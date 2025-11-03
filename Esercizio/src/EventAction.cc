//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file src/EventAction.cc
/// \brief Implementation of the EsercizioG4::EventAction class

#include "EventAction.hh"

#include "G4AnalysisManager.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include <iomanip>

namespace EsercizioG4
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* /*event*/)
{
  // initialisation per event
  fEnergyPrm = 0.;
  fEnergyAll = 0.;
  fTrackLPrm = 0.;
  fTrackLAll = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // fill histograms
  analysisManager->FillH1(0, fEnergyPrm);
  analysisManager->FillH1(1, fEnergyAll);
  analysisManager->FillH1(2, fTrackLPrm);
  analysisManager->FillH1(3, fTrackLAll);

  // fill ntuple
  analysisManager->FillNtupleDColumn(0, fEnergyPrm);
  analysisManager->FillNtupleDColumn(1, fEnergyAll);
  analysisManager->FillNtupleDColumn(2, fTrackLPrm);
  analysisManager->FillNtupleDColumn(3, fTrackLAll);
  analysisManager->AddNtupleRow();

  // Print per event (modulo n)
  //
  auto eventID = event->GetEventID();
  auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();
  if ((printModulo > 0) && (eventID % printModulo == 0)) {
    G4cout << "   Primary Track: total energy: "       << std::setw(7) << G4BestUnit(fEnergyPrm, "Energy")
           << "            total track length: " << std::setw(7) << G4BestUnit(fTrackLPrm, "Length")
           << G4endl;
    G4cout << "   All Tracks: total energy: " << std::setw(7)  << G4BestUnit(fEnergyAll, "Energy")
	   << "         total track length: " << std::setw(7)  << G4BestUnit(fTrackLAll, "Length") << G4endl;

    G4cout << "--> End of event " << eventID << "\n" << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

}  // namespace EsercizioG4
