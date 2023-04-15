////////////////////////////////////////////////////////////////////////
// Class:       Multiplicity
// Plugin Type: analyzer (Aleena Rafique)
// File:        Multiplicity_module.cc
//
// Generated at Monday March 13 01:01:00 2023 by Aleena Rafique 
// from  version .
////////////////////////////////////////////////////////////////////////

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "canvas/Utilities/InputTag.h"
#include "canvas/Persistency/Common/FindManyP.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include "art_root_io/TFileService.h"
#include "nusimdata/SimulationBase/MCTruth.h"
#include "nusimdata/SimulationBase/MCParticle.h"
#include "lardataobj/Simulation/SimEnergyDeposit.h"
#include "lardataobj/Simulation/GeneratedParticleInfo.h"
#include "larcore/Geometry/Geometry.h"

#include "TTree.h"
#include "TFile.h"
#include "TGeoManager.h"

#include <vector>
#include <string>

using namespace std;

namespace dunend {
  class Multiplicity;
}

    constexpr int kMaxtruepar = 9000;
    constexpr int kMaxtrueInAccppar = 5000;
    constexpr int kMaxtruelongInAccppar = 5000;

class dunend::Multiplicity : public art::EDAnalyzer {
public:
  explicit Multiplicity(fhicl::ParameterSet const& p);
  // The compiler-generated destructor is fine for non-base
  // classes without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  Multiplicity(Multiplicity const&) = delete;
  Multiplicity(Multiplicity&&) = delete;
  Multiplicity& operator=(Multiplicity const&) = delete;
  Multiplicity& operator=(Multiplicity&&) = delete;

  // Required functions.
  void analyze(art::Event const& e) override;

  // Selected optional functions.
  void beginJob() override;
// Called when job completes to deal with output of stuff from beginJob
     void endJob();

    // Recover information from the start of a run (if processing across runs)
//     void beginRun(const art::Run&);

    /// Clear all fields if this object (not the tracker algorithm data)
    void ClearLocalData();
    
    /// Clear all fields
    void Clear();

     //Function for calculation KE for diffenert particles and ranges
     float T(int pdg, float range);  

float sx=0,sy=0,sz=0;
float smin=0;

  TTree *fDataTreeFinalSel;
  
  int run;
  int subrun;
  int event;
  
    int   _fmctrue_origin; 
    int   _fTrueccnc;
    int   _fTruemode;
    int   _fTrueinttype;
    int   _fTruenupdg;
    float _fTrueenu;
    float _fTrueq2truth;
    float _fTruenuvrtxx;
    float _fTruenuvrtxy;
    float _fTruenuvrtxz;
    int   _ftrueVrtxOutFV;

    int _fNTrueallPart;
    int _ftrueparpdg[kMaxtruepar];
    int _ftrueparStatusCode[kMaxtruepar];
    float _ftrueparTheta[kMaxtruepar];
    float _ftrueparCosTheta[kMaxtruepar];	
    float _ftrueparSinTheta[kMaxtruepar];
    float _ftrueparPhi[kMaxtruepar];
    float _ftrueparCosPhi[kMaxtruepar];
    float _ftrueparSinPhi[kMaxtruepar];    
    float _ftrueparE[kMaxtruepar];
    float _ftrueparMass[kMaxtruepar];
    float _ftrueparKE[kMaxtruepar];
    float _ftrueparEndE[kMaxtruepar];
    float _ftrueparPx[kMaxtruepar];
    float _ftrueparPy[kMaxtruepar];
    float _ftrueparPz[kMaxtruepar];
    float _ftrueparP[kMaxtruepar];
    float _ftrueparStartx[kMaxtruepar];
    float _ftrueparStarty[kMaxtruepar];
    float _ftrueparStartz[kMaxtruepar];
    float _ftrueparEndx[kMaxtruepar];
    float _ftrueparEndy[kMaxtruepar];
    float _ftrueparEndz[kMaxtruepar];

    int _fNtrueInAccpmult;
    int _ftrueInAccppargeantID[kMaxtrueInAccppar];
    int _ftrueInAccpparpdg[kMaxtrueInAccppar];
    int _ftrueInAccpparStatusCode[kMaxtrueInAccppar];
    float _ftrueInAccpparTheta[kMaxtrueInAccppar];
    float _ftrueInAccpparCosTheta[kMaxtrueInAccppar];	
    float _ftrueInAccpparSinTheta[kMaxtrueInAccppar];
    float _ftrueInAccpparPhi[kMaxtrueInAccppar];
    float _ftrueInAccpparCosPhi[kMaxtrueInAccppar];
    float _ftrueInAccpparSinPhi[kMaxtrueInAccppar];    
    float _ftrueInAccpparE[kMaxtrueInAccppar];
    float _ftrueInAccpparMass[kMaxtrueInAccppar];
    float _ftrueInAccpparKE[kMaxtrueInAccppar];
    float _ftrueInAccpparEndE[kMaxtrueInAccppar];
    float _ftrueInAccpparPx[kMaxtrueInAccppar];
    float _ftrueInAccpparPy[kMaxtrueInAccppar];
    float _ftrueInAccpparPz[kMaxtrueInAccppar];
    float _ftrueInAccpparP[kMaxtrueInAccppar];
    float _ftrueInAccpparStartx[kMaxtrueInAccppar];
    float _ftrueInAccpparStarty[kMaxtrueInAccppar];
    float _ftrueInAccpparStartz[kMaxtrueInAccppar];
    float _ftrueInAccpparEndx[kMaxtrueInAccppar];
    float _ftrueInAccpparEndy[kMaxtrueInAccppar];
    float _ftrueInAccpparEndz[kMaxtrueInAccppar];

    int   _fNtrueInAccpmultmu;
    int   _fNtrueInAccpmultpi;
    int   _fNtrueInAccpmultp;
    int   _fNtrueInAccpmultk;

    int _fNtruelongInAccpmult;
    int _ftruelongInAccppargeantID[kMaxtruelongInAccppar];
    int _ftruelongInAccpparpdg[kMaxtruelongInAccppar];
    int _ftruelongInAccpparStatusCode[kMaxtruelongInAccppar];
    float _ftruelongInAccpparTheta[kMaxtruelongInAccppar];
    float _ftruelongInAccpparCosTheta[kMaxtruelongInAccppar];	
    float _ftruelongInAccpparSinTheta[kMaxtruelongInAccppar];
    float _ftruelongInAccpparPhi[kMaxtruelongInAccppar];
    float _ftruelongInAccpparCosPhi[kMaxtruelongInAccppar];
    float _ftruelongInAccpparSinPhi[kMaxtruelongInAccppar];    
    float _ftruelongInAccpparE[kMaxtruelongInAccppar];
    float _ftruelongInAccpparMass[kMaxtruelongInAccppar];
    float _ftruelongInAccpparKE[kMaxtruelongInAccppar];
    float _ftruelongInAccpparEndE[kMaxtruelongInAccppar];
    float _ftruelongInAccpparPx[kMaxtruelongInAccppar];
    float _ftruelongInAccpparPy[kMaxtruelongInAccppar];
    float _ftruelongInAccpparPz[kMaxtruelongInAccppar];
    float _ftruelongInAccpparP[kMaxtruelongInAccppar];
    float _ftruelongInAccpparStartx[kMaxtruelongInAccppar];
    float _ftruelongInAccpparStarty[kMaxtruelongInAccppar];
    float _ftruelongInAccpparStartz[kMaxtruelongInAccppar];
    float _ftruelongInAccpparEndx[kMaxtruelongInAccppar];
    float _ftruelongInAccpparEndy[kMaxtruelongInAccppar];
    float _ftruelongInAccpparEndz[kMaxtruelongInAccppar];
     
private:

  const art::InputTag fGenieGenModuleLabel;
  const art::InputTag fGeantModuleLabel;
  vector<art::InputTag> fSEDModuleLabels;

