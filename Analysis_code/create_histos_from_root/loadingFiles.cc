////////////////////////////////////////
//  The rootfiles to be analyzed are
//  loaded in this routine.
////////////////////////////////////////

#include <iostream>
#include "TChain.h"
#include "TTree.h"
#include "variable.h"

using namespace std;

void loadingFiles()
{
  cerr<<endl<<"loading root file"<<endl;
  
  MuseFile = new TFile("/home/priyaroy/Documents/G4beamline-3.04/muse_input/MuSEBeam_mu+1551_QTA_QTB_polarities_original.root");

  cerr<<endl<<"Rootfile loaded"<<endl;
  
  //Read ntuples from rootfile
  
  cerr<<endl<<"Now reading ntuples:"<<endl<<endl;
  
  tree0 = (TTree*)MuseFile->Get("VirtualDetector/Det0");
  
  cerr<<"read ntuple corresponding to virtual detector 0"<<endl;
  
  tree3 = (TTree*)MuseFile->Get("VirtualDetector/Det3");

  cerr<<"read ntuple corresponding to virtual detector 3"<<endl;
  
  tree3 = (TTree*)MuseFile->Get("VirtualDetector/DetTar");

  cerr<<"read ntuple corresponding to virtual detector at Muse Target"<<endl;
  
  cerr<<endl;
  
}
  
  
