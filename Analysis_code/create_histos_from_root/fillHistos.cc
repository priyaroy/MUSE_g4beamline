//////////////////////////////////////////////
// Loop over events and fill histograms
//////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "TFile.h"
#include "histos.h"
#include "variable.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TROOT.h"

void fillHistos()
{
	cerr<<endl<<"We are in the fillHistos code now"<<endl;
	int nentries0 = -99;
	int nentries3 = -99;
	int nentriesTar = -99;
	
	int MupEvents0 = 0;
	int MupEvents3 = 0;
	int MupEventsTar = 0;
	
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
    
	///////////////////////////////////////////////
	// Read events from tree0
	///////////////////////////////////////////////
	
	nentries0 = tree0->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det0****** "<<endl;
	cerr<<endl<<"The number of entries in tree0 (det0) = "<<nentries0<<endl;
	
	for(long counter=0; counter<nentries0; counter++)
	{
		// print event number at start detector occasionally
		tree0->GetEntry(counter);
		
		if(counter%5000 == 0 && counter>0) cerr<< " entry number = "<<(nentries0 - counter)<<",  event number = "<<Det0_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det0_PDGid == -13)
		{
			xDet0->Fill(Det0_x);
			yDet0->Fill(Det0_y);
			
			MupEvents0++;
		}
	}
	
	
    ///////////////////////////////////////////////
	// Read events from tree3
	///////////////////////////////////////////////
	
	nentries3 = tree3->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det3****** "<<endl;
	cerr<<endl<<"The number of entries in tree3 (det3) = "<<nentries3<<endl;
	
	for(long counter3=0; counter3<nentries3; counter3++)
	{
		// print event number at start detector occasionally
		tree3->GetEntry(counter3);
		
		if(counter3%5000 == 0 && counter3>0) cerr<< " entry number = "<<(nentries3 - counter3)<<",  event number = "<<Det3_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det3_PDGid == -13)
		{
			xDet3->Fill(Det3_x);
			yDet3->Fill(Det3_y);
			
			MupEvents3++;
		}
	}
	
	///////////////////////////////////////////////
	// Read events from treeTar
	///////////////////////////////////////////////
	
	nentriesTar = treeTar->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to DetTar****** "<<endl;
	cerr<<endl<<"The number of entries in treeTar (detTar) = "<<nentriesTar<<endl;
	
	for(long counterTar=0; counterTar<nentriesTar; counterTar++)
	{
		// print event number at start detector occasionally
		treeTar->GetEntry(counterTar);
		
		if(counterTar%5000 == 0 && counterTar>0) cerr<< " entry number = "<<(nentriesTar - counterTar)<<",  event number = "<<DetTar_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(DetTar_PDGid == -13)
		{
			xDetTar->Fill(DetTar_x);
			yDetTar->Fill(DetTar_y);
			
			MupEventsTar++;
		}

	}
	cerr<<endl<<"End of filling histograms. Summary below:"<<endl<<endl;
	
	cerr<<" Detector	total events	mu+ events"<<endl;
	cerr<<" Det0     "<<nentries0<<"	"<<MupEvents0<<endl;
	cerr<<" Det3     "<<nentries3<<"	"<<MupEvents3<<endl;
	cerr<<" DetTar   "<<nentriesTar<<"	"<<MupEventsTar<<endl;
}
	
	
  
  
  
	  
	    
