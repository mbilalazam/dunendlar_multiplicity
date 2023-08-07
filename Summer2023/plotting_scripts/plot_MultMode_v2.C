// This script is used to plot the total multiplicity for conditions from different trees for different interaction types and interaction modes.
// vector<int> ccnc;             //0: CC; 1: NC
// vector<int> mode;             //0: QE; 1: Resonance; 2: DIS; 3: Coherent pion; 10: MEC
// It also calculates the total number of enteries and their percentage in each bin.


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

void plot_MultMode_v2()
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

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");
  
TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth_morethan50MeVke.root");


TTree* tevt = (TTree*)f.Get("evtTree");
TTree* tmcp = (TTree*)f.Get("mcpTree");
TTree* tsed = (TTree*)f.Get("sedTree");

////////// --------------------------------------------------------------- //////////

// CC Neutrinos Energy

int numBins = 10; // Number of bins (50 MeV per bin)
double minRange = 1; // Minimum range in MeV
double maxRange = 11; // Maximum range in MeV

TH1D *trueEnuStartQE_CC = new TH1D("trueEnuStartQE_CC", "trueEnuStartQE_CC", numBins, minRange, maxRange);
TH1D *trueEnuStartRES_CC = new TH1D("trueEnuStartRES_CC", "trueEnuStartRES_CC", numBins, minRange, maxRange);
TH1D *trueEnuStartDIS_CC = new TH1D("trueEnuStartDIS_CC", "trueEnuStartDIS_CC", numBins, minRange, maxRange);
TH1D *trueEnuStartCOH_CC = new TH1D("trueEnuStartCOH_CC", "trueEnuStartCOH_CC", numBins, minRange, maxRange);
TH1D *trueEnuStartMEC_CC = new TH1D("trueEnuStartMEC_CC", "trueEnuStartMEC_CC", numBins, minRange, maxRange);

// TH1D *trueEnuStartQE_CC = new TH1D("trueEnuStartQE_CC", "trueEnuStartQE_CC", 10, 1, 11);
// TH1D *trueEnuStartRES_CC = new TH1D("trueEnuStartRES_CC", "trueEnuStartRES_CC", 10, 1, 11);
// TH1D *trueEnuStartDIS_CC = new TH1D("trueEnuStartDIS_CC", "trueEnuStartDIS_CC", 10, 1, 11);
// TH1D *trueEnuStartCOH_CC = new TH1D("trueEnuStartCOH_CC", "trueEnuStartCOH_CC", 10, 1, 11);
// TH1D *trueEnuStartMEC_CC = new TH1D("trueEnuStartMEC_CC", "trueEnuStartMEC_CC", 10, 1, 11);
THStack *hs_CC = new THStack("hs_CC", "Interaction Types in Observed Multiplicity Bins");
TCanvas c3;
c3.Draw();

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
tevt->SetBranchAddress("nu_energy", &nu_energy);
tevt->SetBranchAddress("_truemult", &_truemult);


// Variables for storing branch values
Float_t truemcpKE;
Int_t truemcppdg;

tmcp->SetBranchStatus("*", 0); // Disable all branches
tmcp->SetBranchStatus("_truemcpKE", 1); // Enable only the required branch
tmcp->SetBranchAddress("_truemcpKE", &_truemcpKE);

// Loop over the entries and fill histograms
Long64_t numEntries = tevt->GetEntries();
for (Long64_t i = 0; i < numEntries; ++i) {
    tevt->GetEntry(i);
    tmcp->GetEntry(i);

    // Apply the selection criteria
    if ( _truemcpKE >= 0.05 && nu_mode == 0 && nu_ccnc == 0)
        trueEnuStartQE_CC->Fill(_truemult);
    if ( _truemcpKE >= 0.05 && nu_mode == 1 && nu_ccnc == 0)
        trueEnuStartRES_CC->Fill(_truemult);
    if ( _truemcpKE >= 0.05 && nu_mode == 2 && nu_ccnc == 0)
        trueEnuStartDIS_CC->Fill(_truemult);
    if ( _truemcpKE >= 0.05 && nu_mode == 3 && nu_ccnc == 0)
        trueEnuStartCOH_CC->Fill(_truemult);
    if ( _truemcpKE >= 0.05 && nu_mode == 10 && nu_ccnc == 0)
        trueEnuStartMEC_CC->Fill(_truemult);
}