  // Run information

/*
  // Genie information
  vector<int> nuPDG;            //Neutrino PDG code
  vector<int> ccnc;             //0: CC; 1: NC
  vector<int> mode;             //0: QE; 1: Resonance; 2: DIS; 3: Coherent pion; 10: MEC
  vector<int> inttype;          //interaction type    
  vector<float> enu;            //Neutrino energy (GeV)
  vector<float> Q2;             //Momentum transfer
  vector<float> W;              //Invariant mass of hadronic system
  vector<float> X;              //Bjorken-X
  vector<float> Y;              //Hadronic-y
  vector<int> hitnuc;           //PDG code of struck nucleon
  vector<int> target;           //PDG code of target
  vector<float> nuvtxx;         //neutrino vertex x (cm)
  vector<float> nuvtxy;         //neutrino vertex y (cm)
  vector<float> nuvtxz;         //neutrino vertex z (cm)
  vector<float> nu_dcosx;       //neutrino direction cosine x
  vector<float> nu_dcosy;       //neutrino direction cosine y
  vector<float> nu_dcosz;       //neutrino direction cosine z
  vector<float> lep_mom;        //lepton momentum (GeV)
  vector<float> lep_dcosx;      //lepton direction cosine x
  vector<float> lep_dcosy;      //lepton direction cosine y
  vector<float> lep_dcosz;      //lepton direction cosine z
  vector<float> t0;             //neutrino interaction time

  // Geant4 MCParticle information
  vector<int>    mcp_id;        //g4 track ID
  vector<int>    mcp_mother;    //mother track ID
  vector<int>    mcp_pdg;       //PDG code
  vector<int>    mcp_statuscode; //Status code
  vector<float>  mcp_theta;     //Angle theta
  vector<float>  mcp_costheta;  //Cosine theta
  vector<float>  mcp_sintheta;  //Sine theta
  vector<int>    mcp_nuid;      //GENIE index
  vector<float>  mcp_energy;    //particle energy (GeV)
  vector<float>  mcp_mass;      //Particle mass (GeV/c^2)
  vector<float>  mcp_ke;        //particle Kinetic energy (GeV)
  vector<float>  mcp_endenergy; //perticle end energy (GeV)
  vector<float>  mcp_px;        //particle momentum px (GeV/c)
  vector<float>  mcp_py;        //particle momentum py (GeV/c)
  vector<float>  mcp_pz;        //particle momentum pz (GeV/c)
  vector<float>  mcp_p;         //particle momentum magnitude (GeV/c)
  vector<float>  mcp_startx;    //particle start x (cm)
  vector<float>  mcp_starty;    //particle start y (cm)
  vector<float>  mcp_startz;    //particle start z (cm)
  vector<float>  mcp_endx;      //particle end x (cm)
  vector<float>  mcp_endy;      //particle end y (cm)
  vector<float>  mcp_endz;      //particle end z (cm)
  vector<float>  mcp_phi;       //particle angle phi;
  vector<float>  mcp_cosphi;    //Cosine phi
  vector<float>  mcp_sinphi;    //Sine phi
*/    
  // SimEnergyDeposit (sed) information
  vector<float>  sed_startx;    //Edep start x (cm)
  vector<float>  sed_starty;    //Edep start y (cm)
  vector<float>  sed_startz;    //Edep start z (cm)
  vector<float>  sed_endx;      //Edep end x (cm)
  vector<float>  sed_endy;      //Edep end y (cm)
  vector<float>  sed_endz;      //Edep end z (cm)
  vector<float>  sed_energy;    //energy deposition (MeV)
  vector<int>    sed_id;        //MCParticle index
  vector<int>    sed_pdg;       //PDG code
  vector<string> sed_det;       //Detector name

//  void reset();

};

    //-----------------------------------------------------------------------
    // Destructor
