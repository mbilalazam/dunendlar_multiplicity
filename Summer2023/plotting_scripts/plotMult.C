// This script is used to plot the total multiplicity for different interaction types. 
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
void plotMult()
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


// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth.root");

  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/within_acceptance/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/within_acceptance/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/noNeutron/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/within_acceptance/noNeutron/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/noNeutron/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/within_acceptance/noNeutron/TrackMult2x2wTruth.root");



TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


// // // True Multiplicity

TH1D *truemult=new TH1D("truemult","truemult",10,1,11);

TCanvas c1=TCanvas();
c1.Draw();
tevt->Project("truemult","_truemult");

double sumMultiplicity = 0;
int numEvents = truemult->GetEntries();

for (int i = 0; i < truemult->GetNbinsX(); i++) {
    int binContent = truemult->GetBinContent(i + 1);
    sumMultiplicity += (i * binContent);
}

double averageMultiplicity = sumMultiplicity / numEvents;
cout << "Average Multiplicity: " << averageMultiplicity << endl;

truemult->SetTitle(" ");
truemult->GetXaxis()->SetTitle("True Multiplicity");
truemult->GetYaxis()->SetTitle("Number of Events");
// truemult->GetYaxis()->SetRangeUser(0, 3300);
double maxY = 1.5 * truemult->GetMaximum();
truemult->GetYaxis()->SetRangeUser(0, maxY);
truemult->GetYaxis()->SetTitleOffset(1.2);
truemult->SetLineColor(kBlack);
truemult->SetLineStyle(1);

// TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
// l1->AddEntry(truemult,"all ","l");  

truemult->Draw("HIST");
// l1->Draw("SAME");
c1.Print("mult.png");

////////// --------------------------------------------------------------- //////////

// // // True Multiplicity CC 

TH1D *truemult_CC=new TH1D("truemult_CC","truemult_CC",10,1,11);

TCanvas c7=TCanvas();
c7.Draw();
tevt->Project("truemult_CC","_truemult","nu_ccnc == 0");

double sumMultiplicity_CC = 0;
int numEvents_CC = truemult_CC->GetEntries(); 

for (int i = 0; i < truemult_CC->GetNbinsX(); i++) {
    int binContent_CC = truemult_CC->GetBinContent(i + 1);
    sumMultiplicity_CC += (i * binContent_CC);
}

double averageMultiplicity_CC = sumMultiplicity_CC / numEvents_CC;
cout << "Average Multiplicity for CC: " << averageMultiplicity_CC << endl;

truemult_CC->SetTitle(" ");
truemult_CC->GetXaxis()->SetTitle("True Multiplicity CC");
truemult_CC->GetYaxis()->SetTitle("Number of Events");
// truemult_CC->GetYaxis()->SetRangeUser(0, 3300);
double maxY_CC = 1.5 * truemult_CC->GetMaximum();
truemult_CC->GetYaxis()->SetRangeUser(0, maxY_CC);
truemult_CC->GetYaxis()->SetTitleOffset(1.2);
truemult_CC->SetLineColor(kBlack);
truemult_CC->SetLineStyle(1);

truemult_CC->Draw("HIST");
c7.Print("mult_CC.png");

////////// --------------------------------------------------------------- //////////

// // // True Multiplicity NC

TH1D *truemult_NC=new TH1D("truemult_NC","truemult_NC",10,1,11);

TCanvas c6=TCanvas();
c6.Draw();
tevt->Project("truemult_NC","_truemult","nu_ccnc == 1");

double sumMultiplicity_NC = 0;
int numEvents_NC = truemult_NC->GetEntries();

for (int i = 0; i < truemult_NC->GetNbinsX(); i++) {
    int binContent_NC = truemult_NC->GetBinContent(i + 1);
    sumMultiplicity_NC += (i * binContent_NC);
}

double averageMultiplicity_NC = sumMultiplicity_NC / numEvents_NC;
cout << "Average Multiplicity for NC: " << averageMultiplicity_NC << endl;

truemult_NC->SetTitle(" ");
truemult_NC->GetXaxis()->SetTitle("True Multiplicity NC");
truemult_NC->GetYaxis()->SetTitle("Number of Events");
// truemult_NC->GetYaxis()->SetRangeUser(0, 3300);
double maxY_NC = 1.5 * truemult_NC->GetMaximum();
truemult_NC->GetYaxis()->SetRangeUser(0, maxY_NC);
truemult_NC->GetYaxis()->SetTitleOffset(1.2);
truemult_NC->SetLineColor(kBlack);
truemult_NC->SetLineStyle(1);

truemult_NC->Draw("HIST");
c6.Print("mult_NC.png");

////////// --------------------------------------------------------------- //////////


}
