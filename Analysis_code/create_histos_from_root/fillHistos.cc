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
	
	cerr<<"Is the channel momentum 155 MeV? If not, insert the new channel momentum in fillHistos code"<<endl;
	
	int nentries[15];
	int MupEvents[15];
	float Delta_p[15]; //it is (pchannel-p_event)*100/pchannel i.e. percent dispersion in Pchannel
	float xp[15]; //it is angle in mrad
	float yp[15]; //angle in mrad
	for (int i=0; i<15; i++)
	{
		nentries[i] = -99;
		MupEvents[i] = 0;
		xp[i]=-99;
		yp[i]=-99;	
	}
	
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
	// Read events from tree0 i.e. at Det0
	///////////////////////////////////////////////
	
	nentries[0] = tree0->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det0****** "<<endl;
	cerr<<endl<<"The number of entries in tree0 (det0) = "<<nentries[0]<<endl;
	
	for(long counter=0; counter<nentries[0]; counter++)
	{
		// print event number at start detector occasionally
		tree0->GetEntry(counter);
		
		if(counter%10000 == 0 && counter>0) cerr<< " entry number = "<<(nentries[0] - counter)<<",  event number = "<<Det0_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det0_PDGid == 211)
		{
			xDet0->Fill(-0.1*Det0_x);
			yDet0->Fill(-0.1*Det0_y);
			beamspot_Det0->Fill(-0.1*Det0_x, -0.1*Det0_y);
			
			MupEvents[0]++;
		}
		
		//Fill dispersion histogram
		
		Det0_P = sqrt(pow(Det0_Px, 2) + pow(Det0_Py, 2) + pow(Det0_Pz, 2));
		//Delta_p[0] = (-155.0 + Det0_P)*(100/155.0);
		Delta_p[0] = (-155.0 + Det0_P)*(100/Det0_P);
		
		//angles
		/*
		if(Det0_Px<0)xp[0]=asin(fabs(Det0_Px)/Det0_P)*1000; //angle converted to mrad
		else xp[0]=-1*asin(Det0_Px/Det0_P)*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det0_Py<0)yp[0]=asin(fabs(Det0_Py)/Det0_P)*1000; //angle converted to mrad
		else yp[0]=-1*asin(Det0_Py/Det0_P)*1000; 
		*/
		
		if(Det0_Px<0)xp[0]=fabs(atan(Det0_Px/Det0_Pz))*1000; //angle converted to mrad
		else xp[0]=-1*fabs(atan(Det0_Px/Det0_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det0_Py<0)yp[0]=fabs(atan(Det0_Py/Det0_Pz))*1000; //angle converted to mrad
		else yp[0]=-1*fabs(atan(Det0_Py/Det0_Pz))*1000; 
		if(counter==100 || counter==1000) 
		{
			cerr<<"Px="<<Det0_Px<<",  "<<"Py="<<Det0_Py<<",  "<<"Pz="<<Det0_Pz<<",  "<<"P="<<Det0_P<<endl;
			cerr<< " delta_p (% dispersion) = "<<Delta_p[0]<<endl;
		}
		
		if(Det0_PDGid == 211)
		{
			pxDet0->Fill(xp[0]);
			pyDet0->Fill(yp[0]);
			
			pDet0->Fill(Det0_P);
			dpDet0->Fill(Delta_p[0]);
			pxpy_Det0->Fill(-1*Det0_Px, -1*Det0_Py);
			
			xPx_Det0->Fill(-0.1*Det0_x, xp[0]);
			yPy_Det0->Fill(-0.1*Det0_y, yp[0]);
			dpPx_Det0->Fill(xp[0], Delta_p[0]);
			dpPy_Det0->Fill(yp[0], Delta_p[0]);
			ydp_Det0->Fill(-0.1*Det0_y, Delta_p[0]);
			
			dispersion_Det0->Fill(-1*Det0_x/10.0, Delta_p[0]);
			
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}

	}
	
	///////////////////////////////////////////////
	// Read events from tree1 i.e. at Det1
	///////////////////////////////////////////////
	
	nentries[1] = tree1->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det1****** "<<endl;
	cerr<<endl<<"The number of entries in tree1 (det1) = "<<nentries[1]<<endl;
	
	for(long counter1=0; counter1<nentries[1]; counter1++)
	{
		// print event number at start detector occasionally
		
		tree1->GetEntry(counter1);
		
		if(counter1%10000 == 0 && counter1>0) cerr<< " entry number = "<<(nentries[1] - counter1)<<",  event number = "<<Det1_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det1_PDGid == 211)
		{
			
			xDet1->Fill(-0.1*Det1_x);
			
			//cerr<<"Fill Det1_y"<<endl;
			yDet1->Fill(-0.1*Det1_y);
			
			//cerr<<"Fill beamspot_det1"<<endl;
			beamspot_Det1->Fill(-0.1*Det1_x, -0.1*Det1_y);
			
			//cerr<<"count++"<<endl;
			MupEvents[1]++;
		}
		
		//Fill dispersion histogram
		
		//cerr<<"calculating P"<<endl;
		Det1_P = sqrt(pow(Det1_Px, 2) + pow(Det1_Py, 2) + pow(Det1_Pz, 2));
		Delta_p[1] = (-155.0 + Det1_P)*(100/155.0);
		
		//angles
		/*
		if(Det1_Px<0)xp[1]=asin(Det1_Px/Det1_P)*1000; //angle converted to mrad
		else xp[1]=-1*asin(Det1_Px/Det1_P)*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det1_Py<0)yp[1]=asin(Det1_Py/Det1_P)*1000; //angle converted to mrad
		else yp[1]=-1*asin(Det1_Py/Det1_P)*1000;
		*/
		
		if(Det1_Px<0)xp[1]=fabs(atan(Det1_Px/Det1_Pz))*1000; //angle converted to mrad
		else xp[1]=-1*fabs(atan(Det1_Px/Det1_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det1_Py<0)yp[1]=fabs(atan(Det1_Py/Det1_Pz))*1000; //angle converted to mrad
		else yp[1]=-1*fabs(atan(Det1_Py/Det1_Pz))*1000; 
		
		if(counter1==100 || counter1==1000) 
		{
			cerr<<"Px="<<Det1_Px<<",  "<<"Py="<<Det1_Py<<",  "<<"Pz="<<Det1_Pz<<",  "<<"P="<<Det1_P<<endl;
			cerr<< " delta_p (% dispersion) = "<<Delta_p[1]<<endl;
		}
		
		if(Det1_PDGid == 211)
		{
			pxDet1->Fill(xp[1]);
			pyDet1->Fill(yp[1]);
			pDet1->Fill(Det1_P);
			dpDet1->Fill(Delta_p[1]);
			
			pxpy_Det1->Fill(-1*Det1_Px, -1*Det1_Py);
			
			xPx_Det1->Fill(-0.1*Det1_x, xp[1]);
			yPy_Det1->Fill(-0.1*Det1_y, yp[1]);
			dpPx_Det1->Fill(xp[1], Delta_p[1]);
			dpPy_Det1->Fill(yp[1], Delta_p[1]);
			ydp_Det1->Fill(-0.1*Det1_y, Delta_p[1]);
			
			dispersion_Det1->Fill(-1*Det1_x/10.0, Delta_p[1]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
		
	}
	
	
	///////////////////////////////////////////////
	// Read events from tree2 i.e. at Det2
	///////////////////////////////////////////////
	
	nentries[2] = tree2->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det2****** "<<endl;
	cerr<<endl<<"The number of entries in tree2 (det2) = "<<nentries[2]<<endl;
	
	for(long counter2=0; counter2<nentries[2]; counter2++)
	{
		// print event number at start detector occasionally
		tree2->GetEntry(counter2);
		
		if(counter2%10000 == 0 && counter2>0) cerr<< " entry number = "<<(nentries[2] - counter2)<<",  event number = "<<Det2_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det2_PDGid == 211)
		{
			xDet2->Fill(-0.1*Det2_x);
			yDet2->Fill(-0.1*Det2_y);
			beamspot_Det2->Fill(-0.1*Det2_x, -0.1*Det2_y);
			
			MupEvents[2]++;
		}
		
		//Fill dispersion histogram
		
		Det2_P = sqrt(pow(Det2_Px, 2) + pow(Det2_Py, 2) + pow(Det2_Pz, 2));
		Delta_p[2] = (-155.0 + Det2_P)*(100/155.0);
		
		if(Det2_Px<0)xp[2]=fabs(atan(Det2_Px/Det2_Pz))*1000; //angle converted to mrad
		else xp[2]=-1*fabs(atan(Det2_Px/Det2_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det2_Py<0)yp[2]=fabs(atan(Det2_Py/Det2_Pz))*1000; //angle converted to mrad
		else yp[2]=-1*fabs(atan(Det2_Py/Det2_Pz))*1000; 
		
		if(counter2==100 || counter2==1000) cerr<< " delta_p (% dispersion) = "<<Delta_p[2]<<endl;
		
		if(Det2_PDGid == -13)
		{
			pxDet2->Fill(xp[2]);
			pyDet2->Fill(yp[2]);
			pDet2->Fill(Det2_P);
			dpDet2->Fill(Delta_p[2]);
			pxpy_Det2->Fill(-1*Det2_Px, -1*Det2_Py);
			
			xPx_Det2->Fill(-0.1*Det2_x, xp[2]);
			yPy_Det2->Fill(-0.1*Det2_y, yp[2]);
			dpPx_Det2->Fill(xp[2], Delta_p[2]);
			dpPy_Det2->Fill(yp[2], Delta_p[2]);
			ydp_Det2->Fill(-0.1*Det2_y, Delta_p[2]);
			
			dispersion_Det2->Fill(-1*Det2_x/10.0, Delta_p[2]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
		
	}
	
	
    ///////////////////////////////////////////////
	// Read events from tree3 i.e. @ DetIFP
	///////////////////////////////////////////////
	
	nentries[3] = tree3->GetEntries();
	nentries[7] = treeTar->GetEntries();
	cerr<<endl<<"**********Filling histograms that hit Det3 and also make it to the target****** "<<endl;
	cerr<<endl<<"The number of entries in tree3 (detIFP) = "<<nentries[3]<<endl;
	cerr<<endl<<"The number of entries in treeTar (PiM1Tar) = "<<nentries[7]<<endl;
	
	for(long counter3=0; counter3<nentries[3]; counter3++)
	{
		tree3->GetEntry(counter3);
		for(long counterNew=0; counterNew<nentries[7]; counterNew++)
		{
			treeTar->GetEntry(counterNew);
			
			if(Det3_EventID==DetTar_EventID)
			{
				if(Det3_PDGid == 211)
				{
					//Fill spatial histogram
					
					xDet3->Fill(-0.1*Det3_x);
					yDet3->Fill(-0.1*Det3_y);
					beamspot_Det3->Fill(-0.1*Det3_x, -0.1*Det3_y);
					MupEvents[3]++;
					
					//Fill dispersion histogram
					
					Det3_P = sqrt(pow(Det3_Px, 2) + pow(Det3_Py, 2) + pow(Det3_Pz, 2));
					Delta_p[3] = (-155.0 + Det3_P)*(100/155.0);
					if(Det3_Px<0)xp[3]=fabs(atan(Det3_Px/Det3_Pz))*1000; //angle converted to mrad
					else xp[3]=-1*fabs(atan(Det3_Px/Det3_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
					if(Det3_Py<0)yp[3]=fabs(atan(Det3_Py/Det3_Pz))*1000; //angle converted to mrad
					else yp[3]=-1*fabs(atan(Det3_Py/Det3_Pz))*1000; 
					
					pxDet3->Fill(xp[3]);
					pyDet3->Fill(yp[3]);
					pDet3->Fill(Det3_P);
					dpDet3->Fill(Delta_p[3]);
					pxpy_Det3->Fill(-1*Det3_Px, -1*Det3_Py);
					
					xPx_Det3->Fill(-0.1*Det3_x, xp[3]);
					yPy_Det3->Fill(-0.1*Det3_y, yp[3]);
					dpPx_Det3->Fill(xp[3], Delta_p[3]);
					dpPy_Det3->Fill(yp[3], Delta_p[3]);
					ydp_Det3->Fill(-0.1*Det3_y, Delta_p[3]);
					
					dispersion_IFP->Fill(-1*Det3_x/10.0, Delta_p[3]);
			        //I flipped the sign of x so that it matches Turtle. Is easier to compare.
				}
			}
			
			else continue;
		}
	}
	
	///////////////////////////////////////////////
	// Read events from tree4 i.e. @ Det4
	///////////////////////////////////////////////
	
	nentries[4] = tree4->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det4****** "<<endl;
	cerr<<endl<<"The number of entries in tree4 (det4) = "<<nentries[4]<<endl;
	
	for(long counter4=0; counter4<nentries[4]; counter4++)
	{
		// print event number at start detector occasionally
		tree4->GetEntry(counter4);
		
		if(counter4%10000 == 0 && counter4>0) cerr<< " entry number = "<<(nentries[4] - counter4)<<",  event number = "<<Det4_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det4_PDGid == -13)
		{
			xDet4->Fill(-0.1*Det4_x);
			yDet4->Fill(-0.1*Det4_y);
			beamspot_Det4->Fill(-0.1*Det4_x, -0.1*Det4_y);
			
			MupEvents[4]++;
		}
		
		//Fill dispersion histogram
		
		Det4_P = sqrt(pow(Det4_Px, 2) + pow(Det4_Py, 2) + pow(Det4_Pz, 2));
		Delta_p[4] = (-155.0 + Det4_P)*(100/155.0);
		
		if(Det4_Px<0)xp[4]=fabs(atan(Det4_Px/Det4_Pz))*1000; //angle converted to mrad
		else xp[4]=-1*fabs(atan(Det4_Px/Det4_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det4_Py<0)yp[4]=fabs(atan(Det4_Py/Det4_Pz))*1000; //angle converted to mrad
		else yp[4]=-1*fabs(atan(Det4_Py/Det4_Pz))*1000; 
		
		if(counter4==100 || counter4==1000) cerr<< " delta_p (% dispersion) = "<<Delta_p[4]<<endl;
		
		if(Det4_PDGid == -13)
		{
			pxDet4->Fill(xp[4]);
			pyDet4->Fill(yp[4]);
			pDet4->Fill(Det4_P);
			dpDet4->Fill(Delta_p[4]);
			pxpy_Det4->Fill(-1*Det4_Px, -1*Det4_Py);
			
			xPx_Det4->Fill(-0.1*Det4_x, xp[4]);
			yPy_Det4->Fill(-0.1*Det4_y, yp[4]);
			dpPx_Det4->Fill(xp[4], Delta_p[4]);
			dpPy_Det4->Fill(yp[4], Delta_p[4]);
			ydp_Det4->Fill(-0.1*Det4_y, Delta_p[4]);
			
			dispersion_Det4->Fill(-1*Det4_x/10.0, Delta_p[4]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
	}

///////////////////////////////////////////////
	// Read events from tree5 i.e. @ Det5
	///////////////////////////////////////////////
	
	nentries[5] = tree5->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det5****** "<<endl;
	cerr<<endl<<"The number of entries in tree5 (det5) = "<<nentries[5]<<endl;
	
	for(long counter5=0; counter5<nentries[5]; counter5++)
	{
		// print event number at start detector occasionally
		tree5->GetEntry(counter5);
		
		if(counter5%10000 == 0 && counter5>0) cerr<< " entry number = "<<(nentries[5] - counter5)<<",  event number = "<<Det5_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det5_PDGid == -13)
		{
			xDet5->Fill(-0.1*Det5_x);
			yDet5->Fill(-0.1*Det5_y);
			beamspot_Det5->Fill(-0.1*Det5_x, -0.1*Det5_y);
			
			MupEvents[5]++;
		}
		
		//Fill dispersion histogram
		
		Det5_P = sqrt(pow(Det5_Px, 2) + pow(Det5_Py, 2) + pow(Det5_Pz, 2));
		Delta_p[5] = (-155.0 + Det5_P)*(100/155.0);
		
		if(Det5_Px<0)xp[5]=fabs(atan(Det5_Px/Det5_Pz))*1000; //angle converted to mrad
		else xp[5]=-1*fabs(atan(Det5_Px/Det5_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det5_Py<0)yp[5]=fabs(atan(Det5_Py/Det5_Pz))*1000; //angle converted to mrad
		else yp[5]=-1*fabs(atan(Det5_Py/Det5_Pz))*1000; 
		
		if(counter5==100 || counter5==1000) cerr<< " delta_p (% dispersion) = "<<Delta_p[5]<<endl;
		
		if(Det5_PDGid == -13)
		{
			pxDet5->Fill(xp[5]);
			pyDet5->Fill(yp[5]);
			pDet5->Fill(Det5_P);
			dpDet5->Fill(Delta_p[5]);
			pxpy_Det5->Fill(-1*Det5_Px, -1*Det5_Py);
			
			xPx_Det5->Fill(-0.1*Det5_x, xp[5]);
			yPy_Det5->Fill(-0.1*Det5_y, yp[5]);
			dpPx_Det5->Fill(xp[5], Delta_p[5]);
			dpPy_Det5->Fill(yp[5], Delta_p[5]);
			ydp_Det5->Fill(-0.1*Det5_y, Delta_p[5]);
			
			dispersion_Det5->Fill(-1*Det5_x/10.0, Delta_p[5]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
	}
	
	///////////////////////////////////////////////
	// Read events from treeTar
	///////////////////////////////////////////////
	
	nentries[7] = treeTar->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to DetTar****** "<<endl;
	cerr<<endl<<"The number of entries in treeTar (detTar) = "<<nentries[7]<<endl;
	
	for(long counterTar=0; counterTar<nentries[7]; counterTar++)
	{
		// print event number at start detector occasionally
		treeTar->GetEntry(counterTar);
		
		if(counterTar%10000 == 0 && counterTar>0) cerr<< " entry number = "<<(nentries[7] - counterTar)<<",  event number = "<<DetTar_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(DetTar_PDGid == 211)
		{
			xDetTar->Fill(-0.1*DetTar_x);
			yDetTar->Fill(-0.1*DetTar_y);
			beamspot_DetTar->Fill(-0.1*DetTar_x, -0.1*DetTar_y);
			
			MupEvents[7]++;
		}
		
		//Fill dispersion histogram
		
		DetTar_P = sqrt(pow(DetTar_Px, 2) + pow(DetTar_Py, 2) + pow(DetTar_Pz, 2));
		Delta_p[7] = (-155.0 + DetTar_P)*(100/155.0);
		
		if(DetTar_Px<0)xp[7]=fabs(atan(DetTar_Px/DetTar_Pz))*1000; //angle converted to mrad
		else xp[7]=-1*fabs(atan(DetTar_Px/DetTar_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(DetTar_Py<0)yp[7]=fabs(atan(DetTar_Py/DetTar_Pz))*1000; //angle converted to mrad
		else yp[7]=-1*fabs(atan(DetTar_Py/DetTar_Pz))*1000; 
		
		if(counterTar==100 || counterTar==1000) cerr<< " delta_p (% dispersion) = "<<Delta_p[7]<<endl;
		
		if(DetTar_PDGid == 211)
		{
			pxDetTar->Fill(xp[7]);
			pyDetTar->Fill(yp[7]);
			pDetTar->Fill(DetTar_P);
			dpDetTar->Fill(Delta_p[7]);
			pxpy_DetTar->Fill(-1*DetTar_Px, -1*DetTar_Py);
			
			xPx_DetTar->Fill(-0.1*DetTar_x,xp[7]);
			yPy_DetTar->Fill(-0.1*DetTar_y, yp[7]);
			dpPx_DetTar->Fill(xp[7], Delta_p[7]);
			dpPy_DetTar->Fill(yp[7], Delta_p[7]);
			ydp_DetTar->Fill(-0.1*DetTar_y, Delta_p[7]);
			
			dispersion_Tar->Fill(-1*DetTar_x/10.0, Delta_p[7]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
	}
		
     ///////////////////////////////////////////////
	// Read events from Det0a
	///////////////////////////////////////////////
	
	nentries[8] = tree0a->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to Det0a****** "<<endl;
	cerr<<endl<<"The number of entries in tree0a (det0a) = "<<nentries[8]<<endl;
	
	for(long counter8=0; counter8<nentries[8]; counter8++)
	{
		// print event number at start detector occasionally
		tree0a->GetEntry(counter8);
		
		if(counter8%10000 == 0 && counter8>0) cerr<< " entry number = "<<(nentries[8] - counter8)<<",  event number = "<<Det0a_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(Det0a_PDGid == -13)
		{
			xDet0a->Fill(-0.1*Det0a_x);
			yDet0a->Fill(-0.1*Det0a_y);
			beamspot_Det0a->Fill(-0.1*Det0a_x, -0.1*Det0a_y);
			
			MupEvents[8]++;
		}
		
		//Fill dispersion histogram
		
		Det0a_P = sqrt(pow(Det0a_Px, 2) + pow(Det0a_Py, 2) + pow(Det0a_Pz, 2));
		Delta_p[8] = (-155.0 + Det0a_P)*(100/155.0);
		
		if(Det0a_Px<0)xp[8]=fabs(atan(Det0a_Px/Det0a_Pz))*1000; //angle converted to mrad
		else xp[8]=-1*fabs(atan(Det0a_Px/Det0a_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(Det0a_Py<0)yp[8]=fabs(atan(Det0a_Py/Det0a_Pz))*1000; //angle converted to mrad
		else yp[8]=-1*fabs(atan(Det0a_Py/Det0a_Pz))*1000; 
		
		if(counter8==100 || counter8==1000) 
		{
			cerr<<"Px="<<Det0a_Px<<",  "<<"Py="<<Det0a_Py<<",  "<<"Pz="<<Det0a_Pz<<",  "<<"P="<<Det0a_P<<endl;
			cerr<< " delta_p (% dispersion) = "<<Delta_p[8]<<endl;
		}
		
		if(Det0a_PDGid == -13)
		{
			pxDet0a->Fill(xp[8]);
			pyDet0a->Fill(yp[8]);
			pDet0a->Fill(Det0a_P);
			dpDet0a->Fill(Delta_p[8]);
			pxpy_Det0a->Fill(-1*Det0a_Px, -1*Det0a_Py);
			
			xPx_Det0a->Fill(-0.1*Det0a_x, xp[8]);
			yPy_Det0a->Fill(-0.1*Det0a_y, yp[8]);
			dpPx_Det0a->Fill(xp[8], Delta_p[8]);
			dpPy_Det0a->Fill(yp[8], Delta_p[8]);
			ydp_Det0a->Fill(-0.1*Det0a_y, Delta_p[8]);
			
			dispersion_Det0a->Fill(-1*Det0a_x/10.0, Delta_p[8]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
	}
		
	///////////////////////////////////////////////
	// Read events from DetAQTA1
	///////////////////////////////////////////////
	
	nentries[9] = treeAQTA1->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to DetAQTA1****** "<<endl;
	cerr<<endl<<"The number of entries in treeAQTA1 (detAQTA1) = "<<nentries[9]<<endl;
	
	for(long counter9=0; counter9<nentries[9]; counter9++)
	{
		// print event number at start detector occasionally
		treeAQTA1->GetEntry(counter9);
		
		if(counter9%10000 == 0 && counter9>0) cerr<< " entry number = "<<(nentries[9] - counter9)<<",  event number = "<<DetAQTA1_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(DetAQTA1_PDGid == -13)
		{
			xDetAQTA1->Fill(-0.1*DetAQTA1_x);
			yDetAQTA1->Fill(-0.1*DetAQTA1_y);
			beamspot_DetAQTA1->Fill(-0.1*DetAQTA1_x, -0.1*DetAQTA1_y);
			
			MupEvents[9]++;
		}
		
		//Fill dispersion histogram
		
		DetAQTA1_P = sqrt(pow(DetAQTA1_Px, 2) + pow(DetAQTA1_Py, 2) + pow(DetAQTA1_Pz, 2));
		Delta_p[9] = (-155.0 + DetAQTA1_P)*(100/155.0);
		
		if(DetAQTA1_Px<0)xp[9]=fabs(atan(DetAQTA1_Px/DetAQTA1_Pz))*1000; //angle converted to mrad
		else xp[9]=-1*fabs(atan(DetAQTA1_Px/DetAQTA1_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(DetAQTA1_Py<0)yp[9]=fabs(atan(DetAQTA1_Py/DetAQTA1_Pz))*1000; //angle converted to mrad
		else yp[9]=-1*fabs(atan(DetAQTA1_Py/DetAQTA1_Pz))*1000; 
		
		if(counter9==100 || counter9==1000) 
		{
			cerr<<"Px="<<DetAQTA1_Px<<",  "<<"Py="<<DetAQTA1_Py;
			cerr<<",  "<<"Pz="<<DetAQTA1_Pz<<",  "<<"P="<<DetAQTA1_P<<endl;
			cerr<< " delta_p (% dispersion) = "<<Delta_p[9]<<endl;
		}
		
		if(DetAQTA1_PDGid == -13)
		{
			pxDetAQTA1->Fill(xp[9]);
			pyDetAQTA1->Fill(yp[9]);
			pDetAQTA1->Fill(DetAQTA1_P);
			dpDetAQTA1->Fill(Delta_p[9]);
			pxpy_DetAQTA1->Fill(-1*DetAQTA1_Px, -1*DetAQTA1_Py);
			
			xPx_DetAQTA1->Fill(-0.1*DetAQTA1_x, xp[9]);
			yPy_DetAQTA1->Fill(-0.1*DetAQTA1_y, yp[9]);
			dpPx_DetAQTA1->Fill(xp[9], Delta_p[9]);
			dpPy_DetAQTA1->Fill(yp[9], Delta_p[9]);
			ydp_DetAQTA1->Fill(-0.1*DetAQTA1_y, Delta_p[9]);
			
			dispersion_DetAQTA1->Fill(-1*DetAQTA1_x/10.0, Delta_p[9]);
			//I flipped the sign of x so that it matches Turtle. 
			//Is easier to compare.
		}	

	}
	
	///////////////////////////////////////////////
	// Read events from DetAQTB1
	///////////////////////////////////////////////
	
	nentries[10] = treeAQTB1->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to DetAQTB1****** "<<endl;
	cerr<<endl<<"The number of entries in treeAQTB1 (detAQTB1) = "<<nentries[10]<<endl;
	
	for(long counter10=0; counter10<nentries[10]; counter10++)
	{
		// print event number at start detector occasionally
		treeAQTB1->GetEntry(counter10);
		
		if(counter10%10000 == 0 && counter10>0) cerr<< " entry number = "<<(nentries[10] - counter10)<<",  event number = "<<DetAQTB1_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(DetAQTB1_PDGid == -13)
		{
			xDetAQTB1->Fill(-0.1*DetAQTB1_x);
			yDetAQTB1->Fill(-0.1*DetAQTB1_y);
			beamspot_DetAQTB1->Fill(-0.1*DetAQTB1_x, -0.1*DetAQTB1_y);
			
			MupEvents[10]++;
		}
		
		//Fill dispersion histogram
		
		DetAQTB1_P = sqrt(pow(DetAQTB1_Px, 2) + pow(DetAQTB1_Py, 2) + pow(DetAQTB1_Pz, 2));
		Delta_p[10] = (-155.0 + DetAQTB1_P)*(100/155.0);
		
		if(DetAQTB1_Px<0)xp[10]=fabs(atan(DetAQTB1_Px/DetAQTB1_Pz))*1000; //angle converted to mrad
		else xp[10]=-1*fabs(atan(DetAQTB1_Px/DetAQTB1_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(DetAQTB1_Py<0)yp[10]=fabs(atan(DetAQTB1_Py/DetAQTB1_Pz))*1000; //angle converted to mrad
		else yp[10]=-1*fabs(atan(DetAQTB1_Py/DetAQTB1_Pz))*1000; 
		
		if(counter10==100 || counter10==1000) 
		{
			cerr<<"Px="<<DetAQTB1_Px<<",  "<<"Py="<<DetAQTB1_Py<<",  "<<"Pz="<<DetAQTB1_Pz<<",  "<<"P="<<DetAQTB1_P<<endl;
			cerr<< " delta_p (% dispersion) = "<<Delta_p[10]<<endl;
		}
		
		if(DetAQTB1_PDGid == -13)
		{
			pxDetAQTB1->Fill(xp[10]);
			pyDetAQTB1->Fill(yp[10]);
			pDetAQTB1->Fill(DetAQTB1_P);
			dpDetAQTB1->Fill(Delta_p[10]);
			pxpy_DetAQTB1->Fill(-1*DetAQTB1_Px, -1*DetAQTB1_Py);
			
			xPx_DetAQTB1->Fill(-0.1*DetAQTB1_x, xp[10]);
			yPy_DetAQTB1->Fill(-0.1*DetAQTB1_y, yp[10]);
			dpPx_DetAQTB1->Fill(xp[10], Delta_p[10]);
			dpPy_DetAQTB1->Fill(yp[10], Delta_p[10]);
			ydp_DetAQTB1->Fill(-0.1*DetAQTB1_y, Delta_p[10]);
			
			dispersion_DetAQTB1->Fill(-1*DetAQTB1_x/10.0, Delta_p[10]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}	

	}
	
	///////////////////////////////////////////////
	// Read events from DetAQTB2
	///////////////////////////////////////////////
	
	nentries[11] = treeAQTB2->GetEntries();
	cerr<<endl<<"**********Filling histograms corresponding to DetAQTB2****** "<<endl;
	cerr<<endl<<"The number of entries in treeAQTB2 (detAQTB2) = "<<nentries[11]<<endl;
	
	for(long counter11=0; counter11<nentries[11]; counter11++)
	{
		// print event number at start detector occasionally
		treeAQTB2->GetEntry(counter11);
		
		if(counter11%10000 == 0 && counter11>0) cerr<< " entry number = "<<(nentries[11] - counter11)<<",  event number = "<<DetAQTB2_EventID<<endl<<endl;
		
		//Fill spatial distribution histograms
		
		if(DetAQTB2_PDGid == -13)
		{
			xDetAQTB2->Fill(-0.1*DetAQTB2_x);
			yDetAQTB2->Fill(-0.1*DetAQTB2_y);
			beamspot_DetAQTB2->Fill(-0.1*DetAQTB2_x, -0.1*DetAQTB2_y);
			
			MupEvents[11]++;
		}
		
		//Fill dispersion histogram
		
		DetAQTB2_P = sqrt(pow(DetAQTB2_Px, 2) + pow(DetAQTB2_Py, 2) + pow(DetAQTB2_Pz, 2));
		Delta_p[11] = (-155.0 + DetAQTB2_P)*(100/155.0);
		
		if(DetAQTB2_Px<0)xp[11]=fabs(atan(DetAQTB2_Px/DetAQTB2_Pz))*1000; //angle converted to mrad
		else xp[11]=-1*fabs(atan(DetAQTB2_Px/DetAQTB2_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		
		if(DetAQTB2_Py<0)yp[11]=fabs(atan(DetAQTB2_Py/DetAQTB2_Pz))*1000; //angle converted to mrad
		else yp[11]=-1*fabs(atan(DetAQTB2_Py/DetAQTB2_Pz))*1000; 
		
		if(counter11==100 || counter11==1000) 
		{
			cerr<<"Px="<<DetAQTB2_Px<<",  "<<"Py="<<DetAQTB2_Py<<",  "<<"Pz="<<DetAQTB2_Pz<<",  "<<"P="<<DetAQTB2_P<<endl;
			cerr<< " delta_p (% dispersion) = "<<Delta_p[11]<<endl;
		}
		
		if(DetAQTB2_PDGid == -13)
		{
			pxDetAQTB2->Fill(xp[11]);
			pyDetAQTB2->Fill(yp[11]);
			pDetAQTB2->Fill(DetAQTB2_P);
			dpDetAQTB2->Fill(Delta_p[11]);
			pxpy_DetAQTB2->Fill(-1*DetAQTB2_Px, -1*DetAQTB2_Py);
			
			xPx_DetAQTB2->Fill(-0.1*DetAQTB2_x, xp[11]);
			yPy_DetAQTB2->Fill(-0.1*DetAQTB2_y, yp[11]);
			dpPx_DetAQTB2->Fill(xp[11], Delta_p[11]);
			dpPy_DetAQTB2->Fill(yp[11], Delta_p[11]);
			ydp_DetAQTB2->Fill(-0.1*DetAQTB2_y, Delta_p[11]);
			
			dispersion_DetAQTB2->Fill(-1*DetAQTB2_x/10.0, Delta_p[11]);
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}	

	}
	
	cerr<<endl<<"End of filling histograms from simulation. Summary below:"<<endl<<endl;
	
	cerr<<" Detector	total events	mu+ events"<<endl;
	
	for(int i=0; i<12; i++)
	{
		if(i!=3 && i!=7 && i<8)cerr<<" Det"<<i<<"	          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
		else if(i==3)cerr<<" DetIFP	          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
		else if(i==7)cerr<<" DetTar	          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
		else if(i==8)cerr<<" Det0a          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
		else if(i==9)cerr<<" DetAQTA1          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
		else if(i==10)cerr<<" DetAQTB1          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
		else if(i==11)cerr<<" DetAQTB2          "<<nentries[i]<<"	   "<<MupEvents[i]<<endl;
	}
	
	
	cerr<<"Compare with summer 2018 data"<<endl;
	
    //At IFP
    //This is pion data from Ethan. Run582 from summer 2018
    
   xifp__2->SetBinContent(43,4);
   xifp__2->SetBinContent(47,14);
   xifp__2->SetBinContent(49,5);
   xifp__2->SetBinContent(50,2);
   xifp__2->SetBinContent(51,12);
   xifp__2->SetBinContent(52,20);
   xifp__2->SetBinContent(53,4);
   xifp__2->SetBinContent(54,18);
   xifp__2->SetBinContent(55,12);
   xifp__2->SetBinContent(56,7);
   xifp__2->SetBinContent(57,8);
   xifp__2->SetBinContent(58,4);
   xifp__2->SetBinContent(59,91);
   xifp__2->SetBinContent(60,99);
   xifp__2->SetBinContent(61,60);
   xifp__2->SetBinContent(62,74);
   xifp__2->SetBinContent(63,102);
   xifp__2->SetBinContent(64,148);
   xifp__2->SetBinContent(65,132);
   xifp__2->SetBinContent(66,234);
   xifp__2->SetBinContent(67,348);
   xifp__2->SetBinContent(68,501);
   xifp__2->SetBinContent(69,630);
   xifp__2->SetBinContent(70,1010);
   xifp__2->SetBinContent(71,1028);
   xifp__2->SetBinContent(72,1136);
   xifp__2->SetBinContent(73,973);
   xifp__2->SetBinContent(74,1362);
   xifp__2->SetBinContent(75,1341);
   xifp__2->SetBinContent(76,1187);
   xifp__2->SetBinContent(77,683);
   xifp__2->SetBinContent(78,834);
   xifp__2->SetBinContent(79,832);
   xifp__2->SetBinContent(80,1110);
   xifp__2->SetBinContent(81,1416);
   xifp__2->SetBinContent(82,1040);
   xifp__2->SetBinContent(83,979);
   xifp__2->SetBinContent(84,536);
   xifp__2->SetBinContent(85,419);
   xifp__2->SetBinContent(86,248);
   xifp__2->SetBinContent(87,297);
   xifp__2->SetBinContent(88,178);
   xifp__2->SetBinContent(89,62);
   xifp__2->SetBinContent(90,147);
   xifp__2->SetBinContent(91,84);
   xifp__2->SetBinContent(92,41);
   xifp__2->SetBinContent(93,72);
   xifp__2->SetBinContent(94,25);
   xifp__2->SetBinContent(95,46);
   xifp__2->SetBinContent(96,25);
   xifp__2->SetBinContent(97,19);
   xifp__2->SetBinContent(98,7);
   xifp__2->SetBinContent(99,11);
   xifp__2->SetBinContent(101,2);
   xifp__2->SetBinContent(102,11);
   xifp__2->SetBinContent(103,6);
   xifp__2->SetBinContent(106,2);
   xifp__2->SetBinContent(107,20);
   xifp__2->SetBinError(43,2);
   xifp__2->SetBinError(47,3.74166);
   xifp__2->SetBinError(49,2.23607);
   xifp__2->SetBinError(50,1.41421);
   xifp__2->SetBinError(51,3.4641);
   xifp__2->SetBinError(52,4.47214);
   xifp__2->SetBinError(53,2);
   xifp__2->SetBinError(54,4.24264);
   xifp__2->SetBinError(55,3.4641);
   xifp__2->SetBinError(56,2.64575);
   xifp__2->SetBinError(57,2.82843);
   xifp__2->SetBinError(58,2);
   xifp__2->SetBinError(59,9.53939);
   xifp__2->SetBinError(60,9.94987);
   xifp__2->SetBinError(61,7.74597);
   xifp__2->SetBinError(62,8.60233);
   xifp__2->SetBinError(63,10.0995);
   xifp__2->SetBinError(64,12.1655);
   xifp__2->SetBinError(65,11.4891);
   xifp__2->SetBinError(66,15.2971);
   xifp__2->SetBinError(67,18.6548);
   xifp__2->SetBinError(68,22.383);
   xifp__2->SetBinError(69,25.0998);
   xifp__2->SetBinError(70,31.7805);
   xifp__2->SetBinError(71,32.0624);
   xifp__2->SetBinError(72,33.7046);
   xifp__2->SetBinError(73,31.1929);
   xifp__2->SetBinError(74,36.9053);
   xifp__2->SetBinError(75,36.6197);
   xifp__2->SetBinError(76,34.4529);
   xifp__2->SetBinError(77,26.1343);
   xifp__2->SetBinError(78,28.8791);
   xifp__2->SetBinError(79,28.8444);
   xifp__2->SetBinError(80,33.3167);
   xifp__2->SetBinError(81,37.6298);
   xifp__2->SetBinError(82,32.249);
   xifp__2->SetBinError(83,31.289);
   xifp__2->SetBinError(84,23.1517);
   xifp__2->SetBinError(85,20.4695);
   xifp__2->SetBinError(86,15.748);
   xifp__2->SetBinError(87,17.2337);
   xifp__2->SetBinError(88,13.3417);
   xifp__2->SetBinError(89,7.87401);
   xifp__2->SetBinError(90,12.1244);
   xifp__2->SetBinError(91,9.16515);
   xifp__2->SetBinError(92,6.40312);
   xifp__2->SetBinError(93,8.48528);
   xifp__2->SetBinError(94,5);
   xifp__2->SetBinError(95,6.78233);
   xifp__2->SetBinError(96,5);
   xifp__2->SetBinError(97,4.3589);
   xifp__2->SetBinError(98,2.64575);
   xifp__2->SetBinError(99,3.31662);
   xifp__2->SetBinError(101,1.41421);
   xifp__2->SetBinError(102,3.31662);
   xifp__2->SetBinError(103,2.44949);
   xifp__2->SetBinError(106,1.41421);
   xifp__2->SetBinError(107,4.47214);
   xifp__2->SetEntries(19718);
   
   yifp__4->SetBinContent(54,19);
   yifp__4->SetBinContent(55,11);
   yifp__4->SetBinContent(56,71);
   yifp__4->SetBinContent(57,62);
   yifp__4->SetBinContent(58,82);
   yifp__4->SetBinContent(59,223);
   yifp__4->SetBinContent(60,131);
   yifp__4->SetBinContent(61,110);
   yifp__4->SetBinContent(62,210);
   yifp__4->SetBinContent(63,404);
   yifp__4->SetBinContent(64,384);
   yifp__4->SetBinContent(65,493);
   yifp__4->SetBinContent(66,852);
   yifp__4->SetBinContent(67,833);
   yifp__4->SetBinContent(68,1058);
   yifp__4->SetBinContent(69,1312);
   yifp__4->SetBinContent(70,1255);
   yifp__4->SetBinContent(71,1157);
   yifp__4->SetBinContent(72,1143);
   yifp__4->SetBinContent(73,865);
   yifp__4->SetBinContent(74,1009);
   yifp__4->SetBinContent(75,953);
   yifp__4->SetBinContent(76,634);
   yifp__4->SetBinContent(77,569);
   yifp__4->SetBinContent(78,443);
   yifp__4->SetBinContent(79,746);
   yifp__4->SetBinContent(80,523);
   yifp__4->SetBinContent(81,472);
   yifp__4->SetBinContent(82,405);
   yifp__4->SetBinContent(83,400);
   yifp__4->SetBinContent(84,360);
   yifp__4->SetBinContent(85,418);
   yifp__4->SetBinContent(86,300);
   yifp__4->SetBinContent(87,354);
   yifp__4->SetBinContent(88,303);
   yifp__4->SetBinContent(89,183);
   yifp__4->SetBinContent(90,292);
   yifp__4->SetBinContent(91,140);
   yifp__4->SetBinContent(92,124);
   yifp__4->SetBinContent(93,170);
   yifp__4->SetBinContent(94,88);
   yifp__4->SetBinContent(95,121);
   yifp__4->SetBinContent(96,23);
   yifp__4->SetBinContent(97,9);
   yifp__4->SetBinContent(98,4);
   yifp__4->SetBinError(54,4.3589);
   yifp__4->SetBinError(55,3.31662);
   yifp__4->SetBinError(56,8.42615);
   yifp__4->SetBinError(57,7.87401);
   yifp__4->SetBinError(58,9.05539);
   yifp__4->SetBinError(59,14.9332);
   yifp__4->SetBinError(60,11.4455);
   yifp__4->SetBinError(61,10.4881);
   yifp__4->SetBinError(62,14.4914);
   yifp__4->SetBinError(63,20.0998);
   yifp__4->SetBinError(64,19.5959);
   yifp__4->SetBinError(65,22.2036);
   yifp__4->SetBinError(66,29.189);
   yifp__4->SetBinError(67,28.8617);
   yifp__4->SetBinError(68,32.5269);
   yifp__4->SetBinError(69,36.2215);
   yifp__4->SetBinError(70,35.426);
   yifp__4->SetBinError(71,34.0147);
   yifp__4->SetBinError(72,33.8083);
   yifp__4->SetBinError(73,29.4109);
   yifp__4->SetBinError(74,31.7648);
   yifp__4->SetBinError(75,30.8707);
   yifp__4->SetBinError(76,25.1794);
   yifp__4->SetBinError(77,23.8537);
   yifp__4->SetBinError(78,21.0476);
   yifp__4->SetBinError(79,27.313);
   yifp__4->SetBinError(80,22.8692);
   yifp__4->SetBinError(81,21.7256);
   yifp__4->SetBinError(82,20.1246);
   yifp__4->SetBinError(83,20);
   yifp__4->SetBinError(84,18.9737);
   yifp__4->SetBinError(85,20.445);
   yifp__4->SetBinError(86,17.3205);
   yifp__4->SetBinError(87,18.8149);
   yifp__4->SetBinError(88,17.4069);
   yifp__4->SetBinError(89,13.5277);
   yifp__4->SetBinError(90,17.088);
   yifp__4->SetBinError(91,11.8322);
   yifp__4->SetBinError(92,11.1355);
   yifp__4->SetBinError(93,13.0384);
   yifp__4->SetBinError(94,9.38083);
   yifp__4->SetBinError(95,11);
   yifp__4->SetBinError(96,4.79583);
   yifp__4->SetBinError(97,3);
   yifp__4->SetBinError(98,2);
   yifp__4->SetEntries(19718);
   
   xpifp__6->SetBinContent(0,340);
   xpifp__6->SetBinContent(1,6);
   xpifp__6->SetBinContent(2,21);
   xpifp__6->SetBinContent(3,17);
   xpifp__6->SetBinContent(4,53);
   xpifp__6->SetBinContent(5,20);
   xpifp__6->SetBinContent(7,8);
   xpifp__6->SetBinContent(8,22);
   xpifp__6->SetBinContent(9,4);
   xpifp__6->SetBinContent(10,36);
   xpifp__6->SetBinContent(11,35);
   xpifp__6->SetBinContent(12,52);
   xpifp__6->SetBinContent(13,4);
   xpifp__6->SetBinContent(14,79);
   xpifp__6->SetBinContent(15,4);
   xpifp__6->SetBinContent(16,66);
   xpifp__6->SetBinContent(17,9);
   xpifp__6->SetBinContent(18,84);
   xpifp__6->SetBinContent(19,28);
   xpifp__6->SetBinContent(20,2);
   xpifp__6->SetBinContent(21,105);
   xpifp__6->SetBinContent(22,44);
   xpifp__6->SetBinContent(23,107);
   xpifp__6->SetBinContent(24,13);
   xpifp__6->SetBinContent(25,97);
   xpifp__6->SetBinContent(26,73);
   xpifp__6->SetBinContent(27,97);
   xpifp__6->SetBinContent(28,108);
   xpifp__6->SetBinContent(29,73);
   xpifp__6->SetBinContent(30,119);
   xpifp__6->SetBinContent(31,159);
   xpifp__6->SetBinContent(32,95);
   xpifp__6->SetBinContent(33,65);
   xpifp__6->SetBinContent(34,50);
   xpifp__6->SetBinContent(35,89);
   xpifp__6->SetBinContent(36,171);
   xpifp__6->SetBinContent(37,101);
   xpifp__6->SetBinContent(38,108);
   xpifp__6->SetBinContent(39,173);
   xpifp__6->SetBinContent(40,142);
   xpifp__6->SetBinContent(41,105);
   xpifp__6->SetBinContent(42,152);
   xpifp__6->SetBinContent(43,134);
   xpifp__6->SetBinContent(44,208);
   xpifp__6->SetBinContent(45,212);
   xpifp__6->SetBinContent(46,160);
   xpifp__6->SetBinContent(47,444);
   xpifp__6->SetBinContent(48,606);
   xpifp__6->SetBinContent(49,624);
   xpifp__6->SetBinContent(50,732);
   xpifp__6->SetBinContent(51,1010);
   xpifp__6->SetBinContent(52,863);
   xpifp__6->SetBinContent(53,1172);
   xpifp__6->SetBinContent(54,1159);
   xpifp__6->SetBinContent(55,1020);
   xpifp__6->SetBinContent(56,941);
   xpifp__6->SetBinContent(57,699);
   xpifp__6->SetBinContent(58,620);
   xpifp__6->SetBinContent(59,531);
   xpifp__6->SetBinContent(60,411);
   xpifp__6->SetBinContent(61,342);
   xpifp__6->SetBinContent(62,219);
   xpifp__6->SetBinContent(63,226);
   xpifp__6->SetBinContent(64,133);
   xpifp__6->SetBinContent(65,209);
   xpifp__6->SetBinContent(66,184);
   xpifp__6->SetBinContent(67,269);
   xpifp__6->SetBinContent(68,84);
   xpifp__6->SetBinContent(69,85);
   xpifp__6->SetBinContent(70,143);
   xpifp__6->SetBinContent(71,165);
   xpifp__6->SetBinContent(72,78);
   xpifp__6->SetBinContent(73,29);
   xpifp__6->SetBinContent(74,57);
   xpifp__6->SetBinContent(75,163);
   xpifp__6->SetBinContent(76,127);
   xpifp__6->SetBinContent(77,84);
   xpifp__6->SetBinContent(78,79);
   xpifp__6->SetBinContent(79,82);
   xpifp__6->SetBinContent(80,32);
   xpifp__6->SetBinContent(81,61);
   xpifp__6->SetBinContent(82,45);
   xpifp__6->SetBinContent(83,57);
   xpifp__6->SetBinContent(84,95);
   xpifp__6->SetBinContent(85,104);
   xpifp__6->SetBinContent(86,69);
   xpifp__6->SetBinContent(87,36);
   xpifp__6->SetBinContent(88,39);
   xpifp__6->SetBinContent(89,95);
   xpifp__6->SetBinContent(90,31);
   xpifp__6->SetBinContent(91,88);
   xpifp__6->SetBinContent(92,145);
   xpifp__6->SetBinContent(93,84);
   xpifp__6->SetBinContent(94,27);
   xpifp__6->SetBinContent(95,95);
   xpifp__6->SetBinContent(96,24);
   xpifp__6->SetBinContent(97,49);
   xpifp__6->SetBinContent(98,22);
   xpifp__6->SetBinContent(99,23);
   xpifp__6->SetBinContent(100,45);
   xpifp__6->SetBinContent(101,1012);
   xpifp__6->SetBinError(0,18.4391);
   xpifp__6->SetBinError(1,2.44949);
   xpifp__6->SetBinError(2,4.58258);
   xpifp__6->SetBinError(3,4.12311);
   xpifp__6->SetBinError(4,7.28011);
   xpifp__6->SetBinError(5,4.47214);
   xpifp__6->SetBinError(7,2.82843);
   xpifp__6->SetBinError(8,4.69042);
   xpifp__6->SetBinError(9,2);
   xpifp__6->SetBinError(10,6);
   xpifp__6->SetBinError(11,5.91608);
   xpifp__6->SetBinError(12,7.2111);
   xpifp__6->SetBinError(13,2);
   xpifp__6->SetBinError(14,8.88819);
   xpifp__6->SetBinError(15,2);
   xpifp__6->SetBinError(16,8.12404);
   xpifp__6->SetBinError(17,3);
   xpifp__6->SetBinError(18,9.16515);
   xpifp__6->SetBinError(19,5.2915);
   xpifp__6->SetBinError(20,1.41421);
   xpifp__6->SetBinError(21,10.247);
   xpifp__6->SetBinError(22,6.63325);
   xpifp__6->SetBinError(23,10.3441);
   xpifp__6->SetBinError(24,3.60555);
   xpifp__6->SetBinError(25,9.84886);
   xpifp__6->SetBinError(26,8.544);
   xpifp__6->SetBinError(27,9.84886);
   xpifp__6->SetBinError(28,10.3923);
   xpifp__6->SetBinError(29,8.544);
   xpifp__6->SetBinError(30,10.9087);
   xpifp__6->SetBinError(31,12.6095);
   xpifp__6->SetBinError(32,9.74679);
   xpifp__6->SetBinError(33,8.06226);
   xpifp__6->SetBinError(34,7.07107);
   xpifp__6->SetBinError(35,9.43398);
   xpifp__6->SetBinError(36,13.0767);
   xpifp__6->SetBinError(37,10.0499);
   xpifp__6->SetBinError(38,10.3923);
   xpifp__6->SetBinError(39,13.1529);
   xpifp__6->SetBinError(40,11.9164);
   xpifp__6->SetBinError(41,10.247);
   xpifp__6->SetBinError(42,12.3288);
   xpifp__6->SetBinError(43,11.5758);
   xpifp__6->SetBinError(44,14.4222);
   xpifp__6->SetBinError(45,14.5602);
   xpifp__6->SetBinError(46,12.6491);
   xpifp__6->SetBinError(47,21.0713);
   xpifp__6->SetBinError(48,24.6171);
   xpifp__6->SetBinError(49,24.98);
   xpifp__6->SetBinError(50,27.0555);
   xpifp__6->SetBinError(51,31.7805);
   xpifp__6->SetBinError(52,29.3769);
   xpifp__6->SetBinError(53,34.2345);
   xpifp__6->SetBinError(54,34.0441);
   xpifp__6->SetBinError(55,31.9374);
   xpifp__6->SetBinError(56,30.6757);
   xpifp__6->SetBinError(57,26.4386);
   xpifp__6->SetBinError(58,24.8998);
   xpifp__6->SetBinError(59,23.0434);
   xpifp__6->SetBinError(60,20.2731);
   xpifp__6->SetBinError(61,18.4932);
   xpifp__6->SetBinError(62,14.7986);
   xpifp__6->SetBinError(63,15.0333);
   xpifp__6->SetBinError(64,11.5326);
   xpifp__6->SetBinError(65,14.4568);
   xpifp__6->SetBinError(66,13.5647);
   xpifp__6->SetBinError(67,16.4012);
   xpifp__6->SetBinError(68,9.16515);
   xpifp__6->SetBinError(69,9.21954);
   xpifp__6->SetBinError(70,11.9583);
   xpifp__6->SetBinError(71,12.8452);
   xpifp__6->SetBinError(72,8.83176);
   xpifp__6->SetBinError(73,5.38516);
   xpifp__6->SetBinError(74,7.54983);
   xpifp__6->SetBinError(75,12.7671);
   xpifp__6->SetBinError(76,11.2694);
   xpifp__6->SetBinError(77,9.16515);
   xpifp__6->SetBinError(78,8.88819);
   xpifp__6->SetBinError(79,9.05539);
   xpifp__6->SetBinError(80,5.65685);
   xpifp__6->SetBinError(81,7.81025);
   xpifp__6->SetBinError(82,6.7082);
   xpifp__6->SetBinError(83,7.54983);
   xpifp__6->SetBinError(84,9.74679);
   xpifp__6->SetBinError(85,10.198);
   xpifp__6->SetBinError(86,8.30662);
   xpifp__6->SetBinError(87,6);
   xpifp__6->SetBinError(88,6.245);
   xpifp__6->SetBinError(89,9.74679);
   xpifp__6->SetBinError(90,5.56776);
   xpifp__6->SetBinError(91,9.38083);
   xpifp__6->SetBinError(92,12.0416);
   xpifp__6->SetBinError(93,9.16515);
   xpifp__6->SetBinError(94,5.19615);
   xpifp__6->SetBinError(95,9.74679);
   xpifp__6->SetBinError(96,4.89898);
   xpifp__6->SetBinError(97,7);
   xpifp__6->SetBinError(98,4.69042);
   xpifp__6->SetBinError(99,4.79583);
   xpifp__6->SetBinError(100,6.7082);
   xpifp__6->SetBinError(101,31.8119);
   xpifp__6->SetEntries(19718);
   
   ypifp__8->SetBinContent(0,799);
   ypifp__8->SetBinContent(1,41);
   ypifp__8->SetBinContent(3,18);
   ypifp__8->SetBinContent(4,35);
   ypifp__8->SetBinContent(5,61);
   ypifp__8->SetBinContent(6,27);
   ypifp__8->SetBinContent(7,21);
   ypifp__8->SetBinContent(8,30);
   ypifp__8->SetBinContent(9,2);
   ypifp__8->SetBinContent(10,71);
   ypifp__8->SetBinContent(11,44);
   ypifp__8->SetBinContent(12,43);
   ypifp__8->SetBinContent(13,44);
   ypifp__8->SetBinContent(14,94);
   ypifp__8->SetBinContent(15,61);
   ypifp__8->SetBinContent(16,89);
   ypifp__8->SetBinContent(17,81);
   ypifp__8->SetBinContent(18,122);
   ypifp__8->SetBinContent(19,102);
   ypifp__8->SetBinContent(20,109);
   ypifp__8->SetBinContent(21,143);
   ypifp__8->SetBinContent(22,63);
   ypifp__8->SetBinContent(23,45);
   ypifp__8->SetBinContent(24,115);
   ypifp__8->SetBinContent(25,113);
   ypifp__8->SetBinContent(26,124);
   ypifp__8->SetBinContent(27,162);
   ypifp__8->SetBinContent(28,247);
   ypifp__8->SetBinContent(29,114);
   ypifp__8->SetBinContent(30,231);
   ypifp__8->SetBinContent(31,300);
   ypifp__8->SetBinContent(32,353);
   ypifp__8->SetBinContent(33,454);
   ypifp__8->SetBinContent(34,440);
   ypifp__8->SetBinContent(35,559);
   ypifp__8->SetBinContent(36,769);
   ypifp__8->SetBinContent(37,903);
   ypifp__8->SetBinContent(38,1170);
   ypifp__8->SetBinContent(39,980);
   ypifp__8->SetBinContent(40,955);
   ypifp__8->SetBinContent(41,807);
   ypifp__8->SetBinContent(42,760);
   ypifp__8->SetBinContent(43,740);
   ypifp__8->SetBinContent(44,497);
   ypifp__8->SetBinContent(45,521);
   ypifp__8->SetBinContent(46,468);
   ypifp__8->SetBinContent(47,537);
   ypifp__8->SetBinContent(48,509);
   ypifp__8->SetBinContent(49,409);
   ypifp__8->SetBinContent(50,331);
   ypifp__8->SetBinContent(51,331);
   ypifp__8->SetBinContent(52,240);
   ypifp__8->SetBinContent(53,269);
   ypifp__8->SetBinContent(54,119);
   ypifp__8->SetBinContent(55,169);
   ypifp__8->SetBinContent(56,143);
   ypifp__8->SetBinContent(57,179);
   ypifp__8->SetBinContent(58,104);
   ypifp__8->SetBinContent(59,128);
   ypifp__8->SetBinContent(60,197);
   ypifp__8->SetBinContent(61,144);
   ypifp__8->SetBinContent(62,58);
   ypifp__8->SetBinContent(63,174);
   ypifp__8->SetBinContent(64,81);
   ypifp__8->SetBinContent(65,90);
   ypifp__8->SetBinContent(66,61);
   ypifp__8->SetBinContent(67,55);
   ypifp__8->SetBinContent(68,71);
   ypifp__8->SetBinContent(69,72);
   ypifp__8->SetBinContent(70,24);
   ypifp__8->SetBinContent(71,74);
   ypifp__8->SetBinContent(72,48);
   ypifp__8->SetBinContent(73,92);
   ypifp__8->SetBinContent(74,26);
   ypifp__8->SetBinContent(75,14);
   ypifp__8->SetBinContent(76,33);
   ypifp__8->SetBinContent(77,32);
   ypifp__8->SetBinContent(78,30);
   ypifp__8->SetBinContent(79,55);
   ypifp__8->SetBinContent(80,58);
   ypifp__8->SetBinContent(81,41);
   ypifp__8->SetBinContent(82,12);
   ypifp__8->SetBinContent(83,18);
   ypifp__8->SetBinContent(84,57);
   ypifp__8->SetBinContent(85,8);
   ypifp__8->SetBinContent(86,42);
   ypifp__8->SetBinContent(87,17);
   ypifp__8->SetBinContent(88,62);
   ypifp__8->SetBinContent(89,29);
   ypifp__8->SetBinContent(90,9);
   ypifp__8->SetBinContent(91,41);
   ypifp__8->SetBinContent(92,8);
   ypifp__8->SetBinContent(93,6);
   ypifp__8->SetBinContent(96,2);
   ypifp__8->SetBinContent(97,9);
   ypifp__8->SetBinContent(98,4);
   ypifp__8->SetBinContent(99,10);
   ypifp__8->SetBinContent(100,4);
   ypifp__8->SetBinContent(101,455);
   ypifp__8->SetBinError(0,28.2666);
   ypifp__8->SetBinError(1,6.40312);
   ypifp__8->SetBinError(3,4.24264);
   ypifp__8->SetBinError(4,5.91608);
   ypifp__8->SetBinError(5,7.81025);
   ypifp__8->SetBinError(6,5.19615);
   ypifp__8->SetBinError(7,4.58258);
   ypifp__8->SetBinError(8,5.47723);
   ypifp__8->SetBinError(9,1.41421);
   ypifp__8->SetBinError(10,8.42615);
   ypifp__8->SetBinError(11,6.63325);
   ypifp__8->SetBinError(12,6.55744);
   ypifp__8->SetBinError(13,6.63325);
   ypifp__8->SetBinError(14,9.69536);
   ypifp__8->SetBinError(15,7.81025);
   ypifp__8->SetBinError(16,9.43398);
   ypifp__8->SetBinError(17,9);
   ypifp__8->SetBinError(18,11.0454);
   ypifp__8->SetBinError(19,10.0995);
   ypifp__8->SetBinError(20,10.4403);
   ypifp__8->SetBinError(21,11.9583);
   ypifp__8->SetBinError(22,7.93725);
   ypifp__8->SetBinError(23,6.7082);
   ypifp__8->SetBinError(24,10.7238);
   ypifp__8->SetBinError(25,10.6301);
   ypifp__8->SetBinError(26,11.1355);
   ypifp__8->SetBinError(27,12.7279);
   ypifp__8->SetBinError(28,15.7162);
   ypifp__8->SetBinError(29,10.6771);
   ypifp__8->SetBinError(30,15.1987);
   ypifp__8->SetBinError(31,17.3205);
   ypifp__8->SetBinError(32,18.7883);
   ypifp__8->SetBinError(33,21.3073);
   ypifp__8->SetBinError(34,20.9762);
   ypifp__8->SetBinError(35,23.6432);
   ypifp__8->SetBinError(36,27.7308);
   ypifp__8->SetBinError(37,30.05);
   ypifp__8->SetBinError(38,34.2053);
   ypifp__8->SetBinError(39,31.305);
   ypifp__8->SetBinError(40,30.9031);
   ypifp__8->SetBinError(41,28.4077);
   ypifp__8->SetBinError(42,27.5681);
   ypifp__8->SetBinError(43,27.2029);
   ypifp__8->SetBinError(44,22.2935);
   ypifp__8->SetBinError(45,22.8254);
   ypifp__8->SetBinError(46,21.6333);
   ypifp__8->SetBinError(47,23.1733);
   ypifp__8->SetBinError(48,22.561);
   ypifp__8->SetBinError(49,20.2237);
   ypifp__8->SetBinError(50,18.1934);
   ypifp__8->SetBinError(51,18.1934);
   ypifp__8->SetBinError(52,15.4919);
   ypifp__8->SetBinError(53,16.4012);
   ypifp__8->SetBinError(54,10.9087);
   ypifp__8->SetBinError(55,13);
   ypifp__8->SetBinError(56,11.9583);
   ypifp__8->SetBinError(57,13.3791);
   ypifp__8->SetBinError(58,10.198);
   ypifp__8->SetBinError(59,11.3137);
   ypifp__8->SetBinError(60,14.0357);
   ypifp__8->SetBinError(61,12);
   ypifp__8->SetBinError(62,7.61577);
   ypifp__8->SetBinError(63,13.1909);
   ypifp__8->SetBinError(64,9);
   ypifp__8->SetBinError(65,9.48683);
   ypifp__8->SetBinError(66,7.81025);
   ypifp__8->SetBinError(67,7.4162);
   ypifp__8->SetBinError(68,8.42615);
   ypifp__8->SetBinError(69,8.48528);
   ypifp__8->SetBinError(70,4.89898);
   ypifp__8->SetBinError(71,8.60233);
   ypifp__8->SetBinError(72,6.9282);
   ypifp__8->SetBinError(73,9.59166);
   ypifp__8->SetBinError(74,5.09902);
   ypifp__8->SetBinError(75,3.74166);
   ypifp__8->SetBinError(76,5.74456);
   ypifp__8->SetBinError(77,5.65685);
   ypifp__8->SetBinError(78,5.47723);
   ypifp__8->SetBinError(79,7.4162);
   ypifp__8->SetBinError(80,7.61577);
   ypifp__8->SetBinError(81,6.40312);
   ypifp__8->SetBinError(82,3.4641);
   ypifp__8->SetBinError(83,4.24264);
   ypifp__8->SetBinError(84,7.54983);
   ypifp__8->SetBinError(85,2.82843);
   ypifp__8->SetBinError(86,6.48074);
   ypifp__8->SetBinError(87,4.12311);
   ypifp__8->SetBinError(88,7.87401);
   ypifp__8->SetBinError(89,5.38516);
   ypifp__8->SetBinError(90,3);
   ypifp__8->SetBinError(91,6.40312);
   ypifp__8->SetBinError(92,2.82843);
   ypifp__8->SetBinError(93,2.44949);
   ypifp__8->SetBinError(96,1.41421);
   ypifp__8->SetBinError(97,3);
   ypifp__8->SetBinError(98,2);
   ypifp__8->SetBinError(99,3.16228);
   ypifp__8->SetBinError(100,2);
   ypifp__8->SetBinError(101,21.3307);
   ypifp__8->SetEntries(19718);
 
 //At PiM1 Tar
 
   xtarg__1->SetBinContent(0,140);
   xtarg__1->SetBinContent(1,4);
   xtarg__1->SetBinContent(2,8);
   xtarg__1->SetBinContent(3,5);
   xtarg__1->SetBinContent(4,4);
   xtarg__1->SetBinContent(5,6);
   xtarg__1->SetBinContent(7,1);
   xtarg__1->SetBinContent(9,4);
   xtarg__1->SetBinContent(11,1);
   xtarg__1->SetBinContent(12,4);
   xtarg__1->SetBinContent(13,2);
   xtarg__1->SetBinContent(14,6);
   xtarg__1->SetBinContent(15,2);
   xtarg__1->SetBinContent(16,3);
   xtarg__1->SetBinContent(17,4);
   xtarg__1->SetBinContent(19,4);
   xtarg__1->SetBinContent(20,14);
   xtarg__1->SetBinContent(21,1);
   xtarg__1->SetBinContent(22,2);
   xtarg__1->SetBinContent(24,6);
   xtarg__1->SetBinContent(25,10);
   xtarg__1->SetBinContent(27,4);
   xtarg__1->SetBinContent(28,8);
   xtarg__1->SetBinContent(30,16);
   xtarg__1->SetBinContent(31,7);
   xtarg__1->SetBinContent(32,5);
   xtarg__1->SetBinContent(33,7);
   xtarg__1->SetBinContent(34,8);
   xtarg__1->SetBinContent(35,23);
   xtarg__1->SetBinContent(36,3);
   xtarg__1->SetBinContent(37,11);
   xtarg__1->SetBinContent(38,47);
   xtarg__1->SetBinContent(39,58);
   xtarg__1->SetBinContent(40,9);
   xtarg__1->SetBinContent(41,15);
   xtarg__1->SetBinContent(42,67);
   xtarg__1->SetBinContent(43,14);
   xtarg__1->SetBinContent(44,69);
   xtarg__1->SetBinContent(45,31);
   xtarg__1->SetBinContent(46,39);
   xtarg__1->SetBinContent(47,63);
   xtarg__1->SetBinContent(48,38);
   xtarg__1->SetBinContent(49,66);
   xtarg__1->SetBinContent(50,131);
   xtarg__1->SetBinContent(51,85);
   xtarg__1->SetBinContent(52,64);
   xtarg__1->SetBinContent(53,78);
   xtarg__1->SetBinContent(54,128);
   xtarg__1->SetBinContent(55,123);
   xtarg__1->SetBinContent(56,151);
   xtarg__1->SetBinContent(57,173);
   xtarg__1->SetBinContent(58,182);
   xtarg__1->SetBinContent(59,221);
   xtarg__1->SetBinContent(60,260);
   xtarg__1->SetBinContent(61,268);
   xtarg__1->SetBinContent(62,261);
   xtarg__1->SetBinContent(63,398);
   xtarg__1->SetBinContent(64,316);
   xtarg__1->SetBinContent(65,291);
   xtarg__1->SetBinContent(66,474);
   xtarg__1->SetBinContent(67,507);
   xtarg__1->SetBinContent(68,477);
   xtarg__1->SetBinContent(69,486);
   xtarg__1->SetBinContent(70,672);
   xtarg__1->SetBinContent(71,563);
   xtarg__1->SetBinContent(72,588);
   xtarg__1->SetBinContent(73,442);
   xtarg__1->SetBinContent(74,567);
   xtarg__1->SetBinContent(75,582);
   xtarg__1->SetBinContent(76,597);
   xtarg__1->SetBinContent(77,551);
   xtarg__1->SetBinContent(78,658);
   xtarg__1->SetBinContent(79,615);
   xtarg__1->SetBinContent(80,542);
   xtarg__1->SetBinContent(81,703);
   xtarg__1->SetBinContent(82,496);
   xtarg__1->SetBinContent(83,527);
   xtarg__1->SetBinContent(84,609);
   xtarg__1->SetBinContent(85,427);
   xtarg__1->SetBinContent(86,552);
   xtarg__1->SetBinContent(87,251);
   xtarg__1->SetBinContent(88,338);
   xtarg__1->SetBinContent(89,328);
   xtarg__1->SetBinContent(90,273);
   xtarg__1->SetBinContent(91,214);
   xtarg__1->SetBinContent(92,283);
   xtarg__1->SetBinContent(93,309);
   xtarg__1->SetBinContent(94,232);
   xtarg__1->SetBinContent(95,177);
   xtarg__1->SetBinContent(96,246);
   xtarg__1->SetBinContent(97,143);
   xtarg__1->SetBinContent(98,153);
   xtarg__1->SetBinContent(99,143);
   xtarg__1->SetBinContent(100,61);
   xtarg__1->SetBinContent(101,53);
   xtarg__1->SetBinContent(102,100);
   xtarg__1->SetBinContent(103,104);
   xtarg__1->SetBinContent(104,117);
   xtarg__1->SetBinContent(105,37);
   xtarg__1->SetBinContent(106,39);
   xtarg__1->SetBinContent(107,22);
   xtarg__1->SetBinContent(108,63);
   xtarg__1->SetBinContent(109,40);
   xtarg__1->SetBinContent(110,27);
   xtarg__1->SetBinContent(111,56);
   xtarg__1->SetBinContent(112,21);
   xtarg__1->SetBinContent(113,41);
   xtarg__1->SetBinContent(114,15);
   xtarg__1->SetBinContent(115,14);
   xtarg__1->SetBinContent(116,35);
   xtarg__1->SetBinContent(117,23);
   xtarg__1->SetBinContent(118,14);
   xtarg__1->SetBinContent(119,13);
   xtarg__1->SetBinContent(121,18);
   xtarg__1->SetBinContent(122,8);
   xtarg__1->SetBinContent(123,21);
   xtarg__1->SetBinContent(124,14);
   xtarg__1->SetBinContent(125,4);
   xtarg__1->SetBinContent(126,6);
   xtarg__1->SetBinContent(127,4);
   xtarg__1->SetBinContent(129,12);
   xtarg__1->SetBinContent(130,7);
   xtarg__1->SetBinContent(133,9);
   xtarg__1->SetBinContent(137,2);
   xtarg__1->SetBinContent(139,1);
   xtarg__1->SetBinContent(148,5);
   xtarg__1->SetBinContent(150,3);
   xtarg__1->SetBinContent(151,15);
   xtarg__1->SetBinError(0,11.8322);
   xtarg__1->SetBinError(1,2);
   xtarg__1->SetBinError(2,2.82843);
   xtarg__1->SetBinError(3,2.23607);
   xtarg__1->SetBinError(4,2);
   xtarg__1->SetBinError(5,2.44949);
   xtarg__1->SetBinError(7,1);
   xtarg__1->SetBinError(9,2);
   xtarg__1->SetBinError(11,1);
   xtarg__1->SetBinError(12,2);
   xtarg__1->SetBinError(13,1.41421);
   xtarg__1->SetBinError(14,2.44949);
   xtarg__1->SetBinError(15,1.41421);
   xtarg__1->SetBinError(16,1.73205);
   xtarg__1->SetBinError(17,2);
   xtarg__1->SetBinError(19,2);
   xtarg__1->SetBinError(20,3.74166);
   xtarg__1->SetBinError(21,1);
   xtarg__1->SetBinError(22,1.41421);
   xtarg__1->SetBinError(24,2.44949);
   xtarg__1->SetBinError(25,3.16228);
   xtarg__1->SetBinError(27,2);
   xtarg__1->SetBinError(28,2.82843);
   xtarg__1->SetBinError(30,4);
   xtarg__1->SetBinError(31,2.64575);
   xtarg__1->SetBinError(32,2.23607);
   xtarg__1->SetBinError(33,2.64575);
   xtarg__1->SetBinError(34,2.82843);
   xtarg__1->SetBinError(35,4.79583);
   xtarg__1->SetBinError(36,1.73205);
   xtarg__1->SetBinError(37,3.31662);
   xtarg__1->SetBinError(38,6.85565);
   xtarg__1->SetBinError(39,7.61577);
   xtarg__1->SetBinError(40,3);
   xtarg__1->SetBinError(41,3.87298);
   xtarg__1->SetBinError(42,8.18535);
   xtarg__1->SetBinError(43,3.74166);
   xtarg__1->SetBinError(44,8.30662);
   xtarg__1->SetBinError(45,5.56776);
   xtarg__1->SetBinError(46,6.245);
   xtarg__1->SetBinError(47,7.93725);
   xtarg__1->SetBinError(48,6.16441);
   xtarg__1->SetBinError(49,8.12404);
   xtarg__1->SetBinError(50,11.4455);
   xtarg__1->SetBinError(51,9.21954);
   xtarg__1->SetBinError(52,8);
   xtarg__1->SetBinError(53,8.83176);
   xtarg__1->SetBinError(54,11.3137);
   xtarg__1->SetBinError(55,11.0905);
   xtarg__1->SetBinError(56,12.2882);
   xtarg__1->SetBinError(57,13.1529);
   xtarg__1->SetBinError(58,13.4907);
   xtarg__1->SetBinError(59,14.8661);
   xtarg__1->SetBinError(60,16.1245);
   xtarg__1->SetBinError(61,16.3707);
   xtarg__1->SetBinError(62,16.1555);
   xtarg__1->SetBinError(63,19.9499);
   xtarg__1->SetBinError(64,17.7764);
   xtarg__1->SetBinError(65,17.0587);
   xtarg__1->SetBinError(66,21.7715);
   xtarg__1->SetBinError(67,22.5167);
   xtarg__1->SetBinError(68,21.8403);
   xtarg__1->SetBinError(69,22.0454);
   xtarg__1->SetBinError(70,25.923);
   xtarg__1->SetBinError(71,23.7276);
   xtarg__1->SetBinError(72,24.2487);
   xtarg__1->SetBinError(73,21.0238);
   xtarg__1->SetBinError(74,23.8118);
   xtarg__1->SetBinError(75,24.1247);
   xtarg__1->SetBinError(76,24.4336);
   xtarg__1->SetBinError(77,23.4734);
   xtarg__1->SetBinError(78,25.6515);
   xtarg__1->SetBinError(79,24.7992);
   xtarg__1->SetBinError(80,23.2809);
   xtarg__1->SetBinError(81,26.5141);
   xtarg__1->SetBinError(82,22.2711);
   xtarg__1->SetBinError(83,22.9565);
   xtarg__1->SetBinError(84,24.6779);
   xtarg__1->SetBinError(85,20.664);
   xtarg__1->SetBinError(86,23.4947);
   xtarg__1->SetBinError(87,15.843);
   xtarg__1->SetBinError(88,18.3848);
   xtarg__1->SetBinError(89,18.1108);
   xtarg__1->SetBinError(90,16.5227);
   xtarg__1->SetBinError(91,14.6287);
   xtarg__1->SetBinError(92,16.8226);
   xtarg__1->SetBinError(93,17.5784);
   xtarg__1->SetBinError(94,15.2315);
   xtarg__1->SetBinError(95,13.3041);
   xtarg__1->SetBinError(96,15.6844);
   xtarg__1->SetBinError(97,11.9583);
   xtarg__1->SetBinError(98,12.3693);
   xtarg__1->SetBinError(99,11.9583);
   xtarg__1->SetBinError(100,7.81025);
   xtarg__1->SetBinError(101,7.28011);
   xtarg__1->SetBinError(102,10);
   xtarg__1->SetBinError(103,10.198);
   xtarg__1->SetBinError(104,10.8167);
   xtarg__1->SetBinError(105,6.08276);
   xtarg__1->SetBinError(106,6.245);
   xtarg__1->SetBinError(107,4.69042);
   xtarg__1->SetBinError(108,7.93725);
   xtarg__1->SetBinError(109,6.32456);
   xtarg__1->SetBinError(110,5.19615);
   xtarg__1->SetBinError(111,7.48331);
   xtarg__1->SetBinError(112,4.58258);
   xtarg__1->SetBinError(113,6.40312);
   xtarg__1->SetBinError(114,3.87298);
   xtarg__1->SetBinError(115,3.74166);
   xtarg__1->SetBinError(116,5.91608);
   xtarg__1->SetBinError(117,4.79583);
   xtarg__1->SetBinError(118,3.74166);
   xtarg__1->SetBinError(119,3.60555);
   xtarg__1->SetBinError(121,4.24264);
   xtarg__1->SetBinError(122,2.82843);
   xtarg__1->SetBinError(123,4.58258);
   xtarg__1->SetBinError(124,3.74166);
   xtarg__1->SetBinError(125,2);
   xtarg__1->SetBinError(126,2.44949);
   xtarg__1->SetBinError(127,2);
   xtarg__1->SetBinError(129,3.4641);
   xtarg__1->SetBinError(130,2.64575);
   xtarg__1->SetBinError(133,3);
   xtarg__1->SetBinError(137,1.41421);
   xtarg__1->SetBinError(139,1);
   xtarg__1->SetBinError(148,2.23607);
   xtarg__1->SetBinError(150,1.73205);
   xtarg__1->SetBinError(151,3.87298);
   xtarg__1->SetEntries(19718);
   
   xp__5->SetBinContent(0,417);
   xp__5->SetBinContent(2,10);
   xp__5->SetBinContent(3,23);
   xp__5->SetBinContent(4,13);
   xp__5->SetBinContent(5,19);
   xp__5->SetBinContent(6,14);
   xp__5->SetBinContent(7,19);
   xp__5->SetBinContent(8,38);
   xp__5->SetBinContent(9,4);
   xp__5->SetBinContent(10,8);
   xp__5->SetBinContent(11,33);
   xp__5->SetBinContent(12,21);
   xp__5->SetBinContent(13,56);
   xp__5->SetBinContent(14,85);
   xp__5->SetBinContent(15,53);
   xp__5->SetBinContent(16,80);
   xp__5->SetBinContent(17,44);
   xp__5->SetBinContent(18,119);
   xp__5->SetBinContent(19,90);
   xp__5->SetBinContent(20,97);
   xp__5->SetBinContent(21,132);
   xp__5->SetBinContent(22,133);
   xp__5->SetBinContent(23,224);
   xp__5->SetBinContent(24,156);
   xp__5->SetBinContent(25,164);
   xp__5->SetBinContent(26,132);
   xp__5->SetBinContent(27,142);
   xp__5->SetBinContent(28,226);
   xp__5->SetBinContent(29,208);
   xp__5->SetBinContent(30,136);
   xp__5->SetBinContent(31,196);
   xp__5->SetBinContent(32,237);
   xp__5->SetBinContent(33,254);
   xp__5->SetBinContent(34,245);
   xp__5->SetBinContent(35,387);
   xp__5->SetBinContent(36,287);
   xp__5->SetBinContent(37,226);
   xp__5->SetBinContent(38,288);
   xp__5->SetBinContent(39,319);
   xp__5->SetBinContent(40,425);
   xp__5->SetBinContent(41,361);
   xp__5->SetBinContent(42,195);
   xp__5->SetBinContent(43,256);
   xp__5->SetBinContent(44,397);
   xp__5->SetBinContent(45,298);
   xp__5->SetBinContent(46,313);
   xp__5->SetBinContent(47,344);
   xp__5->SetBinContent(48,305);
   xp__5->SetBinContent(49,450);
   xp__5->SetBinContent(50,498);
   xp__5->SetBinContent(51,271);
   xp__5->SetBinContent(52,432);
   xp__5->SetBinContent(53,502);
   xp__5->SetBinContent(54,350);
   xp__5->SetBinContent(55,423);
   xp__5->SetBinContent(56,316);
   xp__5->SetBinContent(57,336);
   xp__5->SetBinContent(58,389);
   xp__5->SetBinContent(59,463);
   xp__5->SetBinContent(60,403);
   xp__5->SetBinContent(61,285);
   xp__5->SetBinContent(62,383);
   xp__5->SetBinContent(63,343);
   xp__5->SetBinContent(64,294);
   xp__5->SetBinContent(65,311);
   xp__5->SetBinContent(66,337);
   xp__5->SetBinContent(67,266);
   xp__5->SetBinContent(68,460);
   xp__5->SetBinContent(69,305);
   xp__5->SetBinContent(70,227);
   xp__5->SetBinContent(71,218);
   xp__5->SetBinContent(72,287);
   xp__5->SetBinContent(73,183);
   xp__5->SetBinContent(74,249);
   xp__5->SetBinContent(75,185);
   xp__5->SetBinContent(76,230);
   xp__5->SetBinContent(77,225);
   xp__5->SetBinContent(78,255);
   xp__5->SetBinContent(79,175);
   xp__5->SetBinContent(80,193);
   xp__5->SetBinContent(81,156);
   xp__5->SetBinContent(82,191);
   xp__5->SetBinContent(83,153);
   xp__5->SetBinContent(84,77);
   xp__5->SetBinContent(85,113);
   xp__5->SetBinContent(86,62);
   xp__5->SetBinContent(87,122);
   xp__5->SetBinContent(88,76);
   xp__5->SetBinContent(89,36);
   xp__5->SetBinContent(90,17);
   xp__5->SetBinContent(91,40);
   xp__5->SetBinContent(92,15);
   xp__5->SetBinContent(93,10);
   xp__5->SetBinContent(94,16);
   xp__5->SetBinContent(95,7);
   xp__5->SetBinContent(98,2);
   xp__5->SetBinContent(100,11);
   xp__5->SetBinContent(101,141);
   xp__5->SetBinError(0,20.4206);
   xp__5->SetBinError(2,3.16228);
   xp__5->SetBinError(3,4.79583);
   xp__5->SetBinError(4,3.60555);
   xp__5->SetBinError(5,4.3589);
   xp__5->SetBinError(6,3.74166);
   xp__5->SetBinError(7,4.3589);
   xp__5->SetBinError(8,6.16441);
   xp__5->SetBinError(9,2);
   xp__5->SetBinError(10,2.82843);
   xp__5->SetBinError(11,5.74456);
   xp__5->SetBinError(12,4.58258);
   xp__5->SetBinError(13,7.48331);
   xp__5->SetBinError(14,9.21954);
   xp__5->SetBinError(15,7.28011);
   xp__5->SetBinError(16,8.94427);
   xp__5->SetBinError(17,6.63325);
   xp__5->SetBinError(18,10.9087);
   xp__5->SetBinError(19,9.48683);
   xp__5->SetBinError(20,9.84886);
   xp__5->SetBinError(21,11.4891);
   xp__5->SetBinError(22,11.5326);
   xp__5->SetBinError(23,14.9666);
   xp__5->SetBinError(24,12.49);
   xp__5->SetBinError(25,12.8062);
   xp__5->SetBinError(26,11.4891);
   xp__5->SetBinError(27,11.9164);
   xp__5->SetBinError(28,15.0333);
   xp__5->SetBinError(29,14.4222);
   xp__5->SetBinError(30,11.6619);
   xp__5->SetBinError(31,14);
   xp__5->SetBinError(32,15.3948);
   xp__5->SetBinError(33,15.9374);
   xp__5->SetBinError(34,15.6525);
   xp__5->SetBinError(35,19.6723);
   xp__5->SetBinError(36,16.9411);
   xp__5->SetBinError(37,15.0333);
   xp__5->SetBinError(38,16.9706);
   xp__5->SetBinError(39,17.8606);
   xp__5->SetBinError(40,20.6155);
   xp__5->SetBinError(41,19);
   xp__5->SetBinError(42,13.9642);
   xp__5->SetBinError(43,16);
   xp__5->SetBinError(44,19.9249);
   xp__5->SetBinError(45,17.2627);
   xp__5->SetBinError(46,17.6918);
   xp__5->SetBinError(47,18.5472);
   xp__5->SetBinError(48,17.4642);
   xp__5->SetBinError(49,21.2132);
   xp__5->SetBinError(50,22.3159);
   xp__5->SetBinError(51,16.4621);
   xp__5->SetBinError(52,20.7846);
   xp__5->SetBinError(53,22.4054);
   xp__5->SetBinError(54,18.7083);
   xp__5->SetBinError(55,20.567);
   xp__5->SetBinError(56,17.7764);
   xp__5->SetBinError(57,18.3303);
   xp__5->SetBinError(58,19.7231);
   xp__5->SetBinError(59,21.5174);
   xp__5->SetBinError(60,20.0749);
   xp__5->SetBinError(61,16.8819);
   xp__5->SetBinError(62,19.5704);
   xp__5->SetBinError(63,18.5203);
   xp__5->SetBinError(64,17.1464);
   xp__5->SetBinError(65,17.6352);
   xp__5->SetBinError(66,18.3576);
   xp__5->SetBinError(67,16.3095);
   xp__5->SetBinError(68,21.4476);
   xp__5->SetBinError(69,17.4642);
   xp__5->SetBinError(70,15.0665);
   xp__5->SetBinError(71,14.7648);
   xp__5->SetBinError(72,16.9411);
   xp__5->SetBinError(73,13.5277);
   xp__5->SetBinError(74,15.7797);
   xp__5->SetBinError(75,13.6015);
   xp__5->SetBinError(76,15.1658);
   xp__5->SetBinError(77,15);
   xp__5->SetBinError(78,15.9687);
   xp__5->SetBinError(79,13.2288);
   xp__5->SetBinError(80,13.8924);
   xp__5->SetBinError(81,12.49);
   xp__5->SetBinError(82,13.8203);
   xp__5->SetBinError(83,12.3693);
   xp__5->SetBinError(84,8.77496);
   xp__5->SetBinError(85,10.6301);
   xp__5->SetBinError(86,7.87401);
   xp__5->SetBinError(87,11.0454);
   xp__5->SetBinError(88,8.7178);
   xp__5->SetBinError(89,6);
   xp__5->SetBinError(90,4.12311);
   xp__5->SetBinError(91,6.32456);
   xp__5->SetBinError(92,3.87298);
   xp__5->SetBinError(93,3.16228);
   xp__5->SetBinError(94,4);
   xp__5->SetBinError(95,2.64575);
   xp__5->SetBinError(98,1.41421);
   xp__5->SetBinError(100,3.31662);
   xp__5->SetBinError(101,11.8743);
   xp__5->SetEntries(19718);
 
   ytarg__3->SetBinContent(0,45);
   ytarg__3->SetBinContent(3,1);
   ytarg__3->SetBinContent(5,1);
   ytarg__3->SetBinContent(6,1);
   ytarg__3->SetBinContent(7,1);
   ytarg__3->SetBinContent(8,2);
   ytarg__3->SetBinContent(9,7);
   ytarg__3->SetBinContent(11,1);
   ytarg__3->SetBinContent(12,2);
   ytarg__3->SetBinContent(13,2);
   ytarg__3->SetBinContent(14,1);
   ytarg__3->SetBinContent(15,3);
   ytarg__3->SetBinContent(16,2);
   ytarg__3->SetBinContent(17,11);
   ytarg__3->SetBinContent(18,4);
   ytarg__3->SetBinContent(19,10);
   ytarg__3->SetBinContent(20,22);
   ytarg__3->SetBinContent(21,7);
   ytarg__3->SetBinContent(22,27);
   ytarg__3->SetBinContent(23,14);
   ytarg__3->SetBinContent(24,22);
   ytarg__3->SetBinContent(25,13);
   ytarg__3->SetBinContent(26,16);
   ytarg__3->SetBinContent(27,15);
   ytarg__3->SetBinContent(28,26);
   ytarg__3->SetBinContent(29,17);
   ytarg__3->SetBinContent(30,17);
   ytarg__3->SetBinContent(31,11);
   ytarg__3->SetBinContent(32,26);
   ytarg__3->SetBinContent(33,9);
   ytarg__3->SetBinContent(34,23);
   ytarg__3->SetBinContent(35,20);
   ytarg__3->SetBinContent(36,49);
   ytarg__3->SetBinContent(37,49);
   ytarg__3->SetBinContent(38,33);
   ytarg__3->SetBinContent(39,95);
   ytarg__3->SetBinContent(40,70);
   ytarg__3->SetBinContent(41,94);
   ytarg__3->SetBinContent(42,131);
   ytarg__3->SetBinContent(43,40);
   ytarg__3->SetBinContent(44,110);
   ytarg__3->SetBinContent(45,117);
   ytarg__3->SetBinContent(46,178);
   ytarg__3->SetBinContent(47,212);
   ytarg__3->SetBinContent(48,94);
   ytarg__3->SetBinContent(49,212);
   ytarg__3->SetBinContent(50,194);
   ytarg__3->SetBinContent(51,157);
   ytarg__3->SetBinContent(52,239);
   ytarg__3->SetBinContent(53,231);
   ytarg__3->SetBinContent(54,247);
   ytarg__3->SetBinContent(55,290);
   ytarg__3->SetBinContent(56,314);
   ytarg__3->SetBinContent(57,173);
   ytarg__3->SetBinContent(58,298);
   ytarg__3->SetBinContent(59,316);
   ytarg__3->SetBinContent(60,330);
   ytarg__3->SetBinContent(61,270);
   ytarg__3->SetBinContent(62,388);
   ytarg__3->SetBinContent(63,368);
   ytarg__3->SetBinContent(64,351);
   ytarg__3->SetBinContent(65,435);
   ytarg__3->SetBinContent(66,517);
   ytarg__3->SetBinContent(67,512);
   ytarg__3->SetBinContent(68,415);
   ytarg__3->SetBinContent(69,447);
   ytarg__3->SetBinContent(70,445);
   ytarg__3->SetBinContent(71,455);
   ytarg__3->SetBinContent(72,466);
   ytarg__3->SetBinContent(73,408);
   ytarg__3->SetBinContent(74,405);
   ytarg__3->SetBinContent(75,524);
   ytarg__3->SetBinContent(76,423);
   ytarg__3->SetBinContent(77,536);
   ytarg__3->SetBinContent(78,410);
   ytarg__3->SetBinContent(79,408);
   ytarg__3->SetBinContent(80,370);
   ytarg__3->SetBinContent(81,349);
   ytarg__3->SetBinContent(82,495);
   ytarg__3->SetBinContent(83,487);
   ytarg__3->SetBinContent(84,438);
   ytarg__3->SetBinContent(85,382);
   ytarg__3->SetBinContent(86,309);
   ytarg__3->SetBinContent(87,301);
   ytarg__3->SetBinContent(88,374);
   ytarg__3->SetBinContent(89,248);
   ytarg__3->SetBinContent(90,231);
   ytarg__3->SetBinContent(91,252);
   ytarg__3->SetBinContent(92,274);
   ytarg__3->SetBinContent(93,240);
   ytarg__3->SetBinContent(94,198);
   ytarg__3->SetBinContent(95,254);
   ytarg__3->SetBinContent(96,159);
   ytarg__3->SetBinContent(97,191);
   ytarg__3->SetBinContent(98,178);
   ytarg__3->SetBinContent(99,164);
   ytarg__3->SetBinContent(100,113);
   ytarg__3->SetBinContent(101,105);
   ytarg__3->SetBinContent(102,109);
   ytarg__3->SetBinContent(103,40);
   ytarg__3->SetBinContent(104,67);
   ytarg__3->SetBinContent(105,57);
   ytarg__3->SetBinContent(106,44);
   ytarg__3->SetBinContent(107,45);
   ytarg__3->SetBinContent(108,49);
   ytarg__3->SetBinContent(109,30);
   ytarg__3->SetBinContent(110,30);
   ytarg__3->SetBinContent(111,35);
   ytarg__3->SetBinContent(112,54);
   ytarg__3->SetBinContent(113,24);
   ytarg__3->SetBinContent(114,15);
   ytarg__3->SetBinContent(115,18);
   ytarg__3->SetBinContent(116,2);
   ytarg__3->SetBinContent(117,8);
   ytarg__3->SetBinContent(118,3);
   ytarg__3->SetBinContent(119,4);
   ytarg__3->SetBinContent(120,9);
   ytarg__3->SetBinContent(121,20);
   ytarg__3->SetBinContent(122,14);
   ytarg__3->SetBinContent(123,3);
   ytarg__3->SetBinContent(124,5);
   ytarg__3->SetBinContent(125,2);
   ytarg__3->SetBinContent(126,4);
   ytarg__3->SetBinContent(127,13);
   ytarg__3->SetBinContent(129,26);
   ytarg__3->SetBinContent(130,6);
   ytarg__3->SetBinContent(132,1);
   ytarg__3->SetBinContent(133,4);
   ytarg__3->SetBinContent(134,5);
   ytarg__3->SetBinContent(135,4);
   ytarg__3->SetBinContent(137,4);
   ytarg__3->SetBinContent(144,4);
   ytarg__3->SetBinContent(146,5);
   ytarg__3->SetBinContent(147,2);
   ytarg__3->SetBinContent(148,2);
   ytarg__3->SetBinContent(151,4);
   ytarg__3->SetBinError(0,6.7082);
   ytarg__3->SetBinError(3,1);
   ytarg__3->SetBinError(5,1);
   ytarg__3->SetBinError(6,1);
   ytarg__3->SetBinError(7,1);
   ytarg__3->SetBinError(8,1.41421);
   ytarg__3->SetBinError(9,2.64575);
   ytarg__3->SetBinError(11,1);
   ytarg__3->SetBinError(12,1.41421);
   ytarg__3->SetBinError(13,1.41421);
   ytarg__3->SetBinError(14,1);
   ytarg__3->SetBinError(15,1.73205);
   ytarg__3->SetBinError(16,1.41421);
   ytarg__3->SetBinError(17,3.31662);
   ytarg__3->SetBinError(18,2);
   ytarg__3->SetBinError(19,3.16228);
   ytarg__3->SetBinError(20,4.69042);
   ytarg__3->SetBinError(21,2.64575);
   ytarg__3->SetBinError(22,5.19615);
   ytarg__3->SetBinError(23,3.74166);
   ytarg__3->SetBinError(24,4.69042);
   ytarg__3->SetBinError(25,3.60555);
   ytarg__3->SetBinError(26,4);
   ytarg__3->SetBinError(27,3.87298);
   ytarg__3->SetBinError(28,5.09902);
   ytarg__3->SetBinError(29,4.12311);
   ytarg__3->SetBinError(30,4.12311);
   ytarg__3->SetBinError(31,3.31662);
   ytarg__3->SetBinError(32,5.09902);
   ytarg__3->SetBinError(33,3);
   ytarg__3->SetBinError(34,4.79583);
   ytarg__3->SetBinError(35,4.47214);
   ytarg__3->SetBinError(36,7);
   ytarg__3->SetBinError(37,7);
   ytarg__3->SetBinError(38,5.74456);
   ytarg__3->SetBinError(39,9.74679);
   ytarg__3->SetBinError(40,8.3666);
   ytarg__3->SetBinError(41,9.69536);
   ytarg__3->SetBinError(42,11.4455);
   ytarg__3->SetBinError(43,6.32456);
   ytarg__3->SetBinError(44,10.4881);
   ytarg__3->SetBinError(45,10.8167);
   ytarg__3->SetBinError(46,13.3417);
   ytarg__3->SetBinError(47,14.5602);
   ytarg__3->SetBinError(48,9.69536);
   ytarg__3->SetBinError(49,14.5602);
   ytarg__3->SetBinError(50,13.9284);
   ytarg__3->SetBinError(51,12.53);
   ytarg__3->SetBinError(52,15.4596);
   ytarg__3->SetBinError(53,15.1987);
   ytarg__3->SetBinError(54,15.7162);
   ytarg__3->SetBinError(55,17.0294);
   ytarg__3->SetBinError(56,17.72);
   ytarg__3->SetBinError(57,13.1529);
   ytarg__3->SetBinError(58,17.2627);
   ytarg__3->SetBinError(59,17.7764);
   ytarg__3->SetBinError(60,18.1659);
   ytarg__3->SetBinError(61,16.4317);
   ytarg__3->SetBinError(62,19.6977);
   ytarg__3->SetBinError(63,19.1833);
   ytarg__3->SetBinError(64,18.735);
   ytarg__3->SetBinError(65,20.8567);
   ytarg__3->SetBinError(66,22.7376);
   ytarg__3->SetBinError(67,22.6274);
   ytarg__3->SetBinError(68,20.3715);
   ytarg__3->SetBinError(69,21.1424);
   ytarg__3->SetBinError(70,21.095);
   ytarg__3->SetBinError(71,21.3307);
   ytarg__3->SetBinError(72,21.587);
   ytarg__3->SetBinError(73,20.199);
   ytarg__3->SetBinError(74,20.1246);
   ytarg__3->SetBinError(75,22.891);
   ytarg__3->SetBinError(76,20.567);
   ytarg__3->SetBinError(77,23.1517);
   ytarg__3->SetBinError(78,20.2485);
   ytarg__3->SetBinError(79,20.199);
   ytarg__3->SetBinError(80,19.2354);
   ytarg__3->SetBinError(81,18.6815);
   ytarg__3->SetBinError(82,22.2486);
   ytarg__3->SetBinError(83,22.0681);
   ytarg__3->SetBinError(84,20.9284);
   ytarg__3->SetBinError(85,19.5448);
   ytarg__3->SetBinError(86,17.5784);
   ytarg__3->SetBinError(87,17.3494);
   ytarg__3->SetBinError(88,19.3391);
   ytarg__3->SetBinError(89,15.748);
   ytarg__3->SetBinError(90,15.1987);
   ytarg__3->SetBinError(91,15.8745);
   ytarg__3->SetBinError(92,16.5529);
   ytarg__3->SetBinError(93,15.4919);
   ytarg__3->SetBinError(94,14.0712);
   ytarg__3->SetBinError(95,15.9374);
   ytarg__3->SetBinError(96,12.6095);
   ytarg__3->SetBinError(97,13.8203);
   ytarg__3->SetBinError(98,13.3417);
   ytarg__3->SetBinError(99,12.8062);
   ytarg__3->SetBinError(100,10.6301);
   ytarg__3->SetBinError(101,10.247);
   ytarg__3->SetBinError(102,10.4403);
   ytarg__3->SetBinError(103,6.32456);
   ytarg__3->SetBinError(104,8.18535);
   ytarg__3->SetBinError(105,7.54983);
   ytarg__3->SetBinError(106,6.63325);
   ytarg__3->SetBinError(107,6.7082);
   ytarg__3->SetBinError(108,7);
   ytarg__3->SetBinError(109,5.47723);
   ytarg__3->SetBinError(110,5.47723);
   ytarg__3->SetBinError(111,5.91608);
   ytarg__3->SetBinError(112,7.34847);
   ytarg__3->SetBinError(113,4.89898);
   ytarg__3->SetBinError(114,3.87298);
   ytarg__3->SetBinError(115,4.24264);
   ytarg__3->SetBinError(116,1.41421);
   ytarg__3->SetBinError(117,2.82843);
   ytarg__3->SetBinError(118,1.73205);
   ytarg__3->SetBinError(119,2);
   ytarg__3->SetBinError(120,3);
   ytarg__3->SetBinError(121,4.47214);
   ytarg__3->SetBinError(122,3.74166);
   ytarg__3->SetBinError(123,1.73205);
   ytarg__3->SetBinError(124,2.23607);
   ytarg__3->SetBinError(125,1.41421);
   ytarg__3->SetBinError(126,2);
   ytarg__3->SetBinError(127,3.60555);
   ytarg__3->SetBinError(129,5.09902);
   ytarg__3->SetBinError(130,2.44949);
   ytarg__3->SetBinError(132,1);
   ytarg__3->SetBinError(133,2);
   ytarg__3->SetBinError(134,2.23607);
   ytarg__3->SetBinError(135,2);
   ytarg__3->SetBinError(137,2);
   ytarg__3->SetBinError(144,2);
   ytarg__3->SetBinError(146,2.23607);
   ytarg__3->SetBinError(147,1.41421);
   ytarg__3->SetBinError(148,1.41421);
   ytarg__3->SetBinError(151,2);
   ytarg__3->SetEntries(19718);
   
   yp__7->SetBinContent(0,262);
   yp__7->SetBinContent(1,29);
   yp__7->SetBinContent(2,15);
   yp__7->SetBinContent(3,18);
   yp__7->SetBinContent(4,9);
   yp__7->SetBinContent(5,9);
   yp__7->SetBinContent(6,9);
   yp__7->SetBinContent(7,16);
   yp__7->SetBinContent(8,17);
   yp__7->SetBinContent(9,12);
   yp__7->SetBinContent(10,17);
   yp__7->SetBinContent(11,10);
   yp__7->SetBinContent(12,35);
   yp__7->SetBinContent(13,22);
   yp__7->SetBinContent(14,17);
   yp__7->SetBinContent(15,29);
   yp__7->SetBinContent(16,11);
   yp__7->SetBinContent(17,30);
   yp__7->SetBinContent(18,20);
   yp__7->SetBinContent(19,28);
   yp__7->SetBinContent(20,10);
   yp__7->SetBinContent(21,46);
   yp__7->SetBinContent(22,15);
   yp__7->SetBinContent(23,13);
   yp__7->SetBinContent(24,20);
   yp__7->SetBinContent(25,55);
   yp__7->SetBinContent(26,58);
   yp__7->SetBinContent(27,46);
   yp__7->SetBinContent(28,95);
   yp__7->SetBinContent(29,47);
   yp__7->SetBinContent(30,122);
   yp__7->SetBinContent(31,107);
   yp__7->SetBinContent(32,97);
   yp__7->SetBinContent(33,191);
   yp__7->SetBinContent(34,246);
   yp__7->SetBinContent(35,235);
   yp__7->SetBinContent(36,268);
   yp__7->SetBinContent(37,392);
   yp__7->SetBinContent(38,381);
   yp__7->SetBinContent(39,512);
   yp__7->SetBinContent(40,540);
   yp__7->SetBinContent(41,578);
   yp__7->SetBinContent(42,757);
   yp__7->SetBinContent(43,762);
   yp__7->SetBinContent(44,879);
   yp__7->SetBinContent(45,971);
   yp__7->SetBinContent(46,882);
   yp__7->SetBinContent(47,859);
   yp__7->SetBinContent(48,841);
   yp__7->SetBinContent(49,897);
   yp__7->SetBinContent(50,863);
   yp__7->SetBinContent(51,982);
   yp__7->SetBinContent(52,796);
   yp__7->SetBinContent(53,811);
   yp__7->SetBinContent(54,552);
   yp__7->SetBinContent(55,688);
   yp__7->SetBinContent(56,509);
   yp__7->SetBinContent(57,445);
   yp__7->SetBinContent(58,427);
   yp__7->SetBinContent(59,418);
   yp__7->SetBinContent(60,266);
   yp__7->SetBinContent(61,246);
   yp__7->SetBinContent(62,144);
   yp__7->SetBinContent(63,155);
   yp__7->SetBinContent(64,119);
   yp__7->SetBinContent(65,102);
   yp__7->SetBinContent(66,82);
   yp__7->SetBinContent(67,99);
   yp__7->SetBinContent(68,38);
   yp__7->SetBinContent(69,71);
   yp__7->SetBinContent(70,21);
   yp__7->SetBinContent(71,10);
   yp__7->SetBinContent(72,13);
   yp__7->SetBinContent(73,13);
   yp__7->SetBinContent(74,13);
   yp__7->SetBinContent(75,11);
   yp__7->SetBinContent(76,16);
   yp__7->SetBinContent(77,26);
   yp__7->SetBinContent(78,5);
   yp__7->SetBinContent(79,20);
   yp__7->SetBinContent(80,2);
   yp__7->SetBinContent(81,9);
   yp__7->SetBinContent(82,13);
   yp__7->SetBinContent(83,9);
   yp__7->SetBinContent(84,4);
   yp__7->SetBinContent(85,6);
   yp__7->SetBinContent(86,8);
   yp__7->SetBinContent(87,3);
   yp__7->SetBinContent(88,11);
   yp__7->SetBinContent(89,11);
   yp__7->SetBinContent(90,11);
   yp__7->SetBinContent(91,5);
   yp__7->SetBinContent(92,2);
   yp__7->SetBinContent(93,6);
   yp__7->SetBinContent(94,2);
   yp__7->SetBinContent(95,8);
   yp__7->SetBinContent(96,2);
   yp__7->SetBinContent(97,7);
   yp__7->SetBinContent(99,7);
   yp__7->SetBinContent(100,3);
   yp__7->SetBinContent(101,91);
   yp__7->SetBinError(0,16.1864);
   yp__7->SetBinError(1,5.38516);
   yp__7->SetBinError(2,3.87298);
   yp__7->SetBinError(3,4.24264);
   yp__7->SetBinError(4,3);
   yp__7->SetBinError(5,3);
   yp__7->SetBinError(6,3);
   yp__7->SetBinError(7,4);
   yp__7->SetBinError(8,4.12311);
   yp__7->SetBinError(9,3.4641);
   yp__7->SetBinError(10,4.12311);
   yp__7->SetBinError(11,3.16228);
   yp__7->SetBinError(12,5.91608);
   yp__7->SetBinError(13,4.69042);
   yp__7->SetBinError(14,4.12311);
   yp__7->SetBinError(15,5.38516);
   yp__7->SetBinError(16,3.31662);
   yp__7->SetBinError(17,5.47723);
   yp__7->SetBinError(18,4.47214);
   yp__7->SetBinError(19,5.2915);
   yp__7->SetBinError(20,3.16228);
   yp__7->SetBinError(21,6.78233);
   yp__7->SetBinError(22,3.87298);
   yp__7->SetBinError(23,3.60555);
   yp__7->SetBinError(24,4.47214);
   yp__7->SetBinError(25,7.4162);
   yp__7->SetBinError(26,7.61577);
   yp__7->SetBinError(27,6.78233);
   yp__7->SetBinError(28,9.74679);
   yp__7->SetBinError(29,6.85565);
   yp__7->SetBinError(30,11.0454);
   yp__7->SetBinError(31,10.3441);
   yp__7->SetBinError(32,9.84886);
   yp__7->SetBinError(33,13.8203);
   yp__7->SetBinError(34,15.6844);
   yp__7->SetBinError(35,15.3297);
   yp__7->SetBinError(36,16.3707);
   yp__7->SetBinError(37,19.799);
   yp__7->SetBinError(38,19.5192);
   yp__7->SetBinError(39,22.6274);
   yp__7->SetBinError(40,23.2379);
   yp__7->SetBinError(41,24.0416);
   yp__7->SetBinError(42,27.5136);
   yp__7->SetBinError(43,27.6043);
   yp__7->SetBinError(44,29.6479);
   yp__7->SetBinError(45,31.1609);
   yp__7->SetBinError(46,29.6985);
   yp__7->SetBinError(47,29.3087);
   yp__7->SetBinError(48,29);
   yp__7->SetBinError(49,29.95);
   yp__7->SetBinError(50,29.3769);
   yp__7->SetBinError(51,31.3369);
   yp__7->SetBinError(52,28.2135);
   yp__7->SetBinError(53,28.4781);
   yp__7->SetBinError(54,23.4947);
   yp__7->SetBinError(55,26.2298);
   yp__7->SetBinError(56,22.561);
   yp__7->SetBinError(57,21.095);
   yp__7->SetBinError(58,20.664);
   yp__7->SetBinError(59,20.445);
   yp__7->SetBinError(60,16.3095);
   yp__7->SetBinError(61,15.6844);
   yp__7->SetBinError(62,12);
   yp__7->SetBinError(63,12.4499);
   yp__7->SetBinError(64,10.9087);
   yp__7->SetBinError(65,10.0995);
   yp__7->SetBinError(66,9.05539);
   yp__7->SetBinError(67,9.94987);
   yp__7->SetBinError(68,6.16441);
   yp__7->SetBinError(69,8.42615);
   yp__7->SetBinError(70,4.58258);
   yp__7->SetBinError(71,3.16228);
   yp__7->SetBinError(72,3.60555);
   yp__7->SetBinError(73,3.60555);
   yp__7->SetBinError(74,3.60555);
   yp__7->SetBinError(75,3.31662);
   yp__7->SetBinError(76,4);
   yp__7->SetBinError(77,5.09902);
   yp__7->SetBinError(78,2.23607);
   yp__7->SetBinError(79,4.47214);
   yp__7->SetBinError(80,1.41421);
   yp__7->SetBinError(81,3);
   yp__7->SetBinError(82,3.60555);
   yp__7->SetBinError(83,3);
   yp__7->SetBinError(84,2);
   yp__7->SetBinError(85,2.44949);
   yp__7->SetBinError(86,2.82843);
   yp__7->SetBinError(87,1.73205);
   yp__7->SetBinError(88,3.31662);
   yp__7->SetBinError(89,3.31662);
   yp__7->SetBinError(90,3.31662);
   yp__7->SetBinError(91,2.23607);
   yp__7->SetBinError(92,1.41421);
   yp__7->SetBinError(93,2.44949);
   yp__7->SetBinError(94,1.41421);
   yp__7->SetBinError(95,2.82843);
   yp__7->SetBinError(96,1.41421);
   yp__7->SetBinError(97,2.64575);
   yp__7->SetBinError(99,2.64575);
   yp__7->SetBinError(100,1.73205);
   yp__7->SetBinError(101,9.53939);
   yp__7->SetEntries(19718);
	
}
	
  
  
  
	  
	    