//    dunend::Multiplicity::~Multiplicity() 
//   {
//    }
   //-----------------------------------------------------------------------
   void dunend::Multiplicity::ClearLocalData()
   {
  std::fill(_ftrueparpdg, _ftrueparpdg + sizeof(_ftrueparpdg)/sizeof(_ftrueparpdg[0]), -99999.); 
  std::fill(_ftrueparStatusCode, _ftrueparStatusCode + sizeof(_ftrueparStatusCode)/sizeof(_ftrueparStatusCode[0]), -99999.); 
  std::fill(_ftrueparTheta, _ftrueparTheta + sizeof(_ftrueparTheta)/sizeof(_ftrueparTheta[0]), -99999.); 
  std::fill(_ftrueparCosTheta, _ftrueparCosTheta + sizeof(_ftrueparCosTheta)/sizeof(_ftrueparCosTheta[0]), -99999.); 
  std::fill(_ftrueparSinTheta, _ftrueparSinTheta + sizeof(_ftrueparSinTheta)/sizeof(_ftrueparSinTheta[0]), -99999.); 
  std::fill(_ftrueparPhi, _ftrueparPhi + sizeof(_ftrueparPhi)/sizeof(_ftrueparPhi[0]), -99999.); 
  std::fill(_ftrueparCosPhi, _ftrueparCosPhi + sizeof(_ftrueparCosPhi)/sizeof(_ftrueparCosPhi[0]), -99999.); 
  std::fill(_ftrueparSinPhi, _ftrueparSinPhi + sizeof(_ftrueparSinPhi)/sizeof(_ftrueparSinPhi[0]), -99999.);  
  std::fill(_ftrueparE, _ftrueparE + sizeof(_ftrueparE)/sizeof(_ftrueparE[0]), -99999.); 
  std::fill(_ftrueparMass, _ftrueparMass + sizeof(_ftrueparMass)/sizeof(_ftrueparMass[0]), -99999.); 
  std::fill(_ftrueparKE, _ftrueparKE + sizeof(_ftrueparKE)/sizeof(_ftrueparKE[0]), -99999.); 
  std::fill(_ftrueparEndE, _ftrueparEndE + sizeof(_ftrueparEndE)/sizeof(_ftrueparEndE[0]), -99999.); 
  std::fill(_ftrueparP, _ftrueparP + sizeof(_ftrueparP)/sizeof(_ftrueparP[0]), -99999.); 
  std::fill(_ftrueparPy, _ftrueparPy + sizeof(_ftrueparPy)/sizeof(_ftrueparPy[0]), -99999.); 
  std::fill(_ftrueparPz, _ftrueparPz + sizeof(_ftrueparPz)/sizeof(_ftrueparPz[0]), -99999.); 
  std::fill(_ftrueparP, _ftrueparP + sizeof(_ftrueparP)/sizeof(_ftrueparP[0]), -99999.); 
  std::fill(_ftrueparStartx, _ftrueparStartx + sizeof(_ftrueparStartx)/sizeof(_ftrueparStartx[0]), -99999.); 
  std::fill(_ftrueparStarty, _ftrueparStarty + sizeof(_ftrueparStarty)/sizeof(_ftrueparStarty[0]), -99999.); 
  std::fill(_ftrueparStartz, _ftrueparStartz + sizeof(_ftrueparStartz)/sizeof(_ftrueparStartz[0]), -99999.); 
  std::fill(_ftrueparEndx, _ftrueparEndx + sizeof(_ftrueparEndx)/sizeof(_ftrueparEndx[0]), -99999.); 
  std::fill(_ftrueparEndy, _ftrueparEndy + sizeof(_ftrueparEndy)/sizeof(_ftrueparEndy[0]), -99999.); 
  std::fill(_ftrueparEndz, _ftrueparEndz + sizeof(_ftrueparEndz)/sizeof(_ftrueparEndz[0]), -99999.); 

  std::fill(_ftrueInAccppargeantID, _ftrueInAccppargeantID + sizeof(_ftrueInAccppargeantID)/sizeof(_ftrueInAccppargeantID[0]), -99999.); 
  std::fill(_ftrueInAccpparpdg, _ftrueInAccpparpdg + sizeof(_ftrueInAccpparpdg)/sizeof(_ftrueInAccpparpdg[0]), -99999.); 
  std::fill(_ftrueInAccpparStatusCode, _ftrueInAccpparStatusCode + sizeof(_ftrueInAccpparStatusCode)/sizeof(_ftrueInAccpparStatusCode[0]), -99999.); 
  std::fill(_ftrueInAccpparTheta, _ftrueInAccpparTheta + sizeof(_ftrueInAccpparTheta)/sizeof(_ftrueInAccpparTheta[0]), -99999.); 
  std::fill(_ftrueInAccpparCosTheta, _ftrueInAccpparCosTheta + sizeof(_ftrueInAccpparCosTheta)/sizeof(_ftrueInAccpparCosTheta[0]), -99999.); 
  std::fill(_ftrueInAccpparSinTheta, _ftrueInAccpparSinTheta + sizeof(_ftrueInAccpparSinTheta)/sizeof(_ftrueInAccpparSinTheta[0]), -99999.); 
  std::fill(_ftrueInAccpparPhi, _ftrueInAccpparPhi + sizeof(_ftrueInAccpparPhi)/sizeof(_ftrueInAccpparPhi[0]), -99999.); 
  std::fill(_ftrueInAccpparCosPhi, _ftrueInAccpparCosPhi + sizeof(_ftrueInAccpparCosPhi)/sizeof(_ftrueInAccpparCosPhi[0]), -99999.); 
  std::fill(_ftrueInAccpparSinPhi, _ftrueInAccpparSinPhi + sizeof(_ftrueInAccpparSinPhi)/sizeof(_ftrueInAccpparSinPhi[0]), -99999.);  
  std::fill(_ftrueInAccpparE, _ftrueInAccpparE + sizeof(_ftrueInAccpparE)/sizeof(_ftrueInAccpparE[0]), -99999.); 
  std::fill(_ftrueInAccpparMass, _ftrueInAccpparMass + sizeof(_ftrueInAccpparMass)/sizeof(_ftrueInAccpparMass[0]), -99999.); 
  std::fill(_ftrueInAccpparKE, _ftrueInAccpparKE + sizeof(_ftrueInAccpparKE)/sizeof(_ftrueInAccpparKE[0]), -99999.); 
  std::fill(_ftrueInAccpparEndE, _ftrueInAccpparEndE + sizeof(_ftrueInAccpparEndE)/sizeof(_ftrueInAccpparEndE[0]), -99999.); 
  std::fill(_ftrueInAccpparP, _ftrueInAccpparP + sizeof(_ftrueInAccpparP)/sizeof(_ftrueInAccpparP[0]), -99999.); 
  std::fill(_ftrueInAccpparPy, _ftrueInAccpparPy + sizeof(_ftrueInAccpparPy)/sizeof(_ftrueInAccpparPy[0]), -99999.); 
  std::fill(_ftrueInAccpparPz, _ftrueInAccpparPz + sizeof(_ftrueInAccpparPz)/sizeof(_ftrueInAccpparPz[0]), -99999.); 
  std::fill(_ftrueInAccpparP, _ftrueInAccpparP + sizeof(_ftrueInAccpparP)/sizeof(_ftrueInAccpparP[0]), -99999.); 
  std::fill(_ftrueInAccpparStartx, _ftrueInAccpparStartx + sizeof(_ftrueInAccpparStartx)/sizeof(_ftrueInAccpparStartx[0]), -99999.); 
  std::fill(_ftrueInAccpparStarty, _ftrueInAccpparStarty + sizeof(_ftrueInAccpparStarty)/sizeof(_ftrueInAccpparStarty[0]), -99999.); 
  std::fill(_ftrueInAccpparStartz, _ftrueInAccpparStartz + sizeof(_ftrueInAccpparStartz)/sizeof(_ftrueInAccpparStartz[0]), -99999.); 
  std::fill(_ftrueInAccpparEndx, _ftrueInAccpparEndx + sizeof(_ftrueInAccpparEndx)/sizeof(_ftrueInAccpparEndx[0]), -99999.); 
  std::fill(_ftrueInAccpparEndy, _ftrueInAccpparEndy + sizeof(_ftrueInAccpparEndy)/sizeof(_ftrueInAccpparEndy[0]), -99999.); 
  std::fill(_ftrueInAccpparEndz, _ftrueInAccpparEndz + sizeof(_ftrueInAccpparEndz)/sizeof(_ftrueInAccpparEndz[0]), -99999.); 

  std::fill(_ftruelongInAccppargeantID, _ftruelongInAccppargeantID + sizeof(_ftruelongInAccppargeantID)/sizeof(_ftruelongInAccppargeantID[0]), -99999.); 
  std::fill(_ftruelongInAccpparpdg, _ftruelongInAccpparpdg + sizeof(_ftruelongInAccpparpdg)/sizeof(_ftruelongInAccpparpdg[0]), -99999.); 
  std::fill(_ftruelongInAccpparStatusCode, _ftruelongInAccpparStatusCode + sizeof(_ftruelongInAccpparStatusCode)/sizeof(_ftruelongInAccpparStatusCode[0]), -99999.); 
  std::fill(_ftruelongInAccpparTheta, _ftruelongInAccpparTheta + sizeof(_ftruelongInAccpparTheta)/sizeof(_ftruelongInAccpparTheta[0]), -99999.); 
  std::fill(_ftruelongInAccpparCosTheta, _ftruelongInAccpparCosTheta + sizeof(_ftruelongInAccpparCosTheta)/sizeof(_ftruelongInAccpparCosTheta[0]), -99999.); 
  std::fill(_ftruelongInAccpparSinTheta, _ftruelongInAccpparSinTheta + sizeof(_ftruelongInAccpparSinTheta)/sizeof(_ftruelongInAccpparSinTheta[0]), -99999.); 
  std::fill(_ftruelongInAccpparPhi, _ftruelongInAccpparPhi + sizeof(_ftruelongInAccpparPhi)/sizeof(_ftruelongInAccpparPhi[0]), -99999.); 
  std::fill(_ftruelongInAccpparCosPhi, _ftruelongInAccpparCosPhi + sizeof(_ftruelongInAccpparCosPhi)/sizeof(_ftruelongInAccpparCosPhi[0]), -99999.); 
  std::fill(_ftruelongInAccpparSinPhi, _ftruelongInAccpparSinPhi + sizeof(_ftruelongInAccpparSinPhi)/sizeof(_ftruelongInAccpparSinPhi[0]), -99999.);  
  std::fill(_ftruelongInAccpparE, _ftruelongInAccpparE + sizeof(_ftruelongInAccpparE)/sizeof(_ftruelongInAccpparE[0]), -99999.); 
  std::fill(_ftruelongInAccpparMass, _ftruelongInAccpparMass + sizeof(_ftruelongInAccpparMass)/sizeof(_ftruelongInAccpparMass[0]), -99999.); 
  std::fill(_ftruelongInAccpparKE, _ftruelongInAccpparKE + sizeof(_ftruelongInAccpparKE)/sizeof(_ftruelongInAccpparKE[0]), -99999.); 
  std::fill(_ftruelongInAccpparEndE, _ftruelongInAccpparEndE + sizeof(_ftruelongInAccpparEndE)/sizeof(_ftruelongInAccpparEndE[0]), -99999.); 
  std::fill(_ftruelongInAccpparP, _ftruelongInAccpparP + sizeof(_ftruelongInAccpparP)/sizeof(_ftruelongInAccpparP[0]), -99999.); 
  std::fill(_ftruelongInAccpparPy, _ftruelongInAccpparPy + sizeof(_ftruelongInAccpparPy)/sizeof(_ftruelongInAccpparPy[0]), -99999.); 
  std::fill(_ftruelongInAccpparPz, _ftruelongInAccpparPz + sizeof(_ftruelongInAccpparPz)/sizeof(_ftruelongInAccpparPz[0]), -99999.); 
  std::fill(_ftruelongInAccpparP, _ftruelongInAccpparP + sizeof(_ftruelongInAccpparP)/sizeof(_ftruelongInAccpparP[0]), -99999.); 
  std::fill(_ftruelongInAccpparStartx, _ftruelongInAccpparStartx + sizeof(_ftruelongInAccpparStartx)/sizeof(_ftruelongInAccpparStartx[0]), -99999.); 
  std::fill(_ftruelongInAccpparStarty, _ftruelongInAccpparStarty + sizeof(_ftruelongInAccpparStarty)/sizeof(_ftruelongInAccpparStarty[0]), -99999.); 
  std::fill(_ftruelongInAccpparStartz, _ftruelongInAccpparStartz + sizeof(_ftruelongInAccpparStartz)/sizeof(_ftruelongInAccpparStartz[0]), -99999.); 
  std::fill(_ftruelongInAccpparEndx, _ftruelongInAccpparEndx + sizeof(_ftruelongInAccpparEndx)/sizeof(_ftruelongInAccpparEndx[0]), -99999.); 
  std::fill(_ftruelongInAccpparEndy, _ftruelongInAccpparEndy + sizeof(_ftruelongInAccpparEndy)/sizeof(_ftruelongInAccpparEndy[0]), -99999.); 
  std::fill(_ftruelongInAccpparEndz, _ftruelongInAccpparEndz + sizeof(_ftruelongInAccpparEndz)/sizeof(_ftruelongInAccpparEndz[0]), -99999.); 
}

   //-----------------------------------------------------------------------
   
   void dunend::Multiplicity::beginJob()
   {
    art::ServiceHandle<art::TFileService> tfs;

    fDataTreeFinalSel->Branch("_fTrueccnc",&_fTrueccnc,"_fTrueccnc/I");
    fDataTreeFinalSel->Branch("_fTruemode",&_fTruemode,"_fTruemode/I");
    fDataTreeFinalSel->Branch("_fTrueinttype",&_fTrueinttype,"_fTrueinttype/I");
    fDataTreeFinalSel->Branch("_fTruenupdg",&_fTruenupdg,"_fTruenupdg/I");
    fDataTreeFinalSel->Branch("_fTrueenu",&_fTrueenu,"_fTrueenu/F");
    fDataTreeFinalSel->Branch("_fTrueq2truth",&_fTrueq2truth,"_fTrueq2truth/F");
    fDataTreeFinalSel->Branch("_fTruenuvrtxx",&_fTruenuvrtxx,"_fTruenuvrtxx/F");
    fDataTreeFinalSel->Branch("_fTruenuvrtxy",&_fTruenuvrtxy,"_fTruenuvrtxy/F");
    fDataTreeFinalSel->Branch("_fTruenuvrtxz",&_fTruenuvrtxz,"_fTruenuvrtxz/F");
    fDataTreeFinalSel->Branch("_fmctrue_origin",&_fmctrue_origin,"_fmctrue_origin/I");
    fDataTreeFinalSel->Branch("_ftrueVrtxOutFV",&_ftrueVrtxOutFV,"_ftrueVrtxOutFV/I");

    fDataTreeFinalSel->Branch("_fNTrueallPart",&_fNTrueallPart,"_fNTrueallPart/I");   
    fDataTreeFinalSel->Branch("_ftrueparpdg",&_ftrueparpdg,"_ftrueparpdg[_fNTrueallPart]/I");
    fDataTreeFinalSel->Branch("_ftrueparStatusCode",&_ftrueparStatusCode,"_ftrueparStatusCode[_fNTrueallPart]/I");
    fDataTreeFinalSel->Branch("_ftrueparTheta",&_ftrueparTheta,"_ftrueparTheta[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparCosTheta",&_ftrueparCosTheta,"_ftrueparCosTheta[_fNTrueallPart]/F");	
    fDataTreeFinalSel->Branch("_ftrueparSinTheta",&_ftrueparSinTheta,"_ftrueparSinTheta[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparPhi",&_ftrueparPhi,"_ftrueparPhi[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparCosPhi",&_ftrueparCosPhi,"_ftrueparCosPhi[_fNTrueallPart]/F");    
    fDataTreeFinalSel->Branch("_ftrueparSinPhi",&_ftrueparSinPhi,"_ftrueparSinPhi[_fNTrueallPart]/F");    
    fDataTreeFinalSel->Branch("_ftrueparE",&_ftrueparE,"_ftrueparE[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparMass",&_ftrueparMass,"_ftrueparMass[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparKE",&_ftrueparKE,"_ftrueparKE[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparEndE",&_ftrueparEndE,"_ftrueparEndE[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparPx",&_ftrueparPx,"_ftrueparPx[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparPy",&_ftrueparPy,"_ftrueparPy[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparPz",&_ftrueparPz,"_ftrueparPz[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparP",&_ftrueparP,"_fTrueparP[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparStartx",&_ftrueparStartx,"_ftrueparStartx[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparStarty",&_ftrueparStarty,"_ftrueparStarty[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparStartz",&_ftrueparStartz,"_ftrueparStartz[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparEndx",&_ftrueparEndx,"_ftrueparEndx[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparEndy",&_ftrueparEndy,"_ftrueparEndy[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_ftrueparEndz",&_ftrueparEndz,"_ftrueparEndz[_fNTrueallPart]/F");
    fDataTreeFinalSel->Branch("_fNtrueInAccpmult",&_fNtrueInAccpmult,"_fNtrueInAccpmult/I");
    fDataTreeFinalSel->Branch("_ftrueInAccppargeantID",&_ftrueInAccppargeantID,"_ftrueInAccppargeantID[_fNtrueInAccpmult]/I");
    fDataTreeFinalSel->Branch("_ftrueInAccpparpdg",&_ftrueInAccpparpdg,"_ftrueInAccpparpdg[_fNtrueInAccpmult]/I");
    fDataTreeFinalSel->Branch("_ftrueInAccpparStatusCode",&_ftrueInAccpparStatusCode,"_ftrueInAccpparStatusCode[_fNtrueInAccpmult]/I");
    fDataTreeFinalSel->Branch("_ftrueInAccpparTheta",&_ftrueInAccpparTheta,"_ftrueInAccpparTheta[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparCosTheta",&_ftrueInAccpparCosTheta,"_ftrueInAccpparCosTheta[_fNtrueInAccpmult]/F");	
    fDataTreeFinalSel->Branch("_ftrueInAccpparSinTheta",&_ftrueInAccpparSinTheta,"_ftrueInAccpparSinTheta[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparPhi",&_ftrueInAccpparPhi,"_ftrueInAccpparPhi[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparCosPhi",&_ftrueInAccpparCosPhi,"_ftrueInAccpparCosPhi[_fNtrueInAccpmult]/F");    
    fDataTreeFinalSel->Branch("_ftrueInAccpparSinPhi",&_ftrueInAccpparSinPhi,"_ftrueInAccpparSinPhi[_fNtrueInAccpmult]/F");    
    fDataTreeFinalSel->Branch("_ftrueInAccpparE",&_ftrueInAccpparE,"_ftrueInAccpparE[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparMass",&_ftrueInAccpparMass,"_ftrueInAccpparMass[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparKE",&_ftrueInAccpparKE,"_ftrueInAccpparKE[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparEndE",&_ftrueInAccpparEndE,"_ftrueInAccpparEndE[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparPx",&_ftrueInAccpparPx,"_ftrueInAccpparPx[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparPy",&_ftrueInAccpparPy,"_ftrueInAccpparPy[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparPz",&_ftrueInAccpparPz,"_ftrueInAccpparPz[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparP",&_ftrueInAccpparP,"_fTrueInAccpparP[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparStartx",&_ftrueInAccpparStartx,"_ftrueInAccpparStartx[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparStarty",&_ftrueInAccpparStarty,"_ftrueInAccpparStarty[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparStartz",&_ftrueInAccpparStartz,"_ftrueInAccpparStartz[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparEndx",&_ftrueInAccpparEndx,"_ftrueInAccpparEndx[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparEndy",&_ftrueInAccpparEndy,"_ftrueInAccpparEndy[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftrueInAccpparEndz",&_ftrueInAccpparEndz,"_ftrueInAccpparEndz[_fNtrueInAccpmult]/F");
    fDataTreeFinalSel->Branch("_fNtrueInAccpmultmu",&_fNtrueInAccpmultmu,"_fNtrueInAccpmultmu/I");
    fDataTreeFinalSel->Branch("_fNtrueInAccpmultpi",&_fNtrueInAccpmultpi,"_fNtrueInAccpmultpi/I");
    fDataTreeFinalSel->Branch("_fNtrueInAccpmultp",&_fNtrueInAccpmultp,"_fNtrueInAccpmultp/I");
    fDataTreeFinalSel->Branch("_fNtrueInAccpmultk",&_fNtrueInAccpmultk,"_fNtrueInAccpmultk/I");
    fDataTreeFinalSel->Branch("_fNtruelongInAccpmult",&_fNtruelongInAccpmult,"_fNtruelongInAccpmult/I");
    fDataTreeFinalSel->Branch("_ftruelongInAccppargeantID",&_ftruelongInAccppargeantID,"_ftruelongInAccppargeantID[_fNtruelongInAccpmult]/I");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparpdg",&_ftruelongInAccpparpdg,"_ftruelongInAccpparpdg[_fNtruelongInAccpmult]/I");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparStatusCode",&_ftruelongInAccpparStatusCode,"_ftruelongInAccpparStatusCode[_fNtruelongInAccpmult]/I");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparTheta",&_ftruelongInAccpparTheta,"_ftruelongInAccpparTheta[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparCosTheta",&_ftruelongInAccpparCosTheta,"_ftruelongInAccpparCosTheta[_fNtruelongInAccpmult]/F");    
    fDataTreeFinalSel->Branch("_ftruelongInAccpparSinTheta",&_ftruelongInAccpparSinTheta,"_ftruelongInAccpparSinTheta[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparPhi",&_ftruelongInAccpparPhi,"_ftruelongInAccpparPhi[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparCosPhi",&_ftruelongInAccpparCosPhi,"_ftruelongInAccpparCosPhi[_fNtruelongInAccpmult]/F");       
    fDataTreeFinalSel->Branch("_ftruelongInAccpparSinPhi",&_ftruelongInAccpparSinPhi,"_ftruelongInAccpparSinPhi[_fNtruelongInAccpmult]/F");    
    fDataTreeFinalSel->Branch("_ftruelongInAccpparE",&_ftruelongInAccpparE,"_ftruelongInAccpparE[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparMass",&_ftruelongInAccpparMass,"_ftruelongInAccpparMass[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparKE",&_ftruelongInAccpparKE,"_ftruelongInAccpparKE[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparEndE",&_ftruelongInAccpparEndE,"_ftruelongInAccpparEndE[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparPx",&_ftruelongInAccpparPx,"_ftruelongInAccpparPx[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparPy",&_ftruelongInAccpparPy,"_ftruelongInAccpparPy[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparPz",&_ftruelongInAccpparPz,"_ftruelongInAccpparPz[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparP",&_ftruelongInAccpparP,"_ftruelongInAccpparP[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparStartx",&_ftruelongInAccpparStartx,"_ftruelongInAccpparStartx[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparStarty",&_ftruelongInAccpparStarty,"_ftruelongInAccpparStarty[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparStartz",&_ftruelongInAccpparStartz,"_ftruelongInAccpparStartz[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparEndx",&_ftruelongInAccpparEndx,"_ftruelongInAccpparEndx[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparEndy",&_ftruelongInAccpparEndy,"_ftruelongInAccpparEndy[_fNtruelongInAccpmult]/F");
    fDataTreeFinalSel->Branch("_ftruelongInAccpparEndz",&_ftruelongInAccpparEndz,"_ftruelongInAccpparEndz[_fNtruelongInAccpmult]/F");
}

   //-----------------------------------------------------------------------
   void dunend::Multiplicity::endJob()
  {

  }
 
   //-----------------------------------------------------------------------
