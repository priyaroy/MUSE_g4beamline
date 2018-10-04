///////////////////////////////////////////////////
// Read the data from the branches of the root file
///////////////////////////////////////////////////

#include <iostream>
#include "TTree.h"
#include "variable.h"

using namespace std;

void setBranches()
{
  //if bname="*", apply to all branches
  // 0 means that the branch will not be processed

  //Set branch status
  
  cerr<<endl<<"Setting branch status"<<endl;
  
  //All branches are read by default?
  
  tree0->SetBranchStatus("x", 1);
  tree0->SetBranchStatus("y", 1);
  tree0->SetBranchStatus("z", 1);
  tree0->SetBranchStatus("Px", 1);
  tree0->SetBranchStatus("Py", 1);
  tree0->SetBranchStatus("Pz", 1);
  tree0->SetBranchStatus("t", 1);
  tree0->SetBranchStatus("PDGid", 1);
  tree0->SetBranchStatus("EventID", 1);
  tree0->SetBranchStatus("TrackID", 1);
  /*
  tree0->SetBranchStatus("*",1);
  tree3->SetBranchStatus("*",1);
  treeTar->SetBranchStatus("*",1);
*/
  cerr<<endl<<"finished setting branch status"<<endl;

  //Set branch addresses

  tree0->SetBranchAddress("x", &Det0_x);
  tree0->SetBranchAddress("y", &Det0_y);
  tree0->SetBranchAddress("z", &Det0_z);
  tree0->SetBranchAddress("Px", &Det0_Px);
  tree0->SetBranchAddress("Py", &Det0_Py);
  tree0->SetBranchAddress("Pz", &Det0_Pz);
  tree0->SetBranchAddress("t", &Det0_t);
  tree0->SetBranchAddress("PDGid", &Det0_PDGid);
  tree0->SetBranchAddress("EventID", &Det0_EventID);
  tree0->SetBranchAddress("TrackID", &Det0_TrackID);

  tree3->SetBranchAddress("x", &Det3_x);
  tree3->SetBranchAddress("y", &Det3_y);
  tree3->SetBranchAddress("z", &Det3_z);
  tree3->SetBranchAddress("Px", &Det3_Px);
  tree3->SetBranchAddress("Py", &Det3_Py);
  tree3->SetBranchAddress("Pz", &Det3_Pz);
  tree3->SetBranchAddress("t", &Det3_t);
  tree3->SetBranchAddress("PDGid", &Det3_PDGid);
  tree3->SetBranchAddress("EventID", &Det3_EventID);
  tree3->SetBranchAddress("TrackID", &Det3_TrackID);

cerr<<endl<<"Reading treeTar variables"<<endl;

  treeTar->SetBranchAddress("x", &DetTar_x);
  treeTar->SetBranchAddress("y", &DetTar_y);
  treeTar->SetBranchAddress("z", &DetTar_z);
  treeTar->SetBranchAddress("Px", &DetTar_Px);
  treeTar->SetBranchAddress("Py", &DetTar_Py);
  treeTar->SetBranchAddress("Pz", &DetTar_z);
  treeTar->SetBranchAddress("t", &DetTar_t);
  treeTar->SetBranchAddress("PDGid", &DetTar_PDGid);
  treeTar->SetBranchAddress("EventID", &DetTar_EventID);
  treeTar->SetBranchAddress("TrackID", &DetTar_TrackID);  
  
}
