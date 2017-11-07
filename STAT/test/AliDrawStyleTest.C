/// \ingroup STAT/test
/// \brief  test of AliDrawStyleTest macro
/// Example usage
/// Some benchmark of the performance doing parsing in loop
///      stopwatch.Start(); (for i; i<n; i++) doSomething(); formatted(dosomething, stopwatch.Print());
/*!
\code
.L $AliRoot_SRC/STAT/test/AliDrawStyleTest.C+
AliDrawStyleTest();
root.exe -b -q  $AliRoot_SRC/STAT/test/AliDrawStyleTest.C+ | tee AliDrawStyleTest.log
\endcode
*/

//list of using functions
//---
// AliDrawStyle::GetMarkerStyle - 3
// AliDrawStyle::GetPropertyValue - 2
// AliDrawStyle::GetNamedIntegerAt - 8
// AliDrawStyle::GetNamedFloatAt - 8
// AliDrawStyle::IsSelected - 5
// AliDrawStyle::GetProperty - 5
// AliDrawStyle::GetSelector - 1
//---

#include "Rtypes.h"
#include "TMath.h"
#include "AliDrawStyle.h"
#include "Riostream.h"
#include <iostream>
#include "TSystem.h"
#include "TStopwatch.h"

void AliDrawStyleTest_StyleArray();
void AliDrawStyleTest_Attributes();
void AliDrawStyleTest_GetIntValues();
void AliDrawStyleTest_GetFloatValues();
//  void AliDrawStyleTest_CSSReadWrite();
void AliDrawStyleTest_GetProperty();
// void AliDrawStyleTest_TGraphApplyStyle();
// void AliDrawStyleTest_TH1ApplyStyle();
// void AliDrawStyleTest_TF1ApplyStyle();
// void AliDrawStyleTest_TPadApplyStyle();
// void AliDrawStyleTest_TCanvasApplyCssStyle();
// void AliDrawStyleTest_ApplyCssStyle();

void AliDrawStyleTest(){
  AliDrawStyleTest_StyleArray();
  AliDrawStyleTest_Attributes();
  AliDrawStyleTest_GetIntValues();
  AliDrawStyleTest_GetFloatValues();
  //  AliDrawStyleTest_CSSReadWrite();
  AliDrawStyleTest_GetProperty();
  // AliDrawStyleTest_TGraphApplyStyle();
  // AliDrawStyleTest_TH1ApplyStyle();
  // AliDrawStyleTest_TF1ApplyStyle();
  // AliDrawStyleTest_TPadApplyStyle();
  // AliDrawStyleTest_TCanvasApplyCssStyle();
  // AliDrawStyleTest_ApplyCssStyle();
}

/// Test acces to the style indexed array
void AliDrawStyleTest_StyleArray(){
  //
  // Standard ALICE marker/colors arrays
  // TODO - extend it with the test of all line and marker atributes
  Int_t result=0;
  result = AliDrawStyle::GetMarkerStyle("1;2,3;4",0);
  if (result!=1){
    ::Error("AliDrawStyleTest","AliDrawStyle::GetMarkerStyle(\"1;2,3;4\",0)==%d should be 1-FAILED\n",result);
  }else{
     ::Info("AliDrawStyleTest","AliDrawStyle::GetMarkerStyle(\"1;2,3;4\",0)- IsOK");
  }
  result = AliDrawStyle::GetMarkerStyle("1;2,3;4",1);
  if (result!=2){
    ::Error("AliDrawStyleTest","AliDrawStyle::GetMarkerStyle(\"1;2,3;4\",1)==%d should be 2-FAILED\n",result);
  }else{
     ::Info("AliDrawStyleTest","AliDrawStyle::GetMarkerStyle(\"1;2,3;4\",1)- IsOK");
  }
  //
  result = AliDrawStyle::GetMarkerStyle("1;2,3;4",0);
  if (result!=1){
    ::Error("AliDrawStyleTest","AliDrawStyle::GetMarkerStyle(\"1;2,3;4\",0)==%d should be 1-FAILED\n",result);
  }else{
     ::Info("AliDrawStyleTest","AliDrawStyle::GetMarkerStyle(\"1;2,3;4\",0)- IsOK");
  }
  //
}

