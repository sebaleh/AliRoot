/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
* See cxx source for full Copyright notice                               */

// $Id$

/// \ingroup base
/// \class AliMUONCalibrationData
/// \brief Single entry point to access MUON calibration data.
///
/// For the moment, this class stores pedestals, gains and deadchannels
/// that are fetched from the CDB.
/// 
/// \author Laurent Aphecetche

#ifndef ALIMUONCALIBRATIONDATA_H
#define ALIMUONCALIBRATIONDATA_H

#ifndef ROOT_TObject
#include "TObject.h"
#endif

class AliCDBEntry;
class AliMUONTriggerEfficiencyCells;
class AliMUONTriggerLut;
class AliMUONV1DStore;
class AliMUONV2DStore;
class AliMUONVCalibParam;

class AliMUONCalibrationData : public TObject
{
public:
  /** Constructor.
    * @param runNumber is used as a key to the CDB
    * @param deferredInitialization if kFALSE, all the calibrations are fetched
    * regardless of whether you'll use them or not.
    */
  AliMUONCalibrationData(Int_t runNumber=-1, Bool_t deferredInitialization=kTRUE);
  virtual ~AliMUONCalibrationData();

  /// Get the DeadChannel calibration object for channels within (detElemId,manuId).
  AliMUONVCalibParam* DeadChannels(Int_t detElemId, Int_t manuId) const;
  
  /// Get the Gain calibration object for channels within (detElemId,manuId).
  AliMUONVCalibParam* Gains(Int_t detElemId, Int_t manuId) const;

  /// Get the mask for the global trigger board.
  AliMUONVCalibParam* GlobalTriggerBoardMasks() const;

  /// Get the mask for a given local trigger board.
  AliMUONVCalibParam* LocalTriggerBoardMasks(Int_t localBoardNumber) const;
  
  /// Whether this object is valid or not (might be invalid if fetching from CDB failed).
  Bool_t IsValid() const { return fIsValid; }
  
  /// Get the Pedestal calibration object for channels within (detElemId,manuId).
  AliMUONVCalibParam* Pedestals(Int_t detElemId, Int_t manuId) const;
  
  /// Dump to screen.
  virtual void Print(Option_t* opt="") const;

  /// Get the mask for a given regional trigger board.
  AliMUONVCalibParam* RegionalTriggerBoardMasks(Int_t index) const;

  /// The runnumber used by this object.
  Int_t RunNumber() const { return fRunNumber; }
  
  /// Get the trigger Look Up Table.
  AliMUONTriggerLut* TriggerLut() const;
  
  /// Get the trigger efficiency map
  AliMUONTriggerEfficiencyCells* TriggerEfficiency() const;
  
protected:
  AliMUONCalibrationData(const AliMUONCalibrationData& other);
  AliMUONCalibrationData& operator=(const AliMUONCalibrationData& other);
  
private:
  AliCDBEntry* GetEntry(const char* path) const;
  AliMUONV2DStore* OnDemandGains() const;
  AliMUONV2DStore* OnDemandPedestals() const;
  AliMUONV2DStore* OnDemandDeadChannels() const;
  AliMUONVCalibParam* OnDemandGlobalTriggerBoardMasks() const;
  AliMUONV1DStore* OnDemandRegionalTriggerBoardMasks() const;
  AliMUONV1DStore* OnDemandLocalTriggerBoardMasks() const;
  AliMUONTriggerLut* OnDemandTriggerLut() const;
  AliMUONTriggerEfficiencyCells* OnDemandTriggerEfficiency() const;
  
private:  
  mutable Bool_t fIsValid; // Whether we were able to correctly initialize
  Int_t fRunNumber; // The run number for which we hold calibrations
  mutable AliMUONV2DStore* fGains; //!
  mutable AliMUONV2DStore* fPedestals; //!
  mutable AliMUONV2DStore* fDeadChannels; //!
  mutable AliMUONV1DStore* fLocalTriggerBoardMasks; //!
  mutable AliMUONV1DStore* fRegionalTriggerBoardMasks; //!
  mutable AliMUONVCalibParam* fGlobalTriggerBoardMasks; //!
  mutable AliMUONTriggerLut* fTriggerLut; //!
  mutable AliMUONTriggerEfficiencyCells* fTriggerEfficiency; //!
  
  ClassDef(AliMUONCalibrationData,3) // Storage for all MUON calibration data.
};

#endif