//   void dunend::Multiplicity::beginRun(const art::Run& run)
//  {    
//  }
  //-----------------------------------------------------------------------

dunend::Multiplicity::Multiplicity(fhicl::ParameterSet const& p)
  : EDAnalyzer{p}  ,
  fGenieGenModuleLabel(p.get<art::InputTag>("GenieGenModuleLabel")),
  fGeantModuleLabel(p.get<art::InputTag>("GeantModuleLabel")),
  fSEDModuleLabels(p.get<vector<art::InputTag>>("SEDModuleLabels"))
{
  // Call appropriate consumes<>() for any products to be retrieved by this module.
}

  //----------------------------------------------------------------------
   float dunend::Multiplicity::T(int pdg, float range)
   {
     float ans;
     if(TMath::Abs(pdg)==13)       {ans=(11.518*(TMath::Power(range,0.555))+0.252*(TMath::Power(range,1.289)))/1000;}//converting to GeV 
     else if(TMath::Abs(pdg)==211) {ans=(13.069*(TMath::Power(range,0.555))+0.233*(TMath::Power(range,1.289)))/1000;} 
     else if(pdg==2212)            {ans=(30.573*(TMath::Power(range,0.555))+0.133*(TMath::Power(range,1.289)))/1000;} 
     else if(TMath::Abs(pdg)==321) {ans=(22.966*(TMath::Power(range,0.555))+0.161*(TMath::Power(range,1.289)))/1000;}	 
     else                          {ans=-999;}
    // std::cout<<"KE limiting values: "<<ans<<"\n";
     return ans;
   }	