void AliDrawStyleTest_Attributes(){
  TString input="{\nmarker_style:25,21,22,23; \nmarker_color:1,2,4,5; \n}";
  if ( AliDrawStyle::GetPropertyValue(input,"marker_color").Contains("1,2,4,5")){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetPropertyValue(input,\"marker_color\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetPropertyValue(input,\"marker_color\")- FAILED");
  }
  if ( AliDrawStyle::GetPropertyValue(input,"marker_style").Contains("25,21,22,23")){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetPropertyValue(input,\"marker_style\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetPropertyValue(input,\"marker_style\")- FAILED");
  }
}

/// test GetIntValues
void AliDrawStyleTest_GetIntValues(){
  TString input="{\nmarker_style:25,21,22,23; \nmarker_color:1,2,4,5; \n}";
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_color",0) == 1){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",0)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",0)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_color",1) == 2){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",1)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_color",2) == 4){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",2)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",2)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_color",3) == 5){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",3)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_color\",3)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_style",0) == 25){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",0)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",0)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_style",1) == 21){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",1)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_style",2) == 22){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",1)- FAILED");
  }
  if ( AliDrawStyle::GetNamedIntegerAt(input,"marker_style",3) == 23){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedIntegerAt(input,\"marker_style\",1)- FAILED");
  }
}

///
void AliDrawStyleTest_GetFloatValues(){
  TString input="{\nmarker_style:25,21,22,23; \nmarker_color:1,2,4,5; \n}";
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_color",0) == 1){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",0)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",0)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_color",1) == 2){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",1)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_color",2) == 4){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",2)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",2)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_color",3) == 5){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",3)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_color\",3)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_style",0) == 25){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",0)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",0)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_style",1) == 21){
      ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",1)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_style",2) == 22){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",1)- FAILED");
  }
  if ( AliDrawStyle::GetNamedFloatAt(input,"marker_style",3) == 23){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",1)- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetNamedFloatAt(input,\"marker_style\",1)- FAILED");
  }
}


/// To test  - input CSS file to be read and than written
///          - diff between the files should be 0 except of the formatting
/// TODO test - ignoring commented fields in selector and in the declaration
// void AliDrawStyleTest_CSSReadWrite(){
//
//   if (gSystem->GetFromPipe(TString("[ -f ") + TString("$AliRoot_SRC/STAT/test/alirootTestStyle.css") +  TString(" ] && echo 1 || echo 0")) == "0") {
//     std::cout << "File doesn't exist1" << std::endl;
//     ::Info("AliDrawStyleTest","AliDrawStyleTest_CSSReadWrite()- FAILED");
//     return;
//   }
//   TObjArray *cssArray = AliDrawStyle::ReadCSSFile("$AliRoot_SRC/STAT/test/alirootTestStyle.css",0);
//   if (cssArray == NULL) {
//     std::cout << "null-pointer error" << std::endl;
//     ::Info("AliDrawStyleTest","AliDrawStyleTest_CSSReadWrite()- FAILED");
//     return;
//   }
//   AliDrawStyle::WriteCSSFilecssArray,"$AliRoot_SRC/STAT/test/test.css");
//   TObjArray *cssArrayFromTest = AliDrawStyle::ReadCSSFile("$AliRoot_SRC/STAT/test/test.css",0);
//   //AliDrawStyle::WriteCSSFile
//   //AliDrawStyle::WriteCSSFile
//
//   for (Int_t i = 0; i < cssArray->GetEntriesFast(); i++){
//     if ((TString(cssArray->At(i)->GetName()).ReplaceAll("\n", "") == TString(cssArrayFromTest->At(i)->GetName()).ReplaceAll("\n", "")) && TString(cssArray->At(i)->GetTitle()).ReplaceAll("\n", "") == TString(cssArrayFromTest->At(i)->GetTitle()).ReplaceAll("\n", "")) ::Info("AliDrawStyleTest","AliDrawStyleTest_CSSReadWrite()- ");
//     else ::Info("AliDrawStyleTest","AliDrawStyleTest_CSSReadWrite()- FAILED");
//
//   }
//   gSystem->GetFromPipe("rm -f $AliRoot_SRC/STAT/test/test.css");
//
// }

