/////////////////////////////////
// Write histograms to root file
/////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TMarker.h"
#include "TPaveText.h"
#include "THStack.h"
#include "TLegend.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TGaxis.h"
#include "TLatex.h"
#include "TColor.h"
#include "TMath.h"
#include "TPaletteAxis.h"
#include "histos.h"
#include "variable.h"

using namespace std;

TDirectoryFile *FitDir[500];

void writeROOT()
{
  cerr << endl << " Writing all histograms to rootfile" << endl;
  
  TFile *f_out = new TFile("anaMUSE_Roy_3OctAdoptedTurtleValues.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_orig_PAul_element_positions_GradB_LQSLcorr.root", "RECREATE");
  
  ////////////////////////
  //Defining directories
  ////////////////////////
  
  FitDir[0] = new TDirectoryFile("Det0","Det0");
  FitDir[1] = new TDirectoryFile("Det3","Det3");
  FitDir[2] = new TDirectoryFile("DetTar","DetTar");
  
  ////////////////////////
  //Write histograms
  ////////////////////////
  
  // Histograms for detector 0
  FitDir[0] -> cd();
  xDet0 -> Write();
  yDet0 -> Write();
  
  // Histograms for detector 3
  FitDir[1] -> cd();
  xDet3 -> Write();
  yDet3 -> Write();
  
  // Histograms for detector 3
  FitDir[2] -> cd();
  xDetTar -> Write();
  yDetTar -> Write();
  
  
  f_out -> Write();
  f_out->Close();
  cerr<<"End of writing histograms to output rootfile"<<endl<<endl;
 
}


