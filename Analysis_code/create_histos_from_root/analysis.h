#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TFile.h"

using namespace std;

char name[100];

//////////////////////////////////////////////
//Input rootfile
//////////////////////////////////////////////

TFile *MuseFile;

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

float_t Det0_x;
float_t Det0_y;
float_t Det0_z;

//momentum info

float_t Det0_Px;
float_t Det0_Py;
float_t Det0_Pz;

// timing info

float_t Det0_t;

//track, particle ID, event ID info

float_t Det0_PDGid;
float_t Det0_EventID;
float_t Det0_TrackID;

///////////the virtual detector at the intermediate focal point in the beamline

//spatial info

float_t Det3_x;
float_t Det3_y;
float_t Det3_z;

//momentum info

float_t Det3_Px;
float_t Det3_Py;
float_t Det3_Pz;

// timing info

float_t Det3_t;

//track, particle ID, event ID info

float_t Det3_PDGid;
float_t Det3_EventID;
float_t Det3_TrackID;

///////////the virtual detector at the MUSE target in the beamline

//spatial info

float_t DetTar_x;
float_t DetTar_y;
float_t DetTar_z;

//momentum info

float_t DetTar_Px;
float_t DetTar_Py;
float_t DetTar_Pz;

// timing info

float_t DetTar_t;

//track, particle ID, event ID info

float_t DetTar_PDGid;
float_t DetTar_EventID;
float_t DetTar_TrackID;

