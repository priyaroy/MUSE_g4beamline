#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"

using namespace std;

//////////////////////////////////////////////
//Input rootfile
//////////////////////////////////////////////

Tfile *MuseFile;

///////////////////////////////////////////////////////////////////////
//Input rootfile's tree
//////////////////////////////////////////////////////////////////////

TTree *tree0; //ntuple for virtual detector 0
TTree *tree3; //ntuple for detector at IFP
TTree *treeTar;//ntuple for detector at MUSE target

///////////////////////////////////////////////////////////////////////
//variables storing information from branches of input rootfile
///////////////////////////////////////////////////////////////////////

///////////the first virtual detector in the beamline

//spatial info

double Det0_x;
double Det0_y;
double Det0_z;

//momentum info

double Det0_Px;
double Det0_Py;
double Det0_Pz;

// timing info

double Det0_t;

//track, particle ID, event ID info

int Det0_PDGid;
int Det0_EventID;
int Det0_TrackID;

///////////the virtual detector at the intermediate focal point in the beamline

//spatial info

double Det3_x;
double Det3_y;
double Det3_z;

//momentum info

double Det3_Px;
double Det3_Py;
double Det3_Pz;

// timing info

double Det3_t;

//track, particle ID, event ID info

int Det3_PDGid;
int Det3_EventID;
int Det3_TrackID;

///////////the virtual detector at the MUSE target in the beamline

//spatial info

double DetTar_x;
double DetTar_y;
double DetTar_z;

//momentum info

double DetTar_Px;
double DetTar_Py;
double DetTar_Pz;

// timing info

double DetTar_t;

//track, particle ID, event ID info

int DetTar_PDGid;
int DetTar_EventID;
int DetTar_TrackID;

