// This script is used to plot the energy of incoming neutrinos. 
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

void plot_EnuStart()
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
  
  TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


////////// --------------------------------------------------------------- //////////

// // // CC Neutrinos Energy

TH1D *histStartEnuCC=new TH1D("histStartEnuCC","histStartEnuCC",10,1,11);

TCanvas c1("c1", "c1", 800, 600); 
c1.Draw();
// tevt->Project("histStartEnuCC","nu_energy","nu_ccnc == 0 || nu_PDG == 12 || nu_PDG == 14 || nu_PDG == 16 ");
tevt->Project("histStartEnuCC","nu_energy","nu_ccnc == 0");

histStartEnuCC->SetTitle(" ");
histStartEnuCC->GetXaxis()->SetTitle("Neutrino Energy (GeV)");
histStartEnuCC->GetYaxis()->SetTitle("Number of CC Particles");
histStartEnuCC->GetYaxis()->SetTitleOffset(1.2);
histStartEnuCC->SetLineColor(kRed);
histStartEnuCC->SetLineStyle(1);

histStartEnuCC->Draw("HIST");

c1.Print("start_EnuCC_0to10MeVke.png");
// c1.Print("start_EnuCC_noCut.png");



// int nMuNu_CC = tevt->GetEntries("nu_ccnc == 0 && nu_PDG == 14");
// std::cout << "MuNu_CC: " << nMuNu_CC << std::endl;

// histStartMuNuCC->Draw("HIST");
// c1.Print("start_MuNuCC_0p05GeVke.png");


////////// --------------------------------------------------------------- //////////


}
