// This script is used to plot the KE of final state particles. 

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
void plotMultFS_ke()
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

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth_0p05GeVke.root");  

  
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/within_acceptance/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/within_acceptance/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/noNeutron/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/within_acceptance/noNeutron/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/noNeutron/TrackMult2x2wTruth.root");
// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/within_acceptance/noNeutron/TrackMult2x2wTruth.root");

// TFile f("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/within_acceptance/accp_50MeV/withNeutron/TrackMult2x2wTruth.root");


TTree* tevt=(TTree*)f.Get("evtTree");
TTree* tmcp=(TTree*)f.Get("mcpTree");
TTree* tsed=(TTree*)f.Get("sedTree");


// // // True Multiplicity

// TH1D *trueEnergy=new TH1D("trueEnergy","trueEnergy",10,0,11);
TH1D *trueEnergyp=new TH1D("trueEnergyp","trueEnergyp",10,0,11);
TH1D *trueEnergymu=new TH1D("trueEnergymu","trueEnergymu",10,0,11);
TH1D *trueEnergypi=new TH1D("trueEnergypi","trueEnergypi",10,0,11);
TH1D *trueEnergyk=new TH1D("trueEnergyk","trueEnergyk",10,0,11);


TCanvas c1=TCanvas();
c1.Draw();
// tmcp->Project("trueEnergy","_truemcpKE");
tmcp->Project("trueEnergyp","_truemcpKE","abs(_truemcppdg == 2212)");
tmcp->Project("trueEnergymu","_truemcpKE","abs(_truemcppdg == 14)");
tmcp->Project("trueEnergypi","_truemcpKE","abs(_truemcppdg == 211)");
tmcp->Project("trueEnergyk","_truemcpKE","abs(_truemcppdg == 321)");


// int numEvents = truemult->GetEntries(); // Get the number of events

// double sumMultiplicity = 0.0;
// for (int i = 1; i <= truemult->GetNbinsX(); i++) {
    // double binContent = truemult->GetBinContent(i);
    // sumMultiplicity += binContent;
// }

// double averageMultiplicity = sumMultiplicity / numEvents;
// double averageBins = truemult->GetMean();

// cout << "Average Multiplicity: " << averageMultiplicity << endl;
// cout << "Average of Bin Values: " << averageBins << endl;    // This is the average Multiplicity that is needed.


trueEnergyp->SetTitle(" ");
trueEnergyp->GetXaxis()->SetTitle("Kinetic Energy (GeV)");
trueEnergyp->GetYaxis()->SetTitle("Number of Events");
// double maxY = 1.5 * trueEnergyp->GetMaximum();
trueEnergyp->GetYaxis()->SetRangeUser(0, 6300);
// trueEnergyp->GetYaxis()->SetTitleOffset(1.2);
trueEnergyp->SetLineColor(kBlack);
trueEnergyp->SetLineStyle(1);
// trueEnergy->SetLineColor(kBlack);
// trueEnergy->SetLineStyle(1);
trueEnergymu->SetLineColor(kRed);
trueEnergymu->SetLineStyle(1);
trueEnergypi->SetLineColor(kBlue);
trueEnergypi->SetLineStyle(1);
trueEnergyk->SetLineColor(kGreen);
trueEnergyk->SetLineStyle(1);

TLegend *l1 = new TLegend(0.4,0.65,0.80,0.88);
// l1->AddEntry(trueEnergy,"all ","l");  
l1->AddEntry(trueEnergyp,"protons ","l");
l1->AddEntry(trueEnergymu,"muons ","l");
l1->AddEntry(trueEnergypi,"pions ","l");
l1->AddEntry(trueEnergyk,"kaons ","l");


// trueEnergy->Draw("HIST");
trueEnergyp->Draw("HIST");
trueEnergymu->Draw("HIST SAME");
trueEnergypi->Draw("HIST SAME");
trueEnergyk->Draw("HIST SAME");

l1->Draw("SAME");
c1.Print("ke_FS_0to10MeV.png");
// c1.Print("ke_FS_0p05GeVke.png");
// c1.Print("mult_accp50.png");
// c1.Print("mult_accpManual.png");


////////// --------------------------------------------------------------- //////////


}