//-----------------------------------------------------------------------
void dunend::Multiplicity::analyze(art::Event const& e)
{
//  reset();

  run = e.run();
  subrun = e.subRun();
  event = e.id().event();

    const int Xnegbound = -67;
    const int Xposbound = +67;
    const int Ynegbound = -25;
    const int Yposbound = 109;
    const int Znegbound = -67;
    const int Zposbound = +67;

    //vertex bounds
    const int vXnegbound = -62;
    const int vXposbound = +62;
    const int vYnegbound = -20;
    const int vYposbound = 104;
    const int vZnegbound = -62;
    const int vZposbound = +62;

    //long track bounds
    const int longXnegbound = -62;
    const int longXposbound = +62;
    const int longYnegbound = -20;
    const int longYposbound = 104;
    const int longZnegbound = -62;
    const int longZposbound = +62;

    const float lengthnumu = 50.0;
    
  // * MC truth information
  std::vector<art::Ptr<simb::MCTruth> > mclist;
  auto mctruthListHandle = e.getHandle< std::vector<simb::MCTruth> >(fGenieGenModuleLabel);
  if (mctruthListHandle)
    art::fill_ptr_vector(mclist, mctruthListHandle);

  for (auto & MCtruth: mclist){
    if (MCtruth->Origin() == simb::kBeamNeutrino)
    {
/*      nuPDG.push_back(mctruth->GetNeutrino().Nu().PdgCode());
      ccnc.push_back(mctruth->GetNeutrino().CCNC());
      mode.push_back(mctruth->GetNeutrino().Mode());
      inttype.push_back(mctruth->GetNeutrino().InteractionType());
      Q2.push_back(mctruth->GetNeutrino().QSqr());
      W.push_back(mctruth->GetNeutrino().W());
      X.push_back(mctruth->GetNeutrino().X());
      Y.push_back(mctruth->GetNeutrino().Y());
      hitnuc.push_back(mctruth->GetNeutrino().HitNuc());
      target.push_back(mctruth->GetNeutrino().Target());
      enu.push_back(mctruth->GetNeutrino().Nu().E());
      nuvtxx.push_back(mctruth->GetNeutrino().Nu().Vx());
      nuvtxy.push_back(mctruth->GetNeutrino().Nu().Vy());
      nuvtxz.push_back(mctruth->GetNeutrino().Nu().Vz());
*/
      _fmctrue_origin=MCtruth->Origin();
      
      if(MCtruth->NeutrinoSet())
      {
        _fTrueccnc=MCtruth->GetNeutrino().CCNC();
	_fTruemode=MCtruth->GetNeutrino().Mode();
	_fTrueinttype=MCtruth->GetNeutrino().InteractionType();
	_fTruenupdg=MCtruth->GetNeutrino().Nu().PdgCode();
	_fTrueenu=MCtruth->GetNeutrino().Nu().E();
	_fTrueq2truth=MCtruth->GetNeutrino().QSqr();
	_fTruenuvrtxx=MCtruth->GetNeutrino().Nu().Vx();
	_fTruenuvrtxy=MCtruth->GetNeutrino().Nu().Vy();
	_fTruenuvrtxz=MCtruth->GetNeutrino().Nu().Vz();
        
      }
      /////------Checking whether true true vertex is inside its limits or not--------/////////
      int trueVrtxOutFV = 0;
      if(_fTruenuvrtxx < vXnegbound || _fTruenuvrtxx > vXposbound
       ||_fTruenuvrtxy < vYnegbound || _fTruenuvrtxy > vYposbound
       ||_fTruenuvrtxz < vZnegbound || _fTruenuvrtxz > vZposbound)
       {
         trueVrtxOutFV = 1;
       }
       _ftrueVrtxOutFV = trueVrtxOutFV;       

/*      if (mctruth->GetNeutrino().Nu().P()){
        nu_dcosx.push_back(mctruth->GetNeutrino().Nu().Px()/mctruth->GetNeutrino().Nu().P());
        nu_dcosy.push_back(mctruth->GetNeutrino().Nu().Py()/mctruth->GetNeutrino().Nu().P());
        nu_dcosz.push_back(mctruth->GetNeutrino().Nu().Pz()/mctruth->GetNeutrino().Nu().P());
      }
      else{
        nu_dcosx.push_back(-999);
        nu_dcosy.push_back(-999);
        nu_dcosz.push_back(-999);
      }
      lep_mom.push_back(mctruth->GetNeutrino().Lepton().P());
      if (mctruth->GetNeutrino().Lepton().P()){
        lep_dcosx.push_back(mctruth->GetNeutrino().Lepton().Px()/mctruth->GetNeutrino().Lepton().P());
        lep_dcosy.push_back(mctruth->GetNeutrino().Lepton().Py()/mctruth->GetNeutrino().Lepton().P());
        lep_dcosz.push_back(mctruth->GetNeutrino().Lepton().Pz()/mctruth->GetNeutrino().Lepton().P());
      }
      else{
        lep_dcosx.push_back(-999);
        lep_dcosy.push_back(-999);
        lep_dcosz.push_back(-999);
      }
      if (mctruth->NParticles()){
        simb::MCParticle particle = mctruth->GetParticle(0);
        t0.push_back(particle.T());
      }
      else{
        t0.push_back(-999);
      }
*/    }
  }

         size_t ntruepart = 0;
	 size_t trueInAccep = 0;
	 size_t truelongInAccep = 0;

     int TrueInAccplongcontained=0, trueInAccpmult=0, trueInAccpmultmu=0, trueInAccpmultpi=0, trueInAccpmultp=0,trueInAccpmultk=0;
      _fNTrueallPart = 0; //in case of cosmic event    
      _fNtrueInAccpmult = 0; //in case of cosmic event  
      _fNtrueInAccpmultmu = 0; //in case of cosmic event  
      _fNtrueInAccpmultpi = 0; //in case of cosmic event  
      _fNtrueInAccpmultp = 0; //in case of cosmic event  
      _fNtrueInAccpmultk = 0; //in case of cosmic event  
       _fNtruelongInAccpmult = 0; //in case of cosmic event  
  

  // Get Geant4 information

  std::vector<art::Ptr<simb::MCParticle>> mcplist;
  auto mcpListHandle = e.getHandle< std::vector<simb::MCParticle> >(fGeantModuleLabel);
  if (mcpListHandle){
    art::fill_ptr_vector(mcplist, mcpListHandle);
  }
  art::FindManyP<simb::MCTruth,sim::GeneratedParticleInfo> fmth(mcpListHandle, e, fGeantModuleLabel);

  for (auto & part : mcplist){
/*    mcp_id.push_back(mcp->TrackId());
    mcp_mother.push_back(mcp->Mother());
    mcp_pdg.push_back(mcp->PdgCode());
    mcp_statuscode.push_back(mcp->StatusCode());
    mcp_theta.push_back(mcp->Momentum().Theta());
    mcp_costheta.push_back(TMath::Cos(mcp->Momentum().Theta()));	
    mcp_sintheta.push_back(TMath::Sin(mcp->Momentum().Theta()));	
    mcp_energy.push_back(mcp->E());
    mcp_mass.push_back(mcp->Mass());
    mcp_ke.push_back((mcp->E())-(mcp->Mass()));
    mcp_endenergy.push_back(mcp->EndE());
    mcp_px.push_back(mcp->Px());
    mcp_py.push_back(mcp->Py());
    mcp_pz.push_back(mcp->Pz());
    mcp_p.push_back(mcp->Momentum().Vect().Mag());
    mcp_startx.push_back(mcp->Vx());
    mcp_starty.push_back(mcp->Vy());
    mcp_startz.push_back(mcp->Vz());
    mcp_endx.push_back(mcp->EndPosition()[0]);
    mcp_endy.push_back(mcp->EndPosition()[1]);
    mcp_endz.push_back(mcp->EndPosition()[2]);
    mcp_phi.push_back(mcp->Momentum().Phi());
    mcp_cosphi.push_back(TMath::Cos(mcp->Momentum().Phi()));
    mcp_sinphi.push_back(TMath::Sin(mcp->Momentum().Phi()));
*/
	  _ftrueparpdg[ntruepart]=part->PdgCode();
	  _ftrueparStatusCode[ntruepart]=part->StatusCode();
	  _ftrueparTheta[ntruepart]=part->Momentum().Theta();
	  _ftrueparCosTheta[ntruepart]=TMath::Cos(part->Momentum().Theta());	
	  _ftrueparSinTheta[ntruepart]=TMath::Sin(part->Momentum().Theta());	
	  _ftrueparE[ntruepart]=part->E();
	  _ftrueparMass[ntruepart]=part->Mass();
	  _ftrueparKE[ntruepart]=(part->E())-(part->Mass());
	  _ftrueparEndE[ntruepart]=part->EndE();
          _ftrueparPx[ntruepart]=part->Px();
	  _ftrueparPy[ntruepart]=part->Py();
	  _ftrueparPz[ntruepart]=part->Pz();
	  _ftrueparP[ntruepart]=part->Momentum().Vect().Mag();
	  _ftrueparStartx[ntruepart]=part->Vx();
	  _ftrueparStarty[ntruepart]=part->Vy();
	  _ftrueparStartz[ntruepart]=part->Vz();
	  _ftrueparEndx[ntruepart]=part->EndPosition()[0];
	  _ftrueparEndy[ntruepart]=part->EndPosition()[1];
	  _ftrueparEndz[ntruepart]=part->EndPosition()[2];
	  _ftrueparPhi[ntruepart]=part->Momentum().Phi();
	  _ftrueparCosPhi[ntruepart]=TMath::Cos(part->Momentum().Phi());
	  _ftrueparSinPhi[ntruepart]=TMath::Sin(part->Momentum().Phi());
            //---- track acceptance------------// 
//	    if(TMath::Abs(TMath::Cos(part.Momentum().Theta()))>=0.052 && part.StatusCode()==1) 
	    if(part->StatusCode()==1) 
	    {
	    if(Xnegbound<(_fTruenuvrtxx+(4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))*(_ftrueparSinTheta[ntruepart])*(_ftrueparCosPhi[ntruepart])) && Xposbound>(_fTruenuvrtxx+(4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))*(_ftrueparSinTheta[ntruepart])*(_ftrueparCosPhi[ntruepart]))
	    && Ynegbound<(_fTruenuvrtxy+(4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))*(_ftrueparSinTheta[ntruepart])*(_ftrueparSinPhi[ntruepart])) && Yposbound>(_fTruenuvrtxy+(4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))*(_ftrueparSinTheta[ntruepart])*(_ftrueparSinPhi[ntruepart]))
	    && Znegbound<(_fTruenuvrtxz+(4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))*(_ftrueparCosTheta[ntruepart])) && Zposbound>(_fTruenuvrtxz+(4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))*(_ftrueparCosTheta[ntruepart])))
	    {
	      if((TMath::Abs(_ftrueparpdg[ntruepart])==13 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))) 
	      || (TMath::Abs(_ftrueparpdg[ntruepart])==211 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))) 
	      || (_ftrueparpdg[ntruepart]==2212 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))) 
	      || (TMath::Abs(_ftrueparpdg[ntruepart])==321 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],4.5/TMath::Abs(_ftrueparCosTheta[ntruepart]))))
	      {
		trueInAccpmult++;
		if(TMath::Abs(part->PdgCode())==13)trueInAccpmultmu++; 
		if(TMath::Abs(part->PdgCode())==211) trueInAccpmultpi++;
		if(part->PdgCode()==2212) trueInAccpmultp++;
		if(TMath::Abs(part->PdgCode())==321) trueInAccpmultk++;

	        _ftrueInAccppargeantID[trueInAccep]=part->TrackId();
	        _ftrueInAccpparpdg[trueInAccep]=part->PdgCode();
	        _ftrueInAccpparStatusCode[trueInAccep]=part->StatusCode();
	        _ftrueInAccpparTheta[trueInAccep]=part->Momentum().Theta();
	        _ftrueInAccpparCosTheta[trueInAccep]=TMath::Cos(part->Momentum().Theta());	
	        _ftrueInAccpparSinTheta[trueInAccep]=TMath::Sin(part->Momentum().Theta());	
	        _ftrueInAccpparE[trueInAccep]=part->E();
	        _ftrueInAccpparMass[trueInAccep]=part->Mass();
	        _ftrueInAccpparKE[trueInAccep]=(part->E())-(part->Mass());
	        _ftrueInAccpparEndE[trueInAccep]=part->EndE();
                _ftrueInAccpparPx[trueInAccep]=part->Px();
	        _ftrueInAccpparPy[trueInAccep]=part->Py();
	        _ftrueInAccpparPz[trueInAccep]=part->Pz();
	        _ftrueInAccpparP[trueInAccep]=part->Momentum().Vect().Mag();
	        _ftrueInAccpparStartx[trueInAccep]=part->Vx();
	        _ftrueInAccpparStarty[trueInAccep]=part->Vy();
	        _ftrueInAccpparStartz[trueInAccep]=part->Vz();
	        _ftrueInAccpparEndx[trueInAccep]=part->EndPosition()[0];
	        _ftrueInAccpparEndy[trueInAccep]=part->EndPosition()[1];
	        _ftrueInAccpparEndz[trueInAccep]=part->EndPosition()[2];
	        _ftrueInAccpparPhi[trueInAccep]=part->Momentum().Phi();
	        _ftrueInAccpparCosPhi[trueInAccep]=TMath::Cos(part->Momentum().Phi());
	        _ftrueInAccpparSinPhi[trueInAccep]=TMath::Sin(part->Momentum().Phi());
		trueInAccep++;
	      }
	    }
	    
	    if(_ftrueparCosPhi[ntruepart]>=0)    sx = (Xposbound-_fTruenuvrtxx)/(_ftrueparSinTheta[ntruepart]*_ftrueparCosPhi[ntruepart]);
	    if(_ftrueparCosPhi[ntruepart]<0)     sx = (Xnegbound-_fTruenuvrtxx)/(_ftrueparSinTheta[ntruepart]*_ftrueparCosPhi[ntruepart]);
	    if(_ftrueparSinPhi[ntruepart]>=0)    sy = (Yposbound-_fTruenuvrtxy)/(_ftrueparSinTheta[ntruepart]*_ftrueparSinPhi[ntruepart]);
	    if(_ftrueparSinPhi[ntruepart]<0)	 sy = (Ynegbound-_fTruenuvrtxy)/(_ftrueparSinTheta[ntruepart]*_ftrueparSinPhi[ntruepart]);
	    if(_ftrueparCosTheta[ntruepart]>=0)  sz = (Zposbound-_fTruenuvrtxz)/(_ftrueparCosTheta[ntruepart]);
	    if(_ftrueparCosTheta[ntruepart]<0)   sz = (Znegbound-_fTruenuvrtxz)/(_ftrueparCosTheta[ntruepart]);
	    
	    smin = TMath::Min(TMath::Min(sx,sy),sz);
	    //std::cout<<"sx: "<<sx<<" sy: "<<sy<<" sz: "<<sz<<" smin: "<<smin<<endl;
	    	             
	      if((TMath::Abs(_ftrueparpdg[ntruepart])==13 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],TMath::Max(lengthnumu,24/TMath::Abs(_ftrueparCosTheta[ntruepart]))) && _ftrueparKE[ntruepart]<T(_ftrueparpdg[ntruepart],smin)) 
	        || (TMath::Abs(_ftrueparpdg[ntruepart])==211 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],TMath::Max(lengthnumu,24/TMath::Abs(_ftrueparCosTheta[ntruepart]))) && _ftrueparKE[ntruepart]<=T(_ftrueparpdg[ntruepart],smin)) 
	        || (_ftrueparpdg[ntruepart]==2212 &&_ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],TMath::Max(lengthnumu,24/TMath::Abs(_ftrueparCosTheta[ntruepart])))&& _ftrueparKE[ntruepart]<=T(_ftrueparpdg[ntruepart],smin)) 
	        || (TMath::Abs(_ftrueparpdg[ntruepart])==321 && _ftrueparKE[ntruepart]>=T(_ftrueparpdg[ntruepart],TMath::Max(lengthnumu,24/TMath::Abs(_ftrueparCosTheta[ntruepart]))) && _ftrueparKE[ntruepart]<=T(_ftrueparpdg[ntruepart],smin)))
	 	{
		if(_ftrueparStartx[ntruepart]>longXnegbound && _ftrueparEndx[ntruepart]>longXnegbound && _ftrueparStartx[ntruepart]<longXposbound && _ftrueparEndx[ntruepart]<longXposbound
		&& _ftrueparStarty[ntruepart]>longYnegbound && _ftrueparEndy[ntruepart]>longYnegbound && _ftrueparStarty[ntruepart]<longYposbound && _ftrueparEndy[ntruepart]<longYposbound
		&& _ftrueparStartz[ntruepart]>longZnegbound && _ftrueparEndz[ntruepart]>longZnegbound && _ftrueparStartz[ntruepart]<longZposbound && _ftrueparEndz[ntruepart]<longZposbound)
		{
		  TrueInAccplongcontained++;

	        _ftruelongInAccppargeantID[truelongInAccep]=part->TrackId();
	        _ftruelongInAccpparpdg[truelongInAccep]=part->PdgCode();
	        _ftruelongInAccpparStatusCode[truelongInAccep]=part->StatusCode();
	        _ftruelongInAccpparTheta[truelongInAccep]=part->Momentum().Theta();
	        _ftruelongInAccpparCosTheta[truelongInAccep]=TMath::Cos(part->Momentum().Theta());	
	        _ftruelongInAccpparSinTheta[truelongInAccep]=TMath::Sin(part->Momentum().Theta()); 
	        _ftruelongInAccpparE[truelongInAccep]=part->E();
	        _ftruelongInAccpparMass[truelongInAccep]=part->Mass();
	        _ftruelongInAccpparKE[truelongInAccep]=(part->E())-(part->Mass());
	        _ftruelongInAccpparEndE[truelongInAccep]=part->EndE();
                _ftruelongInAccpparPx[truelongInAccep]=part->Px();
	        _ftruelongInAccpparPy[truelongInAccep]=part->Py();
	        _ftruelongInAccpparPz[truelongInAccep]=part->Pz();
	        _ftruelongInAccpparP[truelongInAccep]=part->Momentum().Vect().Mag();
	        _ftruelongInAccpparStartx[truelongInAccep]=part->Vx();
	        _ftruelongInAccpparStarty[truelongInAccep]=part->Vy();
	        _ftruelongInAccpparStartz[truelongInAccep]=part->Vz();
	        _ftruelongInAccpparEndx[truelongInAccep]=part->EndPosition()[0];
	        _ftruelongInAccpparEndy[truelongInAccep]=part->EndPosition()[1];
	        _ftruelongInAccpparEndz[truelongInAccep]=part->EndPosition()[2];
	        _ftruelongInAccpparPhi[truelongInAccep]=part->Momentum().Phi();
	        _ftruelongInAccpparCosPhi[truelongInAccep]=TMath::Cos(part->Momentum().Phi());
	        _ftruelongInAccpparSinPhi[truelongInAccep]=TMath::Sin(part->Momentum().Phi());
		truelongInAccep++;
		} 
		} 
	      }//if(part->StatusCode()==1) 
	     ++ntruepart;
	
