//////////////////////////////////////////////
// Loop over events and fill histograms
//Only consider those events that make it to the target
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
	
	int eventID_tar = -9;
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
	nentries[1] = tree1->GetEntries();
	nentries[2] = tree2->GetEntries();
	nentries[3] = tree3->GetEntries();
    nentries[4] = tree4->GetEntries();
    nentries[5] = tree5->GetEntries();
	nentries[7] = treeTar->GetEntries();
	nentries[8] = tree0a->GetEntries();
	nentries[9] = treeAQTA1->GetEntries();
	nentries[10] = treeAQTB1->GetEntries();
	nentries[11] = treeAQTB2->GetEntries();
	
	cerr<<endl<<"**********Filling histograms corresponding to DetTar****** "<<endl;
	cerr<<endl<<"The number of entries in treeTar (detTar) = "<<nentries[7]<<endl;
	
	nentries_Tar=nentries[7]; // set the global variable. Will be used for scaling 
	                          //histograms in writeROOT.cc
	                          
	for(long counterTar=0; counterTar<nentries[7]; counterTar++)
	{
		//Get event no. at PiM1 Tar. We will compare it with event# at other detectors
		//and fill histograms only if the event numbers match
		
		treeTar->GetEntry(counterTar);
		eventID_tar=DetTar_EventID;
		
		if((counterTar%100)==0)
		{
			cerr<<"counter ="<<counterTar<<endl;
			cerr<<"Event ID that makes it to Target = "<<eventID_tar<<endl;
		}
		///////////////////////////////////////////////
		// Read events from tree0 i.e. at Det0
		///////////////////////////////////////////////
		
		/*
		for(long counter=0; counter<nentries[0]; counter++)
		{
			tree0->GetEntry(counter);
			
			if((Det0_PDGid != 211)||(Det0_EventID != eventID_tar)) continue;
			
			else
			{	
				//Fill spatial distribution histograms
				xDet0->Fill(-0.1*Det0_x);
				yDet0->Fill(-0.1*Det0_y);
				beamspot_Det0->Fill(-0.1*Det0_x, -0.1*Det0_y);
				MupEvents[0]++;
				
				//Fill dispersion histogram
				
				Det0_P = sqrt(pow(Det0_Px, 2) + pow(Det0_Py, 2) + pow(Det0_Pz, 2));
				Delta_p[0] = (-155.0 + Det0_P)*(100/Det0_P);
				
				//angles
				if(Det0_Px<0)xp[0]=fabs(atan(Det0_Px/Det0_Pz))*1000; //angle converted to mrad
				else xp[0]=-1*fabs(atan(Det0_Px/Det0_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
				if(Det0_Py<0)yp[0]=fabs(atan(Det0_Py/Det0_Pz))*1000; //angle converted to mrad
				else yp[0]=-1*fabs(atan(Det0_Py/Det0_Pz))*1000; 
				
				//Fill x', y' histograms
				
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
			}
			//I flipped the sign of x so that it matches Turtle. Is easier to compare.
		}
		*/
		///////////////////////////////////////////////
		// Read events from tree1 i.e. at Det1
		///////////////////////////////////////////////
		/*
		for(long counter1=0; counter1<nentries[1]; counter1++)
		{	
			tree1->GetEntry(counter1);
			
			if((Det1_PDGid != 211)||(Det1_EventID != eventID_tar)) continue;
			
			else
			{	
				//Fill spatial distribution histograms
				xDet1->Fill(-0.1*Det1_x);
				
				//cerr<<"Fill Det1_y"<<endl;
				yDet1->Fill(-0.1*Det1_y);
				
				//cerr<<"Fill beamspot_det1"<<endl;
				beamspot_Det1->Fill(-0.1*Det1_x, -0.1*Det1_y);
				
				//cerr<<"count++"<<endl;
				MupEvents[1]++;
				
				//Fill dispersion histogram
				
				Det1_P = sqrt(pow(Det1_Px, 2) + pow(Det1_Py, 2) + pow(Det1_Pz, 2));
				Delta_p[1] = (-155.0 + Det1_P)*(100/155.0);
				
				if(Det1_Px<0)xp[1]=fabs(atan(Det1_Px/Det1_Pz))*1000; //angle converted to mrad
				else xp[1]=-1*fabs(atan(Det1_Px/Det1_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
				
				if(Det1_Py<0)yp[1]=fabs(atan(Det1_Py/Det1_Pz))*1000; //angle converted to mrad
				else yp[1]=-1*fabs(atan(Det1_Py/Det1_Pz))*1000; 
				
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
		*/
		///////////////////////////////////////////////
		// Read events from tree2 i.e. at Det2
		///////////////////////////////////////////////
		/*
		for(long counter2=0; counter2<nentries[2]; counter2++)
		{
			
			tree2->GetEntry(counter2);
			
			if((Det2_PDGid != 211)||(Det2_EventID != eventID_tar)) continue;
			
			else
			{
				//Fill spatial distribution histograms
				
				xDet2->Fill(-0.1*Det2_x);
				yDet2->Fill(-0.1*Det2_y);
				beamspot_Det2->Fill(-0.1*Det2_x, -0.1*Det2_y);
				
				MupEvents[2]++;
				
				//Fill dispersion histogram
				Det2_P = sqrt(pow(Det2_Px, 2) + pow(Det2_Py, 2) + pow(Det2_Pz, 2));
				Delta_p[2] = (-155.0 + Det2_P)*(100/155.0);
				if(Det2_Px<0)xp[2]=fabs(atan(Det2_Px/Det2_Pz))*1000; //angle converted to mrad
				else xp[2]=-1*fabs(atan(Det2_Px/Det2_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
				
				if(Det2_Py<0)yp[2]=fabs(atan(Det2_Py/Det2_Pz))*1000; //angle converted to mrad
				else yp[2]=-1*fabs(atan(Det2_Py/Det2_Pz))*1000; 
				
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
		*/
		///////////////////////////////////////////////
		// Read events from tree3 i.e. @ DetIFP
		///////////////////////////////////////////////
		/*
		for(long counter3=0; counter3<nentries[3]; counter3++)
		{
			
			tree3->GetEntry(counter3);
			if((Det3_PDGid != -13)||(Det3_EventID != eventID_tar)) continue;
			
			else
			{
				
				//Fill spatial distribution histograms
				
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
		*/
		///////////////////////////////////////////////
		// Read events from tree4 i.e. @ Det4
		///////////////////////////////////////////////
		/*
		for(long counter4=0; counter4<nentries[4]; counter4++)
		{
			// print event number at start detector occasionally
			tree4->GetEntry(counter4);
			
			if((Det4_PDGid != 211)||(Det4_EventID != eventID_tar)) continue;
			
			else
			{
				
				//Fill spatial distribution histograms
				
				xDet4->Fill(-0.1*Det4_x);
				yDet4->Fill(-0.1*Det4_y);
				beamspot_Det4->Fill(-0.1*Det4_x, -0.1*Det4_y);
				
				MupEvents[4]++;
				
				//Fill dispersion histogram
				
				Det4_P = sqrt(pow(Det4_Px, 2) + pow(Det4_Py, 2) + pow(Det4_Pz, 2));
				Delta_p[4] = (-155.0 + Det4_P)*(100/155.0);
				
				if(Det4_Px<0)xp[4]=fabs(atan(Det4_Px/Det4_Pz))*1000; //angle converted to mrad
				else xp[4]=-1*fabs(atan(Det4_Px/Det4_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
				
				if(Det4_Py<0)yp[4]=fabs(atan(Det4_Py/Det4_Pz))*1000; //angle converted to mrad
				else yp[4]=-1*fabs(atan(Det4_Py/Det4_Pz))*1000; 
				
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
		*/
		///////////////////////////////////////////////
		// Read events from tree5 i.e. @ Det5
		///////////////////////////////////////////////
		/*
		for(long counter5=0; counter5<nentries[5]; counter5++)
		{
			
			tree5->GetEntry(counter5);
			
			if((Det5_PDGid != 211)||(Det5_EventID != eventID_tar)) continue;
			
			else
			{
				xDet5->Fill(-0.1*Det5_x);
				yDet5->Fill(-0.1*Det5_y);
				beamspot_Det5->Fill(-0.1*Det5_x, -0.1*Det5_y);
				MupEvents[5]++;
				
				//Fill dispersion histogram
				Det5_P = sqrt(pow(Det5_Px, 2) + pow(Det5_Py, 2) + pow(Det5_Pz, 2));
				Delta_p[5] = (-155.0 + Det5_P)*(100/155.0);
				
				if(Det5_Px<0)xp[5]=fabs(atan(Det5_Px/Det5_Pz))*1000; //angle converted to mrad
				else xp[5]=-1*fabs(atan(Det5_Px/Det5_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
				
				if(Det5_Py<0)yp[5]=fabs(atan(Det5_Py/Det5_Pz))*1000; //angle converted to mrad
				else yp[5]=-1*fabs(atan(Det5_Py/Det5_Pz))*1000; 
				
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
		*/
		///////////////////////////////////////////////
		// Read events from treeTar
		///////////////////////////////////////////////
		
		if(DetTar_PDGid!= -13) continue;
		
		else
		{
			xDetTar->Fill(-0.1*DetTar_x);
			yDetTar->Fill(-0.1*DetTar_y);
			beamspot_DetTar->Fill(-0.1*DetTar_x, -0.1*DetTar_y);
			
			MupEvents[7]++;
			
			//Fill dispersion histogram
			
			DetTar_P = sqrt(pow(DetTar_Px, 2) + pow(DetTar_Py, 2) + pow(DetTar_Pz, 2));
			Delta_p[7] = (-155.0 + DetTar_P)*(100/155.0);
			
			if(DetTar_Px<0)xp[7]=fabs(atan(DetTar_Px/DetTar_Pz))*1000; //angle converted to mrad
			else xp[7]=-1*fabs(atan(DetTar_Px/DetTar_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
			
			if(DetTar_Py<0)yp[7]=fabs(atan(DetTar_Py/DetTar_Pz))*1000; //angle converted to mrad
			else yp[7]=-1*fabs(atan(DetTar_Py/DetTar_Pz))*1000; 
			
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
		
		///////////////////////////////////////////////
		// Read events from Det0a
		///////////////////////////////////////////////
		/*
		for(long counter8=0; counter8<nentries[8]; counter8++)
		{
			tree0a->GetEntry(counter8);
		
		    if((Det0a_PDGid != 211)||(Det0a_EventID != eventID_tar)) continue;
			
			else
			{
				//Fill spatial distribution histograms
				
				xDet0a->Fill(-0.1*Det0a_x);
				yDet0a->Fill(-0.1*Det0a_y);
				beamspot_Det0a->Fill(-0.1*Det0a_x, -0.1*Det0a_y);
				
				MupEvents[8]++;
		
		       //Fill dispersion histogram
		       
		       Det0a_P = sqrt(pow(Det0a_Px, 2) + pow(Det0a_Py, 2) + pow(Det0a_Pz, 2));
		       Delta_p[8] = (-155.0 + Det0a_P)*(100/155.0);
		       
		       if(Det0a_Px<0)xp[8]=fabs(atan(Det0a_Px/Det0a_Pz))*1000; //angle converted to mrad
		       else xp[8]=-1*fabs(atan(Det0a_Px/Det0a_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
		       
		       if(Det0a_Py<0)yp[8]=fabs(atan(Det0a_Py/Det0a_Pz))*1000; //angle converted to mrad
		       else yp[8]=-1*fabs(atan(Det0a_Py/Det0a_Pz))*1000; 
		       
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
	   */
	   ///////////////////////////////////////////////
	   // Read events from DetAQTA1
	   ///////////////////////////////////////////////
	   /*
	   for(long counter9=0; counter9<nentries[9]; counter9++)
	   {
		   
		   treeAQTA1->GetEntry(counter9);
		   
		   if((DetAQTA1_PDGid != 211)||(DetAQTA1_EventID != eventID_tar)) continue;
		   
		   else
		   {
			   
			   //Fill spatial distribution histograms
			   
			   xDetAQTA1->Fill(-0.1*DetAQTA1_x);
			   yDetAQTA1->Fill(-0.1*DetAQTA1_y);
			   beamspot_DetAQTA1->Fill(-0.1*DetAQTA1_x, -0.1*DetAQTA1_y);
			   MupEvents[9]++;
			   
			   //Fill dispersion histogram
			   
			   DetAQTA1_P = sqrt(pow(DetAQTA1_Px, 2) + pow(DetAQTA1_Py, 2) + pow(DetAQTA1_Pz, 2));
			   Delta_p[9] = (-155.0 + DetAQTA1_P)*(100/155.0);
			   
			   if(DetAQTA1_Px<0)xp[9]=fabs(atan(DetAQTA1_Px/DetAQTA1_Pz))*1000; //angle converted to mrad
			   else xp[9]=-1*fabs(atan(DetAQTA1_Px/DetAQTA1_Pz))*1000; //when Px is +ve in g4beamline, it is -ve in Turtle
			   if(DetAQTA1_Py<0)yp[9]=fabs(atan(DetAQTA1_Py/DetAQTA1_Pz))*1000; //angle converted to mrad
			   else yp[9]=-1*fabs(atan(DetAQTA1_Py/DetAQTA1_Pz))*1000; 
			   
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
	   */
	   //////////////////////////////////////////////
	   // Read events from DetAQTB1
	   ///////////////////////////////////////////////
	   /*
	   for(long counter10=0; counter10<nentries[10]; counter10++)
	   {
		   treeAQTB1->GetEntry(counter10);
		   
		   if((DetAQTB1_PDGid != 211)||(DetAQTB1_EventID != eventID_tar)) continue;
		   
		   else
		   {
			   
			   //Fill spatial distribution histograms
			   
			   xDetAQTB1->Fill(-0.1*DetAQTB1_x);
			   yDetAQTB1->Fill(-0.1*DetAQTB1_y);
			   beamspot_DetAQTB1->Fill(-0.1*DetAQTB1_x, -0.1*DetAQTB1_y);
			   
			   MupEvents[10]++;
			   
			   //Fill dispersion histogram
			   
			   DetAQTB1_P = sqrt(pow(DetAQTB1_Px, 2) + pow(DetAQTB1_Py, 2) + pow(DetAQTB1_Pz, 2));
			   Delta_p[10] = (-155.0 + DetAQTB1_P)*(100/155.0);
			   
			   if(DetAQTB1_Px<0)xp[10]=fabs(atan(DetAQTB1_Px/DetAQTB1_Pz))*1000; //angle converted to mrad
			   else xp[10]=-1*fabs(atan(DetAQTB1_Px/DetAQTB1_Pz))*1000; //Px is -ve in g4, then it is +ve in Turtle
			   if(DetAQTB1_Py<0)yp[10]=fabs(atan(DetAQTB1_Py/DetAQTB1_Pz))*1000; //angle converted to mrad
			   else yp[10]=-1*fabs(atan(DetAQTB1_Py/DetAQTB1_Pz))*1000; 
			   
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
	   */
	   //////////////////////////////////////////////
	   // Read events from DetAQTB2
	   ///////////////////////////////////////////////
	   /*
	   for(long counter11=0; counter11<nentries[11]; counter11++)
	   {
		   
		   treeAQTB2->GetEntry(counter11);
		   if((DetAQTB2_PDGid != 211)||(DetAQTB2_EventID != eventID_tar)) continue;
		   
		   else
		   {
			   xDetAQTB2->Fill(-0.1*DetAQTB2_x);
			   yDetAQTB2->Fill(-0.1*DetAQTB2_y);
			   beamspot_DetAQTB2->Fill(-0.1*DetAQTB2_x, -0.1*DetAQTB2_y);
			   
			   MupEvents[11]++;
			   
			   //Fill dispersion histogram
			   
			   DetAQTB2_P = sqrt(pow(DetAQTB2_Px, 2) + pow(DetAQTB2_Py, 2) + pow(DetAQTB2_Pz, 2));
			   Delta_p[11] = (-155.0 + DetAQTB2_P)*(100/155.0);
			   
			   if(DetAQTB2_Px<0)xp[11]=fabs(atan(DetAQTB2_Px/DetAQTB2_Pz))*1000; //angle converted to mrad
			   else xp[11]=-1*fabs(atan(DetAQTB2_Px/DetAQTB2_Pz))*1000; 
			   
			   if(DetAQTB2_Py<0)yp[11]=fabs(atan(DetAQTB2_Py/DetAQTB2_Pz))*1000; //angle converted to mrad
			   else yp[11]=-1*fabs(atan(DetAQTB2_Py/DetAQTB2_Pz))*1000; 
			   
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
	   */
   }
   cerr<<endl<<"End of filling histograms. Summary below:"<<endl<<endl;
   
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
	
}
	
  
  
  
	  
	    
