// This script is used to plot 2D histogram for MCP KE and MCP CosTheta.

#include <TFile.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TLegend.h>

void plot2D_ke_theta() {


gROOT->LoadMacro("protoDUNEStyle.C");
gROOT->SetStyle("protoDUNEStyle");
gROOT->ForceStyle();
gStyle->SetTitleX(0.35);
gStyle->SetOptFit(111);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadLeftMargin(0.15);
gStyle->SetOptStat("emr");  //stats box
gStyle->SetStatY(0.9);  // Set y-position (fraction of pad size)
gStyle->SetStatX(0.9);  // Set x-position (fraction of pad size)
gStyle->SetStatW(0.2);  // Set width of stat-box (fraction of pad size)
gStyle->SetStatH(0.2);  // Set height of stat-box (fraction of pad size)
gStyle->SetOptTitle(2);  //no title
gStyle->SetTextFont(42);
gStyle->SetTextSize(0.05);

    // Open the input file
    // TFile *fin = new TFile("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/TrackMult2x2wTruth.root", "READ");

	TFile *fin = new TFile("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/FHC/noCut/TrackMult2x2wTruth.root");
	// TFile *fin = new TFile("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/RHC/noCut/TrackMult2x2wTruth.root");

    // Access the mcpTree from the input file
    TTree *treemcp = (TTree*)fin->Get("mcpTree");

    // Create variables to hold branch values
    int _truemcppdg;
    int _truemcpStatusCode;
    float _truemcpTheta;
    float _truemcpCosTheta;
    float _truemcpSinTheta;
    float _truemcpPhi;
    float _truemcpCosPhi;
    float _truemcpSinPhi;
    float _truemcpE;
    float _truemcpMass;
    float _truemcpKE;
    float _truemcpEndE;
    float _truemcpPx;
    float _truemcpPy;
    float _truemcpPz;
    float _truemcpP;
    float _truemcpStartx;
    float _truemcpStarty;
    float _truemcpStartz;
    float _truemcpEndx;
    float _truemcpEndy;
    float _truemcpEndz;

	 // Set branch addresses for the variables
	treemcp->SetBranchAddress("_truemcppdg", &_truemcppdg);
	treemcp->SetBranchAddress("_truemcpKE", &_truemcpKE);
	treemcp->SetBranchAddress("_truemcpCosTheta", &_truemcpCosTheta);

	// Create a canvas for the histogram
	TCanvas *canvas = new TCanvas("canvas", "2D Histogram", 800, 600);

	// Create the 2D histogram
	TH2F *histogram = new TH2F("histogram", "2D Histogram", 100, 0, 2, 100, -0.5, 1);
	// TH2F *histogram = new TH2F("histogram", "2D Histogram", 100, 0, 20, 100, -1, 1);

	// Get the number of entries in the tree
	Long64_t numEntries = treemcp->GetEntries();

	// Loop over the entries and fill the histogram
	for (Long64_t iEntry = 0; iEntry < numEntries; ++iEntry)
	{
		// Get the entry from the tree
		treemcp->GetEntry(iEntry);

		// Check if _truemcppdg is equal to 13 or -13
		if (abs(_truemcppdg) == 13)
		{
			// Fill the histogram with the values
			histogram->Fill(_truemcpKE, _truemcpCosTheta);
		}
	}

	// Set the title and axis labels for the histogram
	histogram->SetTitle(" ;Kinetic Energy of Muons (GeV);Cos(theta)");

	// Draw the histogram on the canvas
	histogram->Draw("COLZ");

	// Save the canvas as an image
	canvas->SaveAs("2Dhistogram_ke_CosTheta_noCut_mu.png");
	// canvas->SaveAs("2Dhistogram_ke_theta_noCut_p.png");
	// canvas->SaveAs("2Dhistogram_ke_theta_morethan50MeVke_p.png");

    // Clean up
    delete histogram;
    delete canvas;
    fin->Close();
	
}

