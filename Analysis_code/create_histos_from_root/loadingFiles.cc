////////////////////////////////////////
//  The rootfiles to be analyzed are
//  loaded in this routine.
////////////////////////////////////////

#include <iostream>
#include "TChain.h"
#include "TTree.h"
#include "variable.h"
#include "TFile.h"

using namespace std;

void loadingFiles()
{
  cerr<<endl<<"loading root file"<<endl;
  
  //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/MuSEBeam_mu+1551_3Oct2018_original_Paul_element_positions_GradB_LQSLcorr.root");

   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/MuSEBeam_mu+155_dipoleMagnet_tuned_10Oct.root");
   
   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/pencilBeam_studies_10OCt/MuSEBeam_mu+155MeV.root");
   
   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/MuSEBeam_mu+1551_SectorBendingMagnet_apertureCor_12Oct.root");
   
   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/rectangular_beam_studies/MuSEBeam_mu+_155_1.0.root");
   
   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/rectangular_beam_studies_flatP/MuSEBeam_mu+_155_1.0.root");
   
   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/rectangular_beam_studies_flatP/MuSEBeam_mu+_155_1.0_Quadpolarities_reversed_in_1st_3rd_seg.root");
   
   //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/rectangular_beam_studies_flatP/MuSEBeam_mu+_155_1.0_AllQuadpolarities_match_Turtle.root");
   
  //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/rectangular_beam_studies_flatP/MuSEBeam_mu+_155_1.0.root");
  
  //read output with sectorbend where input was from ASCII from Turtle
  //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/Turtle_flat_beam_19Nv2018/IdealSectorBend/MuSEBeam_mu+_155_1.0.root");
  
  //read output with fieldmap where input was from ASCII from Turtle
  //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/Turtle_flat_beam_19Nv2018/Fieldmap/GEM@IFP/MuSEBeam_mu+extendedsource_155_1.0_summer_quad_B.root");
  
  //Read pion point source. Compare with Ethan's 155 MeV electron data (Jan 2019) Summer 2018 B
  //MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/Turtle_flat_beam_19Nv2018/Fieldmap/GEM@IFP/point_source/MuSEBeam_pi+_155_1.0.root");
  
  //Read pion point source data. Compare with Ethan's run 582 data. summer 2018 field but 
 //default for QTA & QTB
  MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/Turtle_ASCII_Gems_at_IFP_NovtoJan2019/Fieldmap/GEM@IFP/point_source/MuSEBeam_pi+pointsource_155_QTA_QTB_defaultB.root");
  
  cerr<<endl<<"Rootfile loaded"<<endl;
  
  //Read ntuples from rootfile
  
  cerr<<endl<<"Now reading ntuples:"<<endl<<endl;
  
  tree0 = (TTree*)MuseFile->Get("VirtualDetector/Det0");
  
  cerr<<endl<<"Now reading ntuples:"<<endl<<endl;
  
  tree0a = (TTree*)MuseFile->Get("VirtualDetector/Det0a");
  
  cerr<<"read ntuple corresponding to virtual detector 0a"<<endl;
  
  treeAQTA1 = (TTree*)MuseFile->Get("VirtualDetector/DetAQTA1");
  
  cerr<<"read ntuple corresponding to virtual detector AQTA1"<<endl;
  
  treeAQTB1 = (TTree*)MuseFile->Get("VirtualDetector/DetAQTB1");
  
  cerr<<"read ntuple corresponding to virtual detector AQTB1"<<endl;
  
  treeAQTB2 = (TTree*)MuseFile->Get("VirtualDetector/DetAQTB2");
  
  cerr<<"read ntuple corresponding to virtual detector AQTB2"<<endl;
  
  tree1 = (TTree*)MuseFile->Get("VirtualDetector/Det1");
  
  cerr<<"read ntuple corresponding to virtual detector 1"<<endl;
  
  tree2 = (TTree*)MuseFile->Get("VirtualDetector/Det2");
  
  cerr<<"read ntuple corresponding to virtual detector 2"<<endl;
  
  tree3 = (TTree*)MuseFile->Get("VirtualDetector/Det3");

  cerr<<"read ntuple corresponding to virtual detector 3"<<endl;
  
  tree4 = (TTree*)MuseFile->Get("VirtualDetector/Det4");
  
  cerr<<"read ntuple corresponding to virtual detector 4"<<endl;
  
  tree5 = (TTree*)MuseFile->Get("VirtualDetector/Det5");
  
  cerr<<"read ntuple corresponding to virtual detector 5"<<endl;
  
  treeTar = (TTree*)MuseFile->Get("VirtualDetector/DetTar");

  cerr<<"read ntuple corresponding to virtual detector at Muse Target"<<endl;
  
  cerr<<endl;
  
}
  
  
