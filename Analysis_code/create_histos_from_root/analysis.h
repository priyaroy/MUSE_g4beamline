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
TTree *tree0a; //ntuple for virtual detector 0a
TTree *treeAQTA1; //ntuple for detector AQTA1
TTree *treeAQTB1; //ntuple for detector AQTB1
TTree *treeAQTB2; //ntuple for detector AQTB2
TTree *tree1; //ntuple for virtual detector 1
TTree *tree2; //ntuple for virtual detector 2
TTree *tree3; //ntuple for detector at IFP
TTree *tree4; //ntuple for virtual detector 4
TTree *tree5; //ntuple for virtual detector 5
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
float_t Det0_P;

// timing info

float_t Det0_t;

//track, particle ID, event ID info

float_t Det0_PDGid;
float_t Det0_EventID;
float_t Det0_TrackID;

///////////the virtual detector at start of QTA1 in the beamline

//spatial info

float_t Det0a_x;
float_t Det0a_y;
float_t Det0a_z;

//momentum info

float_t Det0a_Px;
float_t Det0a_Py;
float_t Det0a_Pz;
float_t Det0a_P;

// timing info

float_t Det0a_t;

//track, particle ID, event ID info

float_t Det0a_PDGid;
float_t Det0a_EventID;
float_t Det0a_TrackID;

///////////the virtual detector between QTA1 & QTB1 in the beamline

//spatial info

float_t DetAQTA1_x;
float_t DetAQTA1_y;
float_t DetAQTA1_z;

//momentum info

float_t DetAQTA1_Px;
float_t DetAQTA1_Py;
float_t DetAQTA1_Pz;
float_t DetAQTA1_P;

// timing info

float_t DetAQTA1_t;

//track, particle ID, event ID info

float_t DetAQTA1_PDGid;
float_t DetAQTA1_EventID;
float_t DetAQTA1_TrackID;

///////////the virtual detector between QTB1 & QTB2 in the beamline

//spatial info

float_t DetAQTB1_x;
float_t DetAQTB1_y;
float_t DetAQTB1_z;

//momentum info

float_t DetAQTB1_Px;
float_t DetAQTB1_Py;
float_t DetAQTB1_Pz;
float_t DetAQTB1_P;

// timing info

float_t DetAQTB1_t;

//track, particle ID, event ID info

float_t DetAQTB1_PDGid;
float_t DetAQTB1_EventID;
float_t DetAQTB1_TrackID;

///////////the virtual detector after QTB2 in the beamline

//spatial info

float_t DetAQTB2_x;
float_t DetAQTB2_y;
float_t DetAQTB2_z;

//momentum info

float_t DetAQTB2_Px;
float_t DetAQTB2_Py;
float_t DetAQTB2_Pz;
float_t DetAQTB2_P;

// timing info

float_t DetAQTB2_t;

//track, particle ID, event ID info

float_t DetAQTB2_PDGid;
float_t DetAQTB2_EventID;
float_t DetAQTB2_TrackID;

/////////// virtual detector at entrance of dipole 1 in the beamline

//spatial info

float_t Det1_x;
float_t Det1_y;
float_t Det1_z;

//momentum info

float_t Det1_Px;
float_t Det1_Py;
float_t Det1_Pz;
float_t Det1_P;

// timing info

float_t Det1_t;

//track, particle ID, event ID info

float_t Det1_PDGid;
float_t Det1_EventID;
float_t Det1_TrackID;

/////////// virtual detector at exit of dipole 1 in the beamline

//spatial info

float_t Det2_x;
float_t Det2_y;
float_t Det2_z;

//momentum info

float_t Det2_Px;
float_t Det2_Py;
float_t Det2_Pz;
float_t Det2_P;

// timing info

float_t Det2_t;

//track, particle ID, event ID info

float_t Det2_PDGid;
float_t Det2_EventID;
float_t Det2_TrackID;


///////////the virtual detector at the intermediate focal point in the beamline

//spatial info

float_t Det3_x;
float_t Det3_y;
float_t Det3_z;

//momentum info

float_t Det3_Px;
float_t Det3_Py;
float_t Det3_Pz;
float_t Det3_P;

// timing info

float_t Det3_t;

//track, particle ID, event ID info

float_t Det3_PDGid;
float_t Det3_EventID;
float_t Det3_TrackID;

///////////the virtual detector at entrance of dipole 2 in the beamline

//spatial info

float_t Det4_x;
float_t Det4_y;
float_t Det4_z;

//momentum info

float_t Det4_Px;
float_t Det4_Py;
float_t Det4_Pz;
float_t Det4_P;

// timing info

float_t Det4_t;

//track, particle ID, event ID info

float_t Det4_PDGid;
float_t Det4_EventID;
float_t Det4_TrackID;

///////////the virtual detector at exit of dipole 2 in the beamline

//spatial info

float_t Det5_x;
float_t Det5_y;
float_t Det5_z;

//momentum info

float_t Det5_Px;
float_t Det5_Py;
float_t Det5_Pz;
float_t Det5_P;

// timing info

float_t Det5_t;

//track, particle ID, event ID info

float_t Det5_PDGid;
float_t Det5_EventID;
float_t Det5_TrackID;

///////////the virtual detector at the MUSE target in the beamline

//spatial info

float_t DetTar_x;
float_t DetTar_y;
float_t DetTar_z;

//momentum info

float_t DetTar_Px;
float_t DetTar_Py;
float_t DetTar_Pz;
float_t DetTar_P;

// timing info

float_t DetTar_t;

//track, particle ID, event ID info

float_t DetTar_PDGid;
float_t DetTar_EventID;
float_t DetTar_TrackID;

