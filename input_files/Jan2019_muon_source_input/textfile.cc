#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include "TFile.h"
#include "TPostScript.h"
#include <iomanip>
#include <stdio.h>

using namespace std;

#define SQR(a) ((a)*(a))

char name[500];
int count, count1, EventID, t, PDGid, TrackID, ParentID, Weight;
float temp[7];
float x, x_p, y, y_p, z, P, Px, Py, Pz, Pt2, Ptest, x_offset;

void textfile()
{
	cerr<<"/////////////////////////////////////////////"<<endl;
	cerr<<"read input textfile from Turtle and write it such that";
	cerr<<" the format matches g4beamline"<<endl;
	cerr<<"/////////////////////////////////////////////"<<endl<<endl;
	
	//Read input file
	
	ifstream TurtleInput;
	sprintf(name, "allmuonraysv6.dat");
	TurtleInput.open(name,ios::in);
	cerr<<"Get data from "<<name<<endl;
	
	//Define output textfile
	sprintf(name, "g4_in.txt");
	ofstream out_txt(name, ios::out);
	out_txt.setf(ios::showpoint|ios::fixed);
	out_txt.precision(3);
		
	//initialize
	for(int i=0; i<7; i++) temp[i]=-99.99;
	count=0;
	count1=0;
	x=-99.99;
	x_p=-99.99;
	y=-99.99;
	y_p=-99.99;
	z=-958; //start point in g4beamline
	P=-99.99;
	Px=-99.99;
	Py=-99.99;
	Pz=-99.99;
	Pt2=-99.99; //sqr of transverse momentum
	EventID=-99;
	t=0; //in ns
	PDGid=-13; //pi+
	TrackID=0;
	ParentID=0;
	Weight=1;
	
	x_offset=0.0; // in mm. For some reason the beam gets shifted by -0.5 mm when I read 
	             //it in using g4beamline simulation
	
	while(!TurtleInput.eof())
	//while(count<5)
	{	
		count++;
		for(int i=0; i<6; i++) TurtleInput>>temp[i];
		x=-10*temp[0]; //converting cm to mm & flip sign to match g4beamline
		x_p= 0.001*temp[1]; //converting mrad to rad
		y=-10*temp[2]; //coverting cm to mm & flip sign to match g4beamline
		y_p=0.001*temp[3]; //converting mrad to rad
		P=temp[4]; //in MeV/c
		EventID=temp[5];
		
		//if(x_p<0) Px=P*sin(fabs(x_p)); // (MeV/c) I have flipped sign of Px 
		                              //to match g4beamline 
		//else Px=-1*P*sin(x_p); //MeV/c
		
		//if(y_p<0)Py=P*sin(fabs(y_p)); //(MeV/c) I have flipped sign of Px 
		                              //to match g4beamline 
		//else Py=-1*P*sin(y_p);
		
		//Pt2=SQR(Px)+SQR(Py); //MeV/c
		//Pz=sqrt(SQR(P)-Pt2); //MeV/c
		
		Pt2=sqrt(1+tan(x_p)*tan(x_p) + tan(y_p)*tan(y_p));
		
		Pz=P/Pt2;
		
	    if(x_p<0) Px = Pz*fabs(tan(x_p));
	    else Px = -1*Pz*fabs(tan(x_p)); //flip sign of Px to match g4beamline
	    
	    if(y_p<0) Py = Pz*fabs(tan(y_p));
	    else Py = -1*Pz*fabs(tan(y_p));
	    
	    Ptest=Px*Px+Py*Py+Pz*Pz;
	    
	    Ptest=sqrt(Ptest);
	    
	    
	    if(fabs(P-Ptest)>0.001)
	    {
			cerr<<endl<<"P does not match sqr sum of Px, Py, Pz for Event num = "<<EventID;
			cerr<<", Px = "<<Px<<", Py = "<<Py<<", Pz = "<<Pz<<", Ptest = "<<Ptest;
			cerr<<", P actual = "<<P<<", P-Ptest = "<<(P-Ptest)<<endl<<endl;
			count1++;
			
		}
		
		if(EventID<5)
		{ 
			cerr<<endl<<"x = "<<x<<", y = "<<y<<", z = "<<z<<endl;
			cerr<<"x' = "<<x_p<<", y' = "<<y_p<<endl;
			cerr<<"Px = "<<Px<<", Py = "<<Py<<", Pz = "<<Pz<<", P = "<<P<<endl;
			cerr<<"t = "<<t<<endl;
			cerr<<"PDGid = "<<PDGid<<", EventID = "<<EventID;
			cerr<<", TrackID = "<<TrackID<<", ParentID = "<<ParentID<<endl;
			cerr<<"Weight = "<<Weight<<endl<<endl;
		}
		//write to output file
		
		out_txt<<(x+x_offset)<<setw(12)<<y<<setw(12)<<z<<setw(12)<<Px<<setw(12);
		//out_txt<<x<<setw(12)<<1.5<<setw(12)<<z<<setw(12)<<Px<<setw(12);
		out_txt<<Py<<setw(12)<<Pz<<setw(6);
		out_txt<<t<<setw(8)<<PDGid<<setw(8)<<EventID;
		out_txt<<setw(4)<<TrackID<<setw(4);
		out_txt<<ParentID<<setw(4)<<Weight<<endl;
		
	}
	cerr<<"Total events read = "<<count<<endl;
	cerr<<"Event number of last entry = "<<EventID<<endl;
	cerr<<"num of events where Ptest does not match P = "<<count1<<endl;
	cerr<<"Done!"<<endl;
}
		
		
	
	
		
		
	
	
