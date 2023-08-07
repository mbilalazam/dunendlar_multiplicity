// This script is used to plot the KE of final state particles for different interaction types and interaction modes.
// vector<int> ccnc;             //0: CC; 1: NC
// vector<int> mode;             //0: QE; 1: Resonance; 2: DIS; 3: Coherent pion; 10: MEC
// It also calculates the average multiplicity.


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
void plot_keMode_FS()
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
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");


TTree* tevt = (TTree*)f.Get("evtTree");
TTree* tmcp = (TTree*)f.Get("mcpTree");
TTree* tsed = (TTree*)f.Get("sedTree");

// Energy CC

int numBins = 40; // Number of bins (50 MeV per bin)
double minRange = 0.001; //0.001; // Minimum range in MeV
double maxRange = 2.001; //2.001; // Maximum range in MeV

TH1D *truekeQE_CC = new TH1D("truekeQE_CC", "truekeQE_CC", numBins, minRange, maxRange);
TH1D *truekeRES_CC = new TH1D("truekeRES_CC", "truekeRES_CC", numBins, minRange, maxRange);
TH1D *truekeDIS_CC = new TH1D("truekeDIS_CC", "truekeDIS_CC", numBins, minRange, maxRange);
TH1D *truekeCOH_CC = new TH1D("truekeCOH_CC", "truekeCOH_CC", numBins, minRange, maxRange);
TH1D *truekeMEC_CC = new TH1D("truekeMEC_CC", "truekeMEC_CC", numBins, minRange, maxRange);

THStack *hs_CC = new THStack("hs_CC", "Interaction Types in Observed Multiplicity Bins");
TCanvas c3;
c3.Draw();

// Add these lines to create a TEventList with the desired condition
tevt->Draw(">>eventList_CCQE", "nu_ccnc == 0 && nu_mode == 0", "goff");
TEventList *eventList_CCQE = (TEventList*)gDirectory->Get("eventList_CCQE");

tevt->Draw(">>eventList_CCRES", "nu_ccnc == 0 && nu_mode == 1", "goff");
TEventList *eventList_CCRES = (TEventList*)gDirectory->Get("eventList_CCRES");

tevt->Draw(">>eventList_CCDIS", "nu_ccnc == 0 && nu_mode == 2", "goff");
TEventList *eventList_CCDIS = (TEventList*)gDirectory->Get("eventList_CCDIS");

tevt->Draw(">>eventList_CCCOH", "nu_ccnc == 0 && nu_mode == 3", "goff");
TEventList *eventList_CCCOH = (TEventList*)gDirectory->Get("eventList_CCCOH");

tevt->Draw(">>eventList_CCMEC", "nu_ccnc == 0 && nu_mode == 10", "goff");
TEventList *eventList_CCMEC = (TEventList*)gDirectory->Get("eventList_CCMEC");

// Add these lines to modify the evtTree to only include events satisfying the condition
tmcp->SetBranchStatus("*", 0);
tmcp->SetBranchStatus("_truemcpKE", 1);
tmcp->SetBranchStatus("_truemcppdg", 1);
// tmcp->SetEventList(eventList_CCQE);
// tmcp->SetEventList(eventList_CCRES);
// tmcp->SetEventList(eventList_CCDIS);
// tmcp->SetEventList(eventList_CCCOH);
// tmcp->SetEventList(eventList_CCMEC);

TEventList* eventList_CC = new TEventList();
eventList_CC->Add(eventList_CCQE);
eventList_CC->Add(eventList_CCRES);
eventList_CC->Add(eventList_CCDIS);
eventList_CC->Add(eventList_CCCOH);
eventList_CC->Add(eventList_CCMEC);
tmcp->SetEventList(eventList_CC);


Float_t _truemcpKE;
Int_t _truemcppdg;


tmcp->SetBranchAddress("_truemcpKE", &_truemcpKE);
tmcp->SetBranchAddress("_truemcppdg", &_truemcppdg);


// QE: Loop over the entries and fill histograms
Long64_t numEntries_CCQE = eventList_CC->GetN();
for (Long64_t i = 0; i < numEntries_CCQE; ++i) {
    Long64_t entry_CCQE = eventList_CCQE->GetEntry(i);
    tmcp->GetEntry(entry_CCQE);

    if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112 && _truemcpKE > 0.05) {
    // if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112) {
        truekeQE_CC->Fill(_truemcpKE);
    }
}

// RES
Long64_t numEntries_CCRES = eventList_CC->GetN();
for (Long64_t i = 0; i < numEntries_CCRES; ++i) {
    Long64_t entry_CCRES = eventList_CCRES->GetEntry(i);
    tmcp->GetEntry(entry_CCRES);

    if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112 && _truemcpKE > 0.05) {
    // if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112) {
        truekeRES_CC->Fill(_truemcpKE);
    }
}

