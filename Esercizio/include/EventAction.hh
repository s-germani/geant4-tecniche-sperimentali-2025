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
/// \file include/EventAction.hh
/// \brief Definition of the EsercizioG4::EventAction class

#ifndef EsercizioG4EventAction_h
#define EsercizioG4EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class G4Event;

namespace EsercizioG4
{

/// Event action class
///
/// It defines data members to hold the energy deposit and track lengths
/// in the detetcor for the Primary Track and for all Tracks:
/// - fEnergyPrm, fEnergyAll, fTrackLPrm, fTrackLAll
/// which are collected step by step via the functions
/// - AddPrmTrk(), AddAllTrk()

class EventAction : public G4UserEventAction
{
  public:
    EventAction() = default;
    ~EventAction() override = default;

    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;

    void AddPrmTrk(G4double de, G4double dl);
    void AddAllTrk(G4double de, G4double dl);

  private:
    G4double fEnergyPrm = 0.;
    G4double fEnergyAll = 0.;
    G4double fTrackLPrm = 0.;
    G4double fTrackLAll = 0.;
};

// inline functions

inline void EventAction::AddPrmTrk(G4double de, G4double dl)
{
  fEnergyPrm += de;
  fTrackLPrm += dl;
}

inline void EventAction::AddAllTrk(G4double de, G4double dl)
{
  fEnergyAll += de;
  fTrackLAll += dl;
}

}  // namespace EsercizioG4
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