//      if (fmth.isValid()){
//      auto vmcth = fmth.at(mcp.key());
      //cout<<vmcth.size()<<endl;
//      if (!vmcth.empty()) mcp_nuid.push_back(vmcth[0].key());
//    }
 }//MC particle loop
         _fNtrueInAccpmult=trueInAccpmult;
	_fNtrueInAccpmultmu=trueInAccpmultmu;
	_fNtrueInAccpmultpi=trueInAccpmultpi;
	_fNtrueInAccpmultp=trueInAccpmultp;
	_fNtrueInAccpmultk=trueInAccpmultk;
	_fNtruelongInAccpmult=TrueInAccplongcontained;


  // Get SimEnergyDeposit information

  for (auto & label : fSEDModuleLabels){
    string det = label.instance().substr(20);
    //cout<<label.instance().substr(20)<<endl;
    std::vector<art::Ptr<sim::SimEnergyDeposit>> sedlist;
    auto sedListHandle = e.getHandle< std::vector<sim::SimEnergyDeposit> >(label);
    if (sedListHandle){
      art::fill_ptr_vector(sedlist, sedListHandle);
    }
    for (auto & sed : sedlist){
      sed_startx.push_back(sed->StartX());
      sed_starty.push_back(sed->StartY());
      sed_startz.push_back(sed->StartZ());
      sed_endx.push_back(sed->EndX());
      sed_endy.push_back(sed->EndY());
      sed_endz.push_back(sed->EndZ());
      sed_energy.push_back(sed->Energy());
      sed_id.push_back(sed->TrackID());
      sed_pdg.push_back(sed->PdgCode());
      sed_det.push_back(det);
    }
  }

  fDataTreeFinalSel->Fill();
  ClearLocalData();
   return;
}

