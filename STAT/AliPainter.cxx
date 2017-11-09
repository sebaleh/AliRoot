/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

#include "AliPainter.h"
#include <iostream>
#include "TPad.h"
#include "TList.h"
#include "TAxis.h"

#include "TMultiGraph.h"
#include "TGraph.h"
///
/// \param pad           - input pad to divide
/// \param division      - division string
///                         <NULL,vertical,horizontal>[div0,div1, ...]
///                            divi - specify number of pads in row (resp. column)
///                                 - sharing parameter for axis
///                                 - btlr  (bottom,lefttop,right)
///                                 - set margin0 in case specified
///                                 - technically attribute can be added to the object name  axis-sharing=""
///                            classID
/*!
   ///TODO add some example
  TCanvas * canvasQA = new TCanvas("canvasQA","canvasQA", 1200,800);
  AliDrawStyle::DivideTPad(canvasQA,"1,1,2");
     AliExternalInfo info("","",0);
     tree = info.GetTree("QA.TPC","LHC15o","pass1")
    canvasQA->cd(1);
    TStatToolkit::DrawMultiGraph(TStatToolkit::MakeMultGraph(tree,"", "meanMIP:run","1","25", "1",1,1,5,0),"ap");
     canvasQA->cd(2);
    TStatToolkit::DrawMultiGraph(TStatToolkit::MakeMultGraph(tree,"", "meanMIPele:run","1","25", "1",1,1,5,0),"ap");
    canvasQA->cd(3);
    TStatToolkit::DrawMultiGraph(TStatToolkit::MakeMultGraph(tree,"", "meanMIPele:meanMIP","1","25", "1",0,1,5,0),"ap");

*/
void AliPainter::DivideTPad(TPad*pad, const char *division) {
  // divide pads
  Int_t nPads = 0, nRows = 0;
  TObjArray *padRows = TString(division).Tokenize("[](),");
  nRows = padRows->GetEntries();
  for (Int_t iRow = 0; iRow < nRows; iRow++) {
    Int_t nCols = TString(padRows->At(iRow)->GetName()).Atoi();
    for (Int_t iCol = 0; iCol < nCols; iCol++) {
      pad->cd();
      TPad *newPad = new TPad(Form("pad%d", nPads), Form("pad%d", nPads), iCol / Double_t(nCols),
                              (nRows - iRow - 1) / Double_t(nRows), (iCol + 1) / Double_t(nCols),
                              (nRows - iRow) / Double_t(nRows));
      newPad->Draw();
      nPads++;
      newPad->SetNumber(nPads);
    }
  }
}


///
/// \param graph
/// \param option
void AliPainter::SetMultiGraphTimeAxis(TMultiGraph *graph, TString option){
  TAxis *axis = NULL;
  for (Int_t i=0; i<graph->GetListOfGraphs()->GetEntries(); i++) {
    TGraph *cGraph=(TGraph *) graph->GetListOfGraphs()->At(i);
    if (option.Contains("X")) axis = cGraph->GetXaxis();
    if (option.Contains("Y")) axis = cGraph->GetYaxis();
    if (axis) {
      axis->SetNdivisions(510, kFALSE);
      axis->SetTimeDisplay(1);
      axis->SetTimeFormat("%d/%m");
    }
  }
}

///
/// \param expresion        - histogram draw expression
///                         - syntax
///                           histogramName(<axisRange>)(<projection string>)(operation)(option)
///                             axisRange:
///                                if integer bin range   - TAxis::SetRange(min, max)
///                                if float   user range  - TAxis::SetRangeUser(min,max)
///                                if Expression is empty - do not specify anything
///                             projectionString (i0,i1)
///                                new projection created THn his = hisInput->Projection(i0,i1....)
///                                at minimum one dimension should be specified, maximum 3D
///                             operation
///
/// \param inputArray       - array of input objects
///                         - Object to draw - histogramArray->FindObject(histogramName)
///                         - in case histogramArray is NULL or histogram not found gROOT->FindObject() will be used
/// \param metaData         - array with metadata describing histogram axis
///                         - for example in the trees we optionally keep metadata (array of TNamed ()tag,value) in the array "metaTable"
///                         - in case not specified -"metaTable" obect from the histogramArray used
/// \param keepArray        - array to keep temporary objects
///
/// \return
/*
   Example case:
   TFile::SetCacheFileDir(".");
   TFile * finput = TFile::Open("http://aliqatrkeos.web.cern.ch/aliqatrkeos/performance/alice/data/2015/LHC15o/pass1/LHC15o.pass1.B1.Bin0/performanceHisto.root", "CACHEREAD");
   hisArray = new TObjArray();
   TList *keys = finput->GetListOfKeys();
   for (Int_t iKey = 0; iKey < keys->GetEntries(); iKey++) {
    TObject *o = finput->Get(TString::Format("%s;%d", keys->At(iKey)->GetName(), ((TKey *) keys->At(iKey))->GetCycle()).Data());
    hisArray->AddLast(o);
   }
   AliPainter::DrawHistogram("hisK0DMassQPtTgl()(0,1)()(err)"
 */
TObject* AliPainter::DrawHistogram(char *expression, TObjArray* inputArray, TObjArray *metaData, TObjArray * keepArray){

}