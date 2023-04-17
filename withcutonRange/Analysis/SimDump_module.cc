////////////////////////////////////////////////////////////////////////
// Class:       SimDump
// Plugin Type: analyzer (Unknown Unknown)
// File:        SimDump_module.cc
//
// Generated at Sun Jun 26 15:23:13 2022 by Tingjun Yang using cetskelgen
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
  class SimDump;
}


class dunend::SimDump : public art::EDAnalyzer {
public:
  explicit SimDump(fhicl::ParameterSet const& p);
  // The compiler-generated destructor is fine for non-base
  // classes without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  SimDump(SimDump const&) = delete;
  SimDump(SimDump&&) = delete;
  SimDump& operator=(SimDump const&) = delete;
  SimDump& operator=(SimDump&&) = delete;

  // Required functions.
  void analyze(art::Event const& e) override;

  // Selected optional functions.
  void beginJob() override;

private:

  const art::InputTag fGenieGenModuleLabel;
  const art::InputTag fGeantModuleLabel;
  vector<art::InputTag> fSEDModuleLabels;

  TTree *fTree;
  // Run information
  int run;
  int subrun;
  int event;

  // Genie information
  vector<int> nuPDG;            //Neutrino PDG code
  vector<int> ccnc;             //0: CC; 1: NC
  vector<int> mode;             //0: QE; 1: Resonance; 2: DIS; 3: Coherent pion; 10: MEC
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
  vector<int>    mcp_nuid;      //GENIE index
  vector<float>  mcp_energy;    //particle energy (GeV)
  vector<float>  mcp_px;        //particle momentum px (GeV/c)
  vector<float>  mcp_py;        //particle momentum py (GeV/c)
  vector<float>  mcp_pz;        //particle momentum pz (GeV/c)
  vector<float>  mcp_startx;    //particle start x (cm)
  vector<float>  mcp_starty;    //particle start y (cm)
  vector<float>  mcp_startz;    //particle start z (cm)
  vector<float>  mcp_endx;      //particle end x (cm)
  vector<float>  mcp_endy;      //particle end y (cm)
  vector<float>  mcp_endz;      //particle end z (cm)

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

  void reset();

};


dunend::SimDump::SimDump(fhicl::ParameterSet const& p)
  : EDAnalyzer{p}  ,
  fGenieGenModuleLabel(p.get<art::InputTag>("GenieGenModuleLabel")),
  fGeantModuleLabel(p.get<art::InputTag>("GeantModuleLabel")),
  fSEDModuleLabels(p.get<vector<art::InputTag>>("SEDModuleLabels"))
{
  // Call appropriate consumes<>() for any products to be retrieved by this module.
}

void dunend::SimDump::analyze(art::Event const& e)
{
  reset();

  run = e.run();
  subrun = e.subRun();
  event = e.id().event();

  // * MC truth information
  std::vector<art::Ptr<simb::MCTruth> > mclist;
  auto mctruthListHandle = e.getHandle< std::vector<simb::MCTruth> >(fGenieGenModuleLabel);
  if (mctruthListHandle)
    art::fill_ptr_vector(mclist, mctruthListHandle);

  for (auto & mctruth: mclist){
    if (mctruth->Origin() == simb::kBeamNeutrino){
      nuPDG.push_back(mctruth->GetNeutrino().Nu().PdgCode());
      ccnc.push_back(mctruth->GetNeutrino().CCNC());
      mode.push_back(mctruth->GetNeutrino().Mode());
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
      if (mctruth->GetNeutrino().Nu().P()){
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
    }
  }

  // Get Geant4 information

  std::vector<art::Ptr<simb::MCParticle>> mcplist;
  auto mcpListHandle = e.getHandle< std::vector<simb::MCParticle> >(fGeantModuleLabel);
  if (mcpListHandle){
    art::fill_ptr_vector(mcplist, mcpListHandle);
  }
  art::FindManyP<simb::MCTruth,sim::GeneratedParticleInfo> fmth(mcpListHandle, e, fGeantModuleLabel);

  for (auto & mcp : mcplist){
    mcp_id.push_back(mcp->TrackId());
    mcp_mother.push_back(mcp->Mother());
    mcp_pdg.push_back(mcp->PdgCode());
    mcp_energy.push_back(mcp->E());
    mcp_px.push_back(mcp->Px());
    mcp_py.push_back(mcp->Py());
    mcp_pz.push_back(mcp->Pz());
    mcp_startx.push_back(mcp->Vx());
    mcp_starty.push_back(mcp->Vy());
    mcp_startz.push_back(mcp->Vz());
    mcp_endx.push_back(mcp->EndPosition()[0]);
    mcp_endy.push_back(mcp->EndPosition()[1]);
    mcp_endz.push_back(mcp->EndPosition()[2]);
    if (fmth.isValid()){
      auto vmcth = fmth.at(mcp.key());
      //cout<<vmcth.size()<<endl;
      if (!vmcth.empty()) mcp_nuid.push_back(vmcth[0].key());
    }
 }

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

  fTree->Fill();
}

void dunend::SimDump::beginJob()
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
  fTree->Branch("mcp_nuid", &mcp_nuid);
  fTree->Branch("mcp_energy", &mcp_energy);
  fTree->Branch("mcp_px", &mcp_px);
  fTree->Branch("mcp_py", &mcp_py);
  fTree->Branch("mcp_pz", &mcp_pz);
  fTree->Branch("mcp_startx", &mcp_startx);
  fTree->Branch("mcp_starty", &mcp_starty);
  fTree->Branch("mcp_startz", &mcp_startz);
  fTree->Branch("mcp_endx", &mcp_endx);
  fTree->Branch("mcp_endy", &mcp_endy);
  fTree->Branch("mcp_endz", &mcp_endz);

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

void dunend::SimDump::reset(){

  run = -1;
  subrun = -1;
  event = -1;
  nuPDG.clear();
  ccnc.clear();
  mode.clear();
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

DEFINE_ART_MODULE(dunend::SimDump)
