/////////////////////////////////////////////
// Histograms are defined and created here.
/////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include "TH1.h"
#include "TH2.h"
#include "TROOT.h"
#include "TStyle.h"  //for sStyle
#include "TFile.h"   //for outFile
#include "TGraph.h"
#include "defineHistos.h"
#include "variable.h"

using namespace std;

void defineHistos()
{

  ////////////////Spatial distributions, 1-D

  //in X
  sprintf(name,"xDet0");
  xDet0 = new TH1F(name,name,60,-30,30);
  xDet0->GetXaxis()->SetTitle("x_det0 (mm)");

  sprintf(name,"xDet3");
  xDet3 = new TH1F(name,name,100,-200,100);
  xDet3->GetXaxis()->SetTitle("x_detIFP (mm)");

  sprintf(name,"xDetTar");
  xDetTar = new TH1F(name,name,100,-100,100);
  xDetTar->GetXaxis()->SetTitle("x_detTar (mm)");

  //in y
  sprintf(name,"yDet0");
  yDet0 = new TH1F(name,name,60,-30,30);
  yDet0->GetXaxis()->SetTitle("y_det0 (mm)");

  sprintf(name,"yDet3");
  yDet3 = new TH1F(name,name, 100,-200,200);
  yDet3->GetXaxis()->SetTitle("y_detIFP (mm)");

  sprintf(name,"yDetTar");
  yDetTar = new TH1F(name,name,300,-500,500);
  yDetTar->GetXaxis()->SetTitle("y_detTar (mm)");

  // Spatial distributions, 2-D

  /////////// Momentum distributions, 1-D

}    
  
    
    
