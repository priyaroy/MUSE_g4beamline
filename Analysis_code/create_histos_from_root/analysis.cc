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
#include "analysis.h"
#include "TSystem.h"

using namespace std;

void initialize();
void defineHistos();
void loadingFiles();
void setBranches();
void fillHistos();
void writeROOT();

int main ()
{
	
  gSystem->Load("libTree");
	
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

  ////// Write the histograms into an output rootfile
  
  writeROOT();

  ////// create plots on canvases and print to a directory

  ////// End of analysis
  cerr<<endl<<"End of analysis ... "<<endl;
}
