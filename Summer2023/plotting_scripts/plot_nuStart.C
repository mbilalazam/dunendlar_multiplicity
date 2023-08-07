// This script is used to plot different types of incoming neutrinos based on interaction type.
//   vector<int> ccnc;             //0: CC; 1: NC

#include "TH1.h"
#include "TGraph.h"
#include "TH2.h"
#include "TF1.h"
#include "TROOT.h"
#include "THStack.h"
#include "TStyle.h"
#include "TMath.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TGraphErrors.h"
#include "TVectorD.h"
#include "TTimeStamp.h"
#include <fstream>
#include "TMinuit.h"
#include "TString.h"
#include <vector>
#include <string.h>
#include "TLatex.h"
#include "TPaveStats.h"
#include "TDatime.h"
#include "TColor.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TH2F.h"
				  
#include "TLatex.h"
#include "TPaveText.h"

void plot_nuStart()
{

gROOT->LoadMacro("protoDUNEStyle.C");
gROOT->SetStyle("protoDUNEStyle");
gROOT->ForceStyle();
gStyle->SetTitleX(0.35);
gStyle->SetOptFit(111);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadLeftMargin(0.15);
gStyle->SetOptTitle(2);  //no title
gStyle->SetOptStat("emr");  ////stats box
gStyle->SetStatY(0.9);  //// Set y-position (fraction of pad size)
gStyle->SetStatX(0.9);  //// Set x-position (fraction of pad size)
gStyle->SetStatW(0.2);  //// Set width of stat-box (fraction of pad size)
gStyle->SetStatH(0.2);  //// Set height of stat-box (fraction of pad size)
gStyle->SetTextFont(42);
gStyle->SetTextSize(0.05);
gStyle->SetStatFontSize(0.05);
  
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth_0p05GeVke.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/within_acceptance/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/within_acceptance/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


////////// --------------------------------------------------------------- //////////

// // // CC Neutrinos

TH1D *histStartMuNuCC=new TH1D("histStartMuNuCC","histStartMuNuCC",10,1,11);
TH1D *histStartENuCC=new TH1D("histStartENuCC","histStartENuCC",10,1,11);
TH1D *histStartMuNuBarCC=new TH1D("histStartMuNuBarCC","histStartMuNuBarCC",10,1,11);
TH1D *histStartENuBarCC=new TH1D("histStartENuBarCC","histStartENuBarCC",10,1,11);


TCanvas c1("c1", "c1", 800, 600); 
c1.Draw();
tevt->Project("histStartMuNuCC","_startmultmunu","nu_ccnc == 0");
tevt->Project("histStartENuCC","_startmultenu","nu_ccnc == 0");
tevt->Project("histStartMuNuBarCC","_startmultmunubar","nu_ccnc == 0");
tevt->Project("histStartENuBarCC","_startmultenubar","nu_ccnc == 0");

histStartMuNuCC->SetTitle(" ");
histStartMuNuCC->GetXaxis()->SetTitle("Multiplicity");
histStartMuNuCC->GetYaxis()->SetTitle("Number of CC Particles");
histStartMuNuCC->GetYaxis()->SetTitleOffset(1.2);
histStartMuNuCC->SetLineColor(kRed);
histStartMuNuCC->SetLineStyle(1);
histStartENuCC->SetLineColor(kBlue);
histStartENuCC->SetLineStyle(1);
histStartMuNuBarCC->SetLineColor(kRed);
histStartMuNuBarCC->SetLineStyle(2);
histStartENuBarCC->SetLineColor(kBlue);
histStartENuBarCC->SetLineStyle(2);

TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
l1->AddEntry(histStartMuNuCC,"Muon Neutrino ","l");  
l1->AddEntry(histStartENuCC,"Electron Neutrino","l");
l1->AddEntry(histStartMuNuBarCC,"Muon Antineutrino ","l");
l1->AddEntry(histStartENuBarCC,"Electron Antineutrino ","l");

histStartMuNuCC->Draw("HIST");
histStartENuCC->Draw("SAME HIST");
histStartMuNuBarCC->Draw("HIST SAME");
histStartENuBarCC->Draw("HIST SAME");

l1->Draw("SAME");
c1.Print("start_NuCC_0p05GeVke.png");



// int nMuNu_CC = tevt->GetEntries("nu_ccnc == 0 && nu_PDG == 14");
// std::cout << "MuNu_CC: " << nMuNu_CC << std::endl;

// histStartMuNuCC->Draw("HIST");
// c1.Print("start_MuNuCC_0p05GeVke.png");


////////// --------------------------------------------------------------- //////////

// // // NC Neutrinos


TH1D *histStartMuNuNC=new TH1D("histStartMuNuNC","histStartMuNuNC",10,1,11);
TH1D *histStartENuNC=new TH1D("histStartENuNC","histStartENuNC",10,1,11);
TH1D *histStartMuNuBarNC=new TH1D("histStartMuNuBarNC","histStartMuNuBarNC",10,1,11);
TH1D *histStartENuBarNC=new TH1D("histStartENuBarNC","histStartENuBarNC",10,1,11);


TCanvas c2("c2", "c2", 800, 600); 
c2.Draw();
tevt->Project("histStartMuNuNC","_startmultmunu","nu_ccnc == 1");
tevt->Project("histStartENuNC","_startmultenu","nu_ccnc == 1");
tevt->Project("histStartMuNuBarNC","_startmultmunubar","nu_ccnc == 1");
tevt->Project("histStartENuBarNC","_startmultenubar","nu_ccnc == 1");

histStartMuNuNC->SetTitle(" ");
histStartMuNuNC->GetXaxis()->SetTitle("Multiplicity");
histStartMuNuNC->GetYaxis()->SetTitle("Number of NC Particles");
histStartMuNuNC->GetYaxis()->SetTitleOffset(1.2);
histStartMuNuNC->SetLineColor(kRed);
histStartMuNuNC->SetLineStyle(1);
histStartENuNC->SetLineColor(kBlue);
histStartENuNC->SetLineStyle(1);
histStartMuNuBarNC->SetLineColor(kRed);
histStartMuNuBarNC->SetLineStyle(2);
histStartENuBarNC->SetLineColor(kBlue);
histStartENuBarNC->SetLineStyle(2);

TLegend *l2 = new TLegend(0.4,0.65,0.80,0.88);
l2->AddEntry(histStartMuNuNC,"Muon Neutrino ","l");  
l2->AddEntry(histStartENuNC,"Electron Neutrino","l");
l2->AddEntry(histStartMuNuBarNC,"Muon Antineutrino ","l");
l2->AddEntry(histStartENuBarNC,"Electron Antineutrino ","l");

histStartMuNuNC->Draw("HIST");
histStartENuNC->Draw("SAME HIST");
histStartMuNuBarNC->Draw("HIST SAME");
histStartENuBarNC->Draw("HIST SAME");

l2->Draw("SAME");
c2.Print("start_NuNC_0p05GeVke.png");

}