void  AliDrawStyleTest_GetProperty(){
  AliDrawStyle::SetCssStyle("alirootTestStyle.css",AliDrawStyle::ReadCSSFile("$AliRoot_SRC/STAT/test/alirootTestStyle.css",0));
  if (AliDrawStyle::GetProperty("alirootTestStyle.css","marker_size", "TGraph", "Status", "TPC.QA.dcar_posA_1") == "1,2,3,4"){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"marker_size\", \"TGraph\", \"Status\", \"TPC.QA.dcar_posA_1\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"marker_size\", \"TGraph\", \"Status\", \"TPC.QA.dcar_posA_1\")- FAILED");
  }
  if (AliDrawStyle::GetProperty("alirootTestStyle.css","marker_size", "TF1", "Status", "obj4") == "17,18,19,20"){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"marker_size\", \"TF1\", \"Status\", \"obj4\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"marker_size\", \"TF1\", \"Status\", \"obj4\")- FAILED");
  }
  if (AliDrawStyle::GetProperty("alirootTestStyle.css","line_color", "TGraphErrors", "Warning", "asdasobj56") == "41,42,43,44"){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"line_color\", \"TGraphErrors\", \"Warning\", \"asdasobj56\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"line_color\", \"TGraphErrors\", \"Warning\", \"asdasobj56\")- FAILED");
  }
  if (AliDrawStyle::GetProperty("alirootTestStyle.css","marker_color", "SomeNotExistingClass", "SomeNotExistingStatus", "obj3") == "37,38,39,40"){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"marker_color\", \"SomeNotExistingClass\", \"SomeNotExistingStatus\", \"obj3\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"marker_color\", \"SomeNotExistingClass\", \"SomeNotExistingStatus\", \"obj3\")- FAILED");
  }
  if (AliDrawStyle::GetProperty("alirootTestStyle.css","line_color", "TH1", "Warning", "obj1") == "57,58,59,60"){
    ::Info("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"line_color\", \"TH1\", \"Warning\", \"obj1\")- IsOK");
  }else{
    ::Error("AliDrawStyleTest","AliDrawStyle::GetProperty(\"alirootTestStyle.css\",\"line_color\", \"TH1\", \"Warning\", \"obj1\")- FAILED");
  }

}


//TODO: add generator of objects and check function
//void AliDrawStyleTest_CountObjects(){
  // const Int_t nHis = 10;
  // TH1F *hisArray[nHis];
  // TGraph *grArray[nHis];
  // TF1  *fitArray[nHis];
  // //TGraphErrors *grArray[nHis];
  // //TF1  *fitArray[nHis];
  // TList *oList = new TList();
  //
  // for (Int_t i=0; i<nHis; i++){
  //   hisArray[i] = new TH1F(TString::Format("his%d.classRaw",i).Data(), "histo from a gaussian", 100, -3, 3);
  //   fitArray[i] = new TF1(TString::Format("func%d.classRaw",i).Data(),"",0,3,6);
  //   grArray[i] = new TGraph(10);
  //   oList->AddLast(hisArray[i]);
  //   oList->AddLast(fitArray[i]);
  //   oList->AddLast(grArray[i]);
  // }

//}

// void AliDrawStyleTest_TGraphApplyStyle(){
//
// }
// void AliDrawStyleTest_TH1ApplyStyle(){
//
// }
// void AliDrawStyleTest_TF1ApplyStyle(){
//
// }
// void AliDrawStyleTest_TPadApplyStyle(){
//
// }
// void AliDrawStyleTest_TCanvasApplyCssStyle(){
//
// }
// void AliDrawStyleTest_ApplyCssStyle(){
//
// }
