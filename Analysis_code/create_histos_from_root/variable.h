#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"

using namespace std;

extern char name[100];

//////////////////////////////////////////////
//Input rootfile
//////////////////////////////////////////////

extern TFile *MuseFile;

/////////////////////////////////////////////////////////////////////
// Input rootfile's tree
////////////////////////////////////////////////////////////////////

extern TTree *tree0; //ntuple for virtual detector 0
extern TTree *tree3; //ntuple for detector at IFP
extern TTree *treeTar;//ntuple for detector at MUSE target

///////////////////////////////////////////////////////////////////////
//variables storing information from branches of input rootfile
///////////////////////////////////////////////////////////////////////

///////////the first virtual detector in the beamline

//spatial info

extern float_t Det0_x;
extern float_t Det0_y;
extern float_t Det0_z;

//momentum info

extern float_t Det0_Px;
extern float_t Det0_Py;
extern float_t Det0_Pz;

// timing info

extern float_t Det0_t;

//track, particle ID, event ID info

extern float_t Det0_PDGid;
extern float_t Det0_EventID;
extern float_t Det0_TrackID;

///////////the virtual detector at the intermediate focal point in the beamline

//spatial info

extern float_t Det3_x;
extern float_t Det3_y;
extern float_t Det3_z;

//momentum info

extern float_t Det3_Px;
extern float_t Det3_Py;
extern float_t Det3_Pz;

// timing info

extern float_t Det3_t;

//track, particle ID, event ID info

extern float_t Det3_PDGid;
extern float_t Det3_EventID;
extern float_t Det3_TrackID;

///////////the virtual detector at the MUSE target in the beamline

//spatial info

extern float_t DetTar_x;
extern float_t DetTar_y;
extern float_t DetTar_z;

//momentum info

extern float_t DetTar_Px;
extern float_t DetTar_Py;
extern float_t DetTar_Pz;

// timing info

extern float_t DetTar_t;

//track, particle ID, event ID info

extern float_t DetTar_PDGid;
extern float_t DetTar_EventID;
extern float_t DetTar_TrackID;

