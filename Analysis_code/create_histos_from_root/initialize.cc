//////////////////////////////////////////
//  Initialize Variables
/////////////////////////////////////////

#include <iostream>
#include "variable.h"

using namespace std;

void initialize()
{
  //the first virtual detector in the beamline

  //spatial info
 
  Det0_x = -99.99;
  Det0_y = -99.99;
  Det0_z = -99.99;

  //momentum info
  
  Det0_Px = -99.99;
  Det0_Py = -99.99;
  Det0_Pz = -99.99;

  //timing info

  Det0_t = -99.99;

  //track, particle ID, event ID info

  Det0_PDGid = -100;
  Det0_EventID = -100;
  Det0_TrackID = -100;

  ///// The virtual detector at the IFP ////////////////////////////

  //spatial info
 
  Det3_x = -99.99;
  Det3_y = -99.99;
  Det3_z = -99.99;

  //momentum info
  
  Det3_Px = -99.99;
  Det3_Py = -99.99;
  Det3_Pz = -99.99;

  //timing info

  Det3_t = -99.99;

  //track, particle ID, event ID info

  Det3_PDGid = -100;
  Det3_EventID = -100;
  Det3_TrackID = -100;
  
  /////////// The virtual detector at the target ///////////////

  //spatial info
 
  DetTar_x = -99.99;
  DetTar_y = -99.99;
  DetTar_z = -99.99;

  //momentum info
  
  DetTar_Px = -99.99;
  DetTar_Py = -99.99;
  DetTar_Pz = -99.99;

  //timing info

  DetTar_t = -99.99;

  //track, particle ID, event ID info

  DetTar_PDGid = -100;
  DetTar_EventID = -100;
  DetTar_TrackID = -100;

}
