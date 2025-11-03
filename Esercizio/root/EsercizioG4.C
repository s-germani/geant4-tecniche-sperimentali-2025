////////////////////////////////////////////////////////////////////////
//  Macro ROOT per l'analisi dei risultati  dell'esercizio su Geant4
//    all'interno dle corso di
//    Tecniche Sperimenatli per la Fisica delle Alte Energie
//    (Corso di Laurea Magistrale - Università di Perugia
//
//  (2025) S. Germani - stefano.germani@unipg.it
//
////////////////////////////////////////////////////////////////////////


#include "TFile.h"
#include "TH1D.h"


void EsercizioG4(bool savePlots=false){

  gStyle->SetOptStat(0);

  // Open Inpunt file (copyed and renamed)
  TFile *eg4f = (TFile*) TFile::Open("EsercizioG4_ev10k.root");

  // Get Histograms
  TH1D *hEprm = (TH1D*) eg4f->Get("Eprm");
  TH1D *hEall = (TH1D*) eg4f->Get("Eall");
  TH1D *hLprm = (TH1D*) eg4f->Get("Lprm");
  TH1D *hLall = (TH1D*) eg4f->Get("Lall");

  // Draw Deposited Energy
  TCanvas *ce = new TCanvas("ce");
  hEall->SetTitle(";Edep [MeV];");
  hEall->SetLineColor(kAzure+1);
  hEall->SetFillColor(kAzure+1);
  hEall->SetFillStyle(3001);
  hEall->SetLineWidth(2);
  hEall->Draw("h");

  hEprm->SetTitle(";Edep [MeV];");
  hEprm->SetLineColor(kRed+1);
  hEprm->SetFillColor(kRed+1);
  hEprm->SetFillStyle(3002);
  hEprm->SetLineWidth(2);
  hEprm->Draw("hsame");

  TLegend *lege = new TLegend(0.15, 0.7, 0.5, 0.9);
  lege->AddEntry(hEprm, "Primary Track");
  lege->AddEntry(hEall, "All Tracks");
  lege->SetBorderSize(0);
  lege->SetFillStyle(0);
  lege->Draw();
  //gPad->SetLogy();

  if(savePlots){
    ce->Print("EsercizioG4_Edep.png");
    ce->Print("EsercizioG4_Edep.pdf");
  }


  // Draw Track Length
  TCanvas *cl = new TCanvas("cl");
  hLall->SetTitle(";Track Length [mm];");
  hLall->SetLineColor(kAzure+1);
  hLall->SetFillColor(kAzure+1);
  hLall->SetFillStyle(3001);
  hLall->SetLineWidth(2);
  hLall->Draw("h");

  hLprm->SetTitle(";Track Length [mm];");
  hLprm->SetLineColor(kRed+1);
  hLprm->SetFillColor(kRed+1);
  hLprm->SetFillStyle(3002);
  hLprm->SetLineWidth(2);
  hLprm->Draw("hsame");
  

  TLegend *legl = new TLegend(0.15, 0.7, 0.5, 0.9);
  legl->AddEntry(hLprm, "Primary Track");
  legl->AddEntry(hLall, "All Tracks");
  legl->SetBorderSize(0);
  legl->SetFillStyle(0);
  legl->Draw();
  //gPad->SetLogy();

  if(savePlots){
    cl->Print("EsercizioG4_Tlen.png");
    cl->Print("EsercizioG4_Tlen.pdf");
  }

  

}
