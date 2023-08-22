#include <TFile.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TLegend.h>
#include <TProfile.h>
#include <TF1.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include <TStyle.h>
#include <TMath.h>

void plot2D_ke_range_hist() {
    gROOT->LoadMacro("protoDUNEStyle.C");
    gROOT->SetStyle("protoDUNEStyle");
    gROOT->ForceStyle();
    gStyle->SetTitleX(0.35);
    gStyle->SetOptFit(111);
    gStyle->SetPadRightMargin(0.15);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetOptStat("emr");
    gStyle->SetStatY(0.9);
    gStyle->SetStatX(0.9);
    gStyle->SetStatW(0.2);
    gStyle->SetStatH(0.2);
    gStyle->SetOptTitle(2);
    gStyle->SetTextFont(42);
    gStyle->SetTextSize(0.05);
    gStyle->SetStatFontSize(0.03);

    TFile *f = new TFile("/dune/app/users/mazam/working_area/dunendlar_multiplicity/bilal_work/inProgress/one/TrackMult2x2wTruth.root");
    TTree *treeevt = (TTree*)f->Get("evtTree");

    float _truemcpKE;
    int _truemcppdg, nu_ccnc;
    float _truemcpStartx, _truemcpStarty, _truemcpStartz, _truemcpEndx, _truemcpEndy, _truemcpEndz;

    treeevt->SetBranchAddress("_truemcpKE", &_truemcpKE);
    treeevt->SetBranchAddress("_truemcppdg", &_truemcppdg);
    treeevt->SetBranchAddress("nu_ccnc", &nu_ccnc);
    treeevt->SetBranchAddress("_truemcpStartx", &_truemcpStartx);
    treeevt->SetBranchAddress("_truemcpStarty", &_truemcpStarty);
    treeevt->SetBranchAddress("_truemcpStartz", &_truemcpStartz);
    treeevt->SetBranchAddress("_truemcpEndx", &_truemcpEndx);
    treeevt->SetBranchAddress("_truemcpEndy", &_truemcpEndy);
    treeevt->SetBranchAddress("_truemcpEndz", &_truemcpEndz);

    const int Xnegbound = -67;
    const int Xposbound = +67;
    const int Ynegbound = -25;
    const int Yposbound = 109;
    const int Znegbound = -67;
    const int Zposbound = +67;

    const int nBinsX = 100;
    const int nBinsY = 100;

    auto drawHistogramAndProfile = [&](const char* canvasName, const char* histName, const char* profileName, const char* title, const char* pngName, const char* profilePngName, int pdgCode, double xMin, double xMax, double yMin, double yMax) {
        TCanvas *c = new TCanvas(canvasName, title, 800, 600);
        TH2F *hist = new TH2F(histName, title, nBinsX, yMin, yMax, nBinsY, xMin, xMax); // Swapped xMin, xMax with yMin, yMax and vice-versa
	hist->GetYaxis()->SetTitleOffset(1.4); 

		
        std::vector<std::tuple<float, double>> data;

        Long64_t numEntries = treeevt->GetEntries();
        for (Long64_t iEntry = 0; iEntry < numEntries; ++iEntry) {
            treeevt->GetEntry(iEntry);

            if(_truemcpStartx > Xnegbound && _truemcpStartx < Xposbound && _truemcpStarty > Ynegbound && _truemcpStarty < Yposbound && _truemcpStartz > Znegbound && _truemcpStartz < Zposbound) {
                double dx = _truemcpEndx - _truemcpStartx;
                double dy = _truemcpEndy - _truemcpStarty;
                double dz = _truemcpEndz - _truemcpStartz;
                double len_inLAr = TMath::Sqrt(dx * dx + dy * dy + dz * dz);

                if (abs(_truemcppdg) == pdgCode && nu_ccnc == 0) {
					data.push_back(std::make_tuple(_truemcpKE, len_inLAr));
				}			
			}
        }

        // Sort data first by KE and then by len_inLAr
        std::sort(data.begin(), data.end(), [](const auto &a, const auto &b) {
            return std::get<0>(a) < std::get<0>(b) || (std::get<0>(a) == std::get<0>(b) && std::get<1>(a) < std::get<1>(b));
        });

        float prevKE = -1.0f;
        double prevLen_inLAr = -1.0;

        for (const auto &datum : data) {
            float ke = std::get<0>(datum);
            double len_inLAr = std::get<1>(datum);

            if (ke > prevKE && len_inLAr > prevLen_inLAr) {
                hist->Fill(len_inLAr, ke); // Swapped ke with len_inLAr
                prevKE = ke;
                prevLen_inLAr = len_inLAr;
            }
			
			if (len_inLAr > 250) {
				break;  // Terminate the loop when len_inLAr exceeds 250
			}
        }

        c->cd();
        //c->SetLogy();
        hist->Draw("COLZ");
        c->SaveAs(pngName);

        TCanvas *c_profile = new TCanvas(profileName, "Profile Plot", 800, 600);
        TProfile *profile = hist->ProfileX(profileName);
        profile->SetLineColor(kBlack);
        profile->SetMarkerColor(kRed);
        profile->Draw();
        c_profile->SaveAs(profilePngName);

        delete profile;
        delete hist;
        delete c;
        delete c_profile;
    };

    drawHistogramAndProfile("c_muCC", "ke_range_muCC", "profile_muCC", "  ;Range of Muons (cm);Kinetic Energy of Muons (GeV)", "ke_range_muCC_fhc.png", "profile_muCC_fhc.png", 13, 0.0, 0.2, 0.0, 50);
    drawHistogramAndProfile("c_piCC", "ke_range_piCC", "profile_piCC", "  ;Range of Pions (cm);Kinetic Energy of Pions (GeV)", "ke_range_piCC_fhc.png", "profile_piCC_fhc.png", 211, 0.0, 0.2, 0.0, 50);
    drawHistogramAndProfile("c_kCC", "ke_range_kCC", "profile_kCC", "  ;Range of Kaons (cm);Kinetic Energy of Kaons (GeV)", "ke_range_kCC_fhc.png", "profile_kCC_fhc.png", 321, 0.0, 0.25, 0.0, 50);
    drawHistogramAndProfile("c_pCC", "ke_range_pCC", "profile_pCC", "  ;Range of Protons (cm);Kinetic Energy of Protons (GeV)", "ke_range_pCC_fhc.png", "profile_pCC_fhc.png", 2212, 0.0, 0.25, 0.0, 30);
}


