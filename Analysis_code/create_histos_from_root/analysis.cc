//////////////////////////////////////////////////////////////////////
//This accesses ntuple variables in a rootfile and creates histograms
//Created: 21 Sept 2018 by Priyashree Roy
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "TROOT.h"
#include "TStyle.h"
#include "TChain.h"
#include "TFile.h"

using namespace std;

void initialize();
void defineHistos();
void loadingFiles();
void setBranches();
void fillHistos();
void writeROOT();

void analysis()
{
  /////// define and initialize variables

  initialize();
  
  ////// define histograms

  defineHistos();

  ////// Load rootfile and read ntuples

  loadingFiles();

  ////// Read branches from ntuples 
  
  setBranches();

  ////// Fill histograms

  fillHistos();

  delete tree0;
  delete tree3;
  delete treeTar;

  ////// Write the histograms into an output rootfile
  
  writeROOT();

  ////// create plots on canvases and print to a directory

  /////// Set options for histograms

  gROOT -> SetBatch();
  gROOT -> SetStyle("Plain");
  gStyle -> SetOptStat(0);
  gStyle -> SetOptFit(0);
  gStyle -> SetPalette(1);
  gStyle -> SetHistLineWidth(3);
  gStyle -> SetCanvasBorderMode(0);
  gStyle -> SetCanvasColor(kWhite);
  gStyle -> SetTitleColor(1);
  gStyle -> SetStatColor(0);
  gStyle -> SetPadColor(0);
  gStyle -> SetLabelColor(1);
  gStyle -> SetStatColor(0);
  gStyle -> SetStatTextColor(1);
  gStyle -> SetStatBorderSize(0);
  gStyle -> SetPalette(1);
  gStyle -> cd();
  
  
  ////// End of analysis
  cerr<<endl<<"End of analysis ... "<<endl;
}
