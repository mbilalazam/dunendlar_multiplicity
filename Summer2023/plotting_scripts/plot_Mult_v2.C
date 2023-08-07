// This script is used to plot the total multiplicity for conditions from different trees.

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

void plot_Mult_v2()
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

TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");
  
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth_morethan50MeVke.root");


TTree* tevt = (TTree*)f.Get("evtTree");
TTree* tmcp = (TTree*)f.Get("mcpTree");
TTree* tsed = (TTree*)f.Get("sedTree");

////////// --------------------------------------------------------------- //////////

// CC Multiplicity

int numBins = 10; // Number of bins
double minRange = 1; // Minimum range
double maxRange = 11; // Maximum range

TH1D *truemult_CC = new TH1D("truemult_CC", "truemult_CC", numBins, minRange, maxRange);

TCanvas c1("c1", "CC Multiplicity", 800, 600);

Float_t _truemcpKE;
Int_t _truemcppdg;
Int_t nu_mode;
Int_t nu_ccnc;
Float_t nu_energy;
Int_t _truemult;

tmcp->SetBranchAddress("_truemcpKE", &_truemcpKE);
tmcp->SetBranchAddress("_truemcppdg", &_truemcppdg);
tevt->SetBranchAddress("nu_mode", &nu_mode);
tevt->SetBranchAddress("nu_ccnc", &nu_ccnc);
tevt->SetBranchAddress("nu_energy", &nu_energy);
tevt->SetBranchAddress("_truemult", &_truemult);

// Loop over the entries and fill histograms
Long64_t numEntries = tevt->GetEntries();
for (Long64_t i = 0; i < numEntries; ++i) {
    tevt->GetEntry(i);
    tmcp->GetEntry(i);

    // Apply the selection criteria
    // if (nu_ccnc == 0)
    if (_truemcpKE >= 0.05 && nu_ccnc == 0)
        truemult_CC->Fill(_truemult);
}

truemult_CC->SetTitle("CC Multiplicity");
truemult_CC->GetXaxis()->SetTitle("True Multiplicity");
truemult_CC->GetYaxis()->SetTitle("Number of CC Events");

double maxY = 1.5 * truemult_CC->GetMaximum();
truemult_CC->GetYaxis()->SetRangeUser(0, maxY);
truemult_CC->GetYaxis()->SetTitleOffset(1.2);
truemult_CC->SetLineColor(kBlack);
truemult_CC->SetLineStyle(1);

c1.cd();
truemult_CC->Draw();

c1.Update();
c1.Print("mult_CC_cutOn50MeVke_rhc.png");



////////// --------------------------------------------------------------- //////////


}