// DIS
Long64_t numEntries_CCDIS = eventList_CC->GetN();
for (Long64_t i = 0; i < numEntries_CCDIS; ++i) {
    Long64_t entry_CCDIS = eventList_CCDIS->GetEntry(i);
    tmcp->GetEntry(entry_CCDIS);

    if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112 && _truemcpKE > 0.05) {
    // if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112) {
        truekeDIS_CC->Fill(_truemcpKE);
    }
}

// COH
Long64_t numEntries_CCCOH = eventList_CC->GetN();
for (Long64_t i = 0; i < numEntries_CCCOH; ++i) {
    Long64_t entry_CCCOH = eventList_CCCOH->GetEntry(i);
    tmcp->GetEntry(entry_CCCOH);

    if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112 && _truemcpKE > 0.05) {
    // if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112) {
        truekeCOH_CC->Fill(_truemcpKE);
    }
}

// MEC
Long64_t numEntries_CCMEC = eventList_CC->GetN();
for (Long64_t i = 0; i < numEntries_CCMEC; ++i) {
    Long64_t entry_CCMEC = eventList_CCMEC->GetEntry(i);
    tmcp->GetEntry(entry_CCMEC);

    if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112 && _truemcpKE > 0.05) {
    // if (abs(_truemcppdg) != 13 && abs(_truemcppdg) != 211 && abs(_truemcppdg) != 321 && abs(_truemcppdg) != 111 && abs(_truemcppdg) != 2212 && abs(_truemcppdg) != 2112) {
        truekeMEC_CC->Fill(_truemcpKE);
    }
}


hs_CC->Add(truekeQE_CC);
hs_CC->Add(truekeRES_CC);
hs_CC->Add(truekeDIS_CC);
hs_CC->Add(truekeCOH_CC);
hs_CC->Add(truekeMEC_CC);
truekeQE_CC->SetFillColor(kBlack);
truekeRES_CC->SetFillColor(kRed);
truekeDIS_CC->SetFillColor(kBlue);
truekeCOH_CC->SetFillColor(kGreen);
truekeMEC_CC->SetFillColor(6);
hs_CC->Draw("hist");
hs_CC->SetTitle(" ");
hs_CC->GetXaxis()->SetTitle("Kinetic Energy (GeV)");
hs_CC->GetYaxis()->SetTitle("Number of Final State CC Other Particles");
hs_CC->GetYaxis()->SetRangeUser(0, 500);
TLegend *l3 = new TLegend(0.65, 0.65, 0.95, 0.88);

double totalEvents = truekeQE_CC->Integral() + truekeRES_CC->Integral() + truekeDIS_CC->Integral() + truekeCOH_CC->Integral() + truekeMEC_CC->Integral();

double percentageQE = (truekeQE_CC->Integral() / totalEvents) * 100;
double percentageRES = (truekeRES_CC->Integral() / totalEvents) * 100;
double percentageDIS = (truekeDIS_CC->Integral() / totalEvents) * 100;
double percentageCOH = (truekeCOH_CC->Integral() / totalEvents) * 100;
double percentageMEC = (truekeMEC_CC->Integral() / totalEvents) * 100;

// l3->AddEntry(truekeQE_CC, Form("QE (%.2f%%, %g)", percentageQE, truekeQE_CC->GetEntries()), "F");
// l3->AddEntry(truekeRES_CC, Form("RES (%.2f%%, %g)", percentageRES, truekeRES_CC->GetEntries()), "F");
// l3->AddEntry(truekeDIS_CC, Form("DIS (%.2f%%, %g)", percentageDIS, truekeDIS_CC->GetEntries()), "F");
// l3->AddEntry(truekeCOH_CC, Form("COH (%.2f%%, %g)", percentageCOH, truekeCOH_CC->GetEntries()), "F");
// l3->AddEntry(truekeMEC_CC, Form("MEC (%.2f%%, %g)", percentageMEC, truekeMEC_CC->GetEntries()), "F");

std::cout << "QE: " << percentageQE << " ; " << truekeQE_CC->GetEntries() << std::endl;
std::cout << "RES: " << percentageRES << " ; " << truekeRES_CC->GetEntries() << std::endl;
std::cout << "DIS: " << percentageDIS << " ; " << truekeDIS_CC->GetEntries() << std::endl;
std::cout << "COH: " << percentageCOH << " ; " << truekeCOH_CC->GetEntries() << std::endl;
std::cout << "MEC: " << percentageMEC << " ; " << truekeMEC_CC->GetEntries() << std::endl;

l3->AddEntry(truekeQE_CC,"QE ", "F");
l3->AddEntry(truekeRES_CC, "RES", "F");
l3->AddEntry(truekeDIS_CC, "DIS", "F");
l3->AddEntry(truekeCOH_CC, "COH", "F");
l3->AddEntry(truekeMEC_CC, "MEC", "F");

l3->Draw("SAME");

// c3.Print("FS_allOtherRHC_keModeCC_noCut.png");
c3.Print("FS_allOtherFHC_keModeCC_noCut_cutOn50MeVke.png");
// c3.Print("FS_pi_keModeCC_morethan50MeVke_onAllParticles.png");
// c3.Print("FS_pi_keModeCC_morethan500MeVke_onAllParticles.png");


}