hs_CC->Add(trueEnuStartQE_CC);
hs_CC->Add(trueEnuStartRES_CC);
hs_CC->Add(trueEnuStartDIS_CC);
hs_CC->Add(trueEnuStartCOH_CC);
hs_CC->Add(trueEnuStartMEC_CC);
trueEnuStartQE_CC->SetFillColor(kBlack);
trueEnuStartRES_CC->SetFillColor(kRed);
trueEnuStartDIS_CC->SetFillColor(kBlue);
trueEnuStartCOH_CC->SetFillColor(kGreen);
trueEnuStartMEC_CC->SetFillColor(6);
hs_CC->Draw("hist");
hs_CC->SetTitle(" ");
hs_CC->GetXaxis()->SetTitle("Multiplicity");
hs_CC->GetYaxis()->SetTitle("Number of CC Events");
hs_CC->GetYaxis()->SetRangeUser(0, 500);
TLegend *l3 = new TLegend(0.65, 0.65, 0.95, 0.88);

double totalEvents = trueEnuStartQE_CC->Integral() + trueEnuStartRES_CC->Integral() + trueEnuStartDIS_CC->Integral() + trueEnuStartCOH_CC->Integral() + trueEnuStartMEC_CC->Integral();

double percentageQE = (trueEnuStartQE_CC->Integral() / totalEvents) * 100;
double percentageRES = (trueEnuStartRES_CC->Integral() / totalEvents) * 100;
double percentageDIS = (trueEnuStartDIS_CC->Integral() / totalEvents) * 100;
double percentageCOH = (trueEnuStartCOH_CC->Integral() / totalEvents) * 100;
double percentageMEC = (trueEnuStartMEC_CC->Integral() / totalEvents) * 100;

l3->AddEntry(trueEnuStartQE_CC, "QE ", "F");
l3->AddEntry(trueEnuStartRES_CC, "RES ", "F");
l3->AddEntry(trueEnuStartDIS_CC, "DIS ", "F");
l3->AddEntry(trueEnuStartCOH_CC, "COH ", "F");
l3->AddEntry(trueEnuStartMEC_CC, "MEC ", "F");

std::cout << "QE: " << percentageQE << " ; " << trueEnuStartQE_CC->GetEntries() << std::endl;
std::cout << "RES: " << percentageRES << " ; " << trueEnuStartRES_CC->GetEntries() << std::endl;
std::cout << "DIS: " << percentageDIS << " ; " << trueEnuStartDIS_CC->GetEntries() << std::endl;
std::cout << "COH: " << percentageCOH << " ; " << trueEnuStartCOH_CC->GetEntries() << std::endl;
std::cout << "MEC: " << percentageMEC << " ; " << trueEnuStartMEC_CC->GetEntries() << std::endl;

// l3->AddEntry(trueEnuStartQE_CC, Form("QE (%.2f%%, %g)", percentageQE, trueEnuStartQE_CC->GetEntries()), "F");
// l3->AddEntry(trueEnuStartRES_CC, Form("RES (%.2f%%, %g)", percentageRES, trueEnuStartRES_CC->GetEntries()), "F");
// l3->AddEntry(trueEnuStartDIS_CC, Form("DIS (%.2f%%, %g)", percentageDIS, trueEnuStartDIS_CC->GetEntries()), "F");
// l3->AddEntry(trueEnuStartCOH_CC, Form("COH (%.2f%%, %g)", percentageCOH, trueEnuStartCOH_CC->GetEntries()), "F");
// l3->AddEntry(trueEnuStartMEC_CC, Form("MEC (%.2f%%, %g)", percentageMEC, trueEnuStartMEC_CC->GetEntries()), "F");

l3->Draw("SAME");

c3.Print("EnuStart_mode_CC_noCut_cutOn50MeVke_fhc.png");
// c3.Print("multMode_CC_noCut_fhc.png");


// c3.Print("EnuStart_mode_CC_noCut_cutOn50MeVke_numbers.png");
// c3.Print("EnuStart_mode_CC_noCut_numbers.png");


////////// --------------------------------------------------------------- //////////


}