/*
void dunend::Multiplicity::beginJob()
{

  art::ServiceHandle<geo::Geometry> geom;
  TGeoManager *geoman = geom->ROOTGeoManager();
  TFile *f = TFile::Open("geometry.root", "recreate");
  geoman->Write("EDepSimGeometry");
  f->Close();

  art::ServiceHandle<art::TFileService> tfs;
  fTree = tfs->make<TTree>("ndsim","ND simulation tree");
  fTree->Branch("run",&run,"run/I");
  fTree->Branch("subrun",&subrun,"subrun/I");
  fTree->Branch("event",&event,"event/I");

  fTree->Branch("nuPDG", &nuPDG);
  fTree->Branch("ccnc", &ccnc);
  fTree->Branch("mode", &mode);
  fTree->Branch("inttype",&inttype);
  fTree->Branch("enu", &enu);
  fTree->Branch("Q2", &Q2);
  fTree->Branch("W", &W);
  fTree->Branch("X", &X);
  fTree->Branch("Y", &Y);
  fTree->Branch("hitnuc", &hitnuc);
  fTree->Branch("target", &target);
  fTree->Branch("nuvtxx", &nuvtxx);
  fTree->Branch("nuvtxy", &nuvtxy);
  fTree->Branch("nuvtxz", &nuvtxz);
  fTree->Branch("nu_dcosx", &nu_dcosx);
  fTree->Branch("nu_dcosy", &nu_dcosy);
  fTree->Branch("nu_dcosz", &nu_dcosz);
  fTree->Branch("lep_mom", &lep_mom);
  fTree->Branch("lep_dcosx", &lep_dcosx);
  fTree->Branch("lep_dcosy", &lep_dcosy);
  fTree->Branch("lep_dcosz", &lep_dcosz);
  fTree->Branch("t0", &t0);

  fTree->Branch("mcp_id", &mcp_id);
  fTree->Branch("mcp_mother", &mcp_mother);
  fTree->Branch("mcp_pdg", &mcp_pdg);
  fTree->Branch("mcp_statuscode", &mcp_statuscode);
  fTree->Branch("mcp_theta", &mcp_theta);
  fTree->Branch("mcp_costheta", &mcp_costheta);
  fTree->Branch("mcp_sintheta", &mcp_sintheta);
  fTree->Branch("mcp_nuid", &mcp_nuid);
  fTree->Branch("mcp_energy", &mcp_energy);
  fTree->Branch("mcp_mass", &mcp_mass);
  fTree->Branch("mcp_ke", &mcp_ke);
  fTree->Branch("mcp_endenergy", &mcp_endenergy);      
  fTree->Branch("mcp_px", &mcp_px);
  fTree->Branch("mcp_py", &mcp_py);
  fTree->Branch("mcp_pz", &mcp_pz);
  fTree->Branch("mcp_p", &mcp_p);
  fTree->Branch("mcp_startx", &mcp_startx);
  fTree->Branch("mcp_starty", &mcp_starty);
  fTree->Branch("mcp_startz", &mcp_startz);
  fTree->Branch("mcp_endx", &mcp_endx);
  fTree->Branch("mcp_endy", &mcp_endy);
  fTree->Branch("mcp_endz", &mcp_endz);
  fTree->Branch("mcp_phi", &mcp_phi);
  fTree->Branch("mcp_cosphi", &mcp_cosphi);
  fTree->Branch("mcp_sinphi", &mcp_sinphi);

  fTree->Branch("sed_startx", &sed_startx);
  fTree->Branch("sed_starty", &sed_starty);
  fTree->Branch("sed_startz", &sed_startz);
  fTree->Branch("sed_endx", &sed_endx);
  fTree->Branch("sed_endy", &sed_endy);
  fTree->Branch("sed_endz", &sed_endz);
  fTree->Branch("sed_energy", &sed_energy);
  fTree->Branch("sed_id", &sed_id);
  fTree->Branch("sed_pdg", &sed_pdg);
  fTree->Branch("sed_det", &sed_det);
}

void dunend::Multiplicity::reset(){

  run = -1;
  subrun = -1;
  event = -1;
  nuPDG.clear();
  ccnc.clear();
  mode.clear();
  inttype.clear();
  enu.clear();
  Q2.clear();
  W.clear();
  X.clear();
  Y.clear();
  hitnuc.clear();
  target.clear();
  nuvtxx.clear();
  nuvtxy.clear();
  nuvtxz.clear();
  nu_dcosx.clear();
  nu_dcosy.clear();
  nu_dcosz.clear();
  lep_mom.clear();
  lep_dcosx.clear();
  lep_dcosy.clear();
  lep_dcosz.clear();
  t0.clear();
  mcp_id.clear();
  mcp_mother.clear();
  mcp_pdg.clear();
  mcp_nuid.clear();
  mcp_energy.clear();
  mcp_px.clear();
  mcp_py.clear();
  mcp_pz.clear();
  mcp_startx.clear();
  mcp_starty.clear();
  mcp_startz.clear();
  mcp_endx.clear();
  mcp_endy.clear();
  mcp_endz.clear();
  sed_startx.clear();
  sed_starty.clear();
  sed_startz.clear();
  sed_endx.clear();
  sed_endy.clear();
  sed_endz.clear();
  sed_energy.clear();
  sed_id.clear();
  sed_pdg.clear();
  sed_det.clear();
}
*/
DEFINE_ART_MODULE(dunend::Multiplicity)
