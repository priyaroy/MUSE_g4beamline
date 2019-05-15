/////////////////////////////////
// Write histograms to root file
/////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TMarker.h"
#include "TPaveText.h"
#include "THStack.h"
#include "TLegend.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TGaxis.h"
#include "TLatex.h"
#include "TColor.h"
#include "TMath.h"
#include "TPaletteAxis.h"
#include "histos.h"
#include "variable.h"

using namespace std;

TDirectoryFile *FitDir[500];

TCanvas *Can_Name;
TCanvas *Can_Name1;

//Scale g4beamline plots to match Turtle
float_t scale;

void NewTitle(char *,double ,int, double ,double ,double ,double );

void writeROOT()
{
  cerr << endl << " Writing all histograms to rootfile" << endl;
  
  //TFile *f_out = new TFile("anaMUSE_Roy_orig_PAul_element_positions_GradB_LQSLcorr.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+155_dipoleMagnet_tuned_10Oct.root", "RECREATE");
  
  //TFile *f_out = new TFile("PencilBeam_Dispersion_Studies/anaMUSE_Roy_mu+155MeV_IdealSectorBend_10Oct.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+1551_SectorBendingMagnet_RectBeam_Dispersion_8Nov.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+1551_SectorBendingMagnet_RectBeam_Dispersion_FlatP_11Nov.root", "RECREATE"); //this is with reversed pol for quads in segments 1 &3 compared to Turtle
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+1551_SectorBend_RectBeam_Dispersion_FlatP_sameQuadPol_asTurtle_19Nov.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+1551_SectorBend_RectBeam_Dispersion_FlatP_3mrad_16Nov.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+1551_Fieldmap_Turtle_ASCII_inputBeam_GEMdefined_30Nov.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+1551_Fieldmap_Turtle_ASCII_inputBeam_22Nov.root", "RECREATE");
  
  
  
  //Jan 2019: write mu+ 155 MeV output file
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+_80mmFS11_5mmColl.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+_11mmFS11_5mmColl.root", "RECREATE");
  
  TFile *f_out = new TFile("anaMUSE_Roy_mu+_80mmFS11_105mmColl.root", "RECREATE");
  
  //TFile *f_out = new TFile("anaMUSE_Roy_mu+_11mmFS11_105mmColl.root", "RECREATE");
  
  
  ////////////////////////
  //Defining directories
  ////////////////////////
  
  FitDir[0] = new TDirectoryFile("Det0","Det0");
  FitDir[1] = new TDirectoryFile("Det1","Det1");
  FitDir[2] = new TDirectoryFile("Det2","Det2");
  FitDir[3] = new TDirectoryFile("DetIFP","DetIFP");
  FitDir[4] = new TDirectoryFile("Det4","Det4");
  FitDir[5] = new TDirectoryFile("Det5","Det5");
  FitDir[7] = new TDirectoryFile("DetTar","DetTar");
  FitDir[8] = new TDirectoryFile("Det0a","Det0a");
  FitDir[9] = new TDirectoryFile("DetAQTA1","DetAQTA1");
  FitDir[10] = new TDirectoryFile("DetAQTB1","DetAQTB1");
  FitDir[11] = new TDirectoryFile("DetAQTB2","DetAQTB2"); 
   
   
   //Scale factor to match g4 with Turtle
   
   scale=(37460.0/nentries_Tar);
   
   cerr<<"Scale IFP histograms by "<<scale<<endl;
   
  ////////////////////////
  //Write histograms
  ////////////////////////
  
  // Histograms for detector 0
  FitDir[0] -> cd();
  
  xDet0 -> Write();
  yDet0 -> Write();
  pxDet0 -> Write();
  pyDet0 -> Write();
  pDet0 -> Write();
  dpDet0 -> Write();
  
  pxpy_Det0->Write();
  beamspot_Det0->Write();
  
  xPx_Det0->Write();
  yPy_Det0->Write();
  dpPx_Det0->Write();
  ydp_Det0->Write();
  dpPy_Det0->Write();
  
  dispersion_Det0->Write();
  
  // Histograms for detector 0a
  FitDir[8] -> cd();
  
  xDet0a -> Write();
  yDet0a -> Write();
  pxDet0a -> Write();
  pyDet0a -> Write();
  pDet0a -> Write();
  dpDet0a -> Write();
  
  pxpy_Det0a->Write();
  beamspot_Det0a->Write();
  
  xPx_Det0a->Write();
  yPy_Det0a->Write();
  dpPx_Det0a->Write();
  ydp_Det0a->Write();
  dpPy_Det0a->Write();
  
  dispersion_Det0a->Write();
  
   // Histograms for detector AQTA1
  FitDir[9] -> cd();
  
  xDetAQTA1 -> Write();
  yDetAQTA1 -> Write();
  pxDetAQTA1 -> Write();
  pyDetAQTA1 -> Write();
  pDetAQTA1 -> Write();
  dpDetAQTA1 -> Write();
  
  pxpy_DetAQTA1->Write();
  beamspot_DetAQTA1->Write();
  
  xPx_DetAQTA1->Write();
  yPy_DetAQTA1->Write();
  dpPx_DetAQTA1->Write();
  ydp_DetAQTA1->Write();
  dpPy_DetAQTA1->Write();
  
  dispersion_DetAQTA1->Write();
  
  // Histograms for detector AQTB1
  FitDir[10] -> cd();
  
  xDetAQTB1 -> Write();
  yDetAQTB1 -> Write();
  pxDetAQTB1 -> Write();
  pyDetAQTB1 -> Write();
  pDetAQTB1 -> Write();
  dpDetAQTB1 -> Write();
  
  pxpy_DetAQTB1->Write();
  beamspot_DetAQTB1->Write();
  
  xPx_DetAQTB1->Write();
  yPy_DetAQTB1->Write();
  dpPx_DetAQTB1->Write();
  ydp_DetAQTB1->Write();
  dpPy_DetAQTB1->Write();
  
  dispersion_DetAQTB1->Write();
  
 // Histograms for detector AQTB1
  FitDir[11] -> cd();
  
  xDetAQTB2 -> Write();
  yDetAQTB2 -> Write();
  pxDetAQTB2 -> Write();
  pyDetAQTB2 -> Write();
  pDetAQTB2 -> Write();
  dpDetAQTB2 -> Write();
  
  pxpy_DetAQTB2->Write();
  beamspot_DetAQTB2->Write();
  
  xPx_DetAQTB2->Write();
  yPy_DetAQTB2->Write();
  dpPx_DetAQTB2->Write();
  ydp_DetAQTB2->Write();
  dpPy_DetAQTB2->Write();
  
  dispersion_DetAQTB2->Write();
  
  // Histograms for detector 1 (@ entrance of dipole1)
  FitDir[1] -> cd();
  xDet1 -> Write();
  yDet1 -> Write();
   pxDet1 -> Write();
  pyDet1 -> Write();
  pDet1 -> Write();
  dpDet1 -> Write();
  
  pxpy_Det1->Write();
  beamspot_Det1->Write();
  
  xPx_Det1->Write();
  yPy_Det1->Write();
  dpPx_Det1->Write();
  ydp_Det1->Write();
  dpPy_Det1->Write();
  
  dispersion_Det1->Write();
  
  
  // Histograms for detector 2 (@ exit of dipole 1)
  FitDir[2] -> cd();
  
  xDet2 -> Write();
  yDet2 -> Write();
  pxDet2 -> Write();
  pyDet2 -> Write();
  pDet2-> Write();
  dpDet2 -> Write();
  
  pxpy_Det2->Write();
  beamspot_Det2->Write();
  
  xPx_Det2->Write();
  yPy_Det2->Write();
  dpPx_Det2->Write();
  ydp_Det2->Write();
  dpPy_Det2->Write();
  
  dispersion_Det2->Write();
  
  // Histograms for detector 3 (IFP)
  FitDir[3] -> cd();
  xDet3 -> Write();
  yDet3 -> Write();
  pxDet3 -> Write();
  pyDet3 -> Write();
  pDet3-> Write();
  dpDet3 -> Write();
  
  pxpy_Det3->Write();
  beamspot_Det3->Write();
  
  xPx_Det3->Write();
  yPy_Det3->Write();
  dpPx_Det3->Write();
  ydp_Det3->Write();
  dpPy_Det3->Write();
  
  dispersion_IFP->Write();
  
  // Histograms for detector 4 (start of dipole 2)
  FitDir[4] -> cd();
  
  xDet4 -> Write();
  yDet4 -> Write();
  pxDet4 -> Write();
  pyDet4 -> Write();
  pDet4-> Write();
  dpDet4 -> Write();
  
  pxpy_Det4->Write();
  beamspot_Det4->Write();
  
  xPx_Det4->Write();
  yPy_Det4->Write();
  dpPx_Det4->Write();
  ydp_Det4->Write();
  dpPy_Det4->Write();
  
  dispersion_Det4->Write();
  
  // Histograms for detector 5 (exit of dipole 2)
  FitDir[5] -> cd();
  
  xDet5 -> Write();
  yDet5 -> Write();
  pxDet5 -> Write();
  pyDet5 -> Write();
  pDet5-> Write();
  dpDet5 -> Write();
  
  pxpy_Det5->Write();
  beamspot_Det5->Write();
  
  xPx_Det5->Write();
  yPy_Det5->Write();
  dpPx_Det5->Write();
  ydp_Det5->Write();
  dpPy_Det5->Write();
  
  dispersion_Det5->Write();
  
  // Histograms for detector 7 (@ PiM1 Tar)
  FitDir[7] -> cd();
  
  xDetTar -> Scale(2100/xDetTar->GetMaximum());
  yDetTar -> Scale(1250/yDetTar->GetMaximum());
  pxDetTar -> Scale(1115/pxDetTar->GetMaximum());
  pyDetTar -> Scale(680/pyDetTar->GetMaximum());
  
  xDetTar -> SetLineColor(2);
  yDetTar -> SetLineColor(2);
  pxDetTar -> SetLineColor(2);
  pyDetTar -> SetLineColor(2);
  
  xDetTar -> SetLineWidth(2);
  yDetTar -> SetLineWidth(2);
  pxDetTar -> SetLineWidth(2);
  pyDetTar -> SetLineWidth(2);
  
  xDetTar -> Write();
  yDetTar -> Write();
  pxDetTar -> Write();
  pyDetTar -> Write();
  pDetTar -> Write();
  dpDetTar -> Write();
  
  pxpy_DetTar->Write();
  beamspot_DetTar->Write();
  
  xPx_DetTar->Write();
  yPy_DetTar->Write();
  dpPx_DetTar->Write();
  ydp_DetTar->Write();
  dpPy_DetTar->Write();
  
  dispersion_Tar->Write();
  
  
  ////////////////////////////////////////////////////
  // Make canvases
  ////////////////////////////////////////////////////
  
  //gROOT->SetBatch();
  gROOT->SetStyle("Plain");
  //gStyle->SetOptStat("emr"); //print entries, mean, rms
  gStyle->SetOptStat(0);
  //gStyle -> SetPalette(54);
  gStyle -> SetPalette(54);

  // At production Target ******************************************************
  
  //position and momentum histograms
  
  Can_Name = new TCanvas("xp_Det0", "xp_Det0", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xDet0->SetTitle(0);
  xDet0->SetLabelSize(0.05, "x");
  xDet0->SetLabelSize(0.05, "y");
  xDet0->GetXaxis()->SetTitleSize(0.05);
  xDet0->GetXaxis()->SetTitleOffset(1.0);
  xDet0->SetMinimum(0);
  xDet0->Draw();
  //xDet0->GetXaxis()->SetRangeUser(-0.12, 0.12);
  sprintf(name,"Entries: %.0f", xDet0->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDet0->SetTitle(0);
  pxDet0->SetLabelSize(0.05, "x");
  pxDet0->SetLabelSize(0.05, "y");
  pxDet0->GetXaxis()->SetTitleSize(0.05);
  pxDet0->GetXaxis()->SetTitleOffset(1.0);
  pxDet0->SetMinimum(0);
  pxDet0->Draw();
  //pxDet0->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pxDet0->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDet0->SetTitle(0);
  yDet0->SetLabelSize(0.05, "x");
  yDet0->SetLabelSize(0.05, "y");
  yDet0->GetXaxis()->SetTitleSize(0.05);
  yDet0->GetXaxis()->SetTitleOffset(1.0);
  yDet0->SetMinimum(0);
  yDet0->Draw();
  //yDet0->GetXaxis()->SetRangeUser(-0.12, 0.12);
  sprintf(name,"Entries: %.0f", yDet0->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDet0->SetTitle(0);
  pyDet0->SetLabelSize(0.05, "x");
  pyDet0->SetLabelSize(0.05, "y");
  pyDet0->GetXaxis()->SetTitleSize(0.05);
  pyDet0->GetXaxis()->SetTitleOffset(1.0);
  pyDet0->SetMinimum(0);
  pyDet0->Draw();
  //pyDet0->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pyDet0->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDet0->SetTitle(0);
  dpDet0->SetLabelSize(0.05, "x");
  dpDet0->SetLabelSize(0.05, "y");
  dpDet0->GetXaxis()->SetTitleSize(0.05);
  dpDet0->GetXaxis()->SetTitleOffset(1.0);
  dpDet0->SetMinimum(0);
  dpDet0->Draw();
  //dpDet0->GetXaxis()->SetRangeUser(-2, 2);
  sprintf(name,"Entries: %.0f", dpDet0->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_Det0->SetTitle(0);
  beamspot_Det0->SetLabelSize(0.05, "x");
  beamspot_Det0->SetLabelSize(0.05, "y");
  beamspot_Det0->GetXaxis()->SetTitleSize(0.05);
  beamspot_Det0->GetXaxis()->SetTitleOffset(1.0);
  beamspot_Det0->GetYaxis()->SetTitleOffset(1.1);
  beamspot_Det0->GetYaxis()->SetTitleSize(0.05);
  beamspot_Det0->Draw("colz");
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/Det0_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_Det0", "dpPlots_Det0", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xPx_Det0->SetTitle(0);
  xPx_Det0->SetLabelSize(0.05, "x");
  xPx_Det0->SetLabelSize(0.05, "y");
  xPx_Det0->GetXaxis()->SetTitleSize(0.05);
  xPx_Det0->GetXaxis()->SetTitleOffset(1.0);
  xPx_Det0->GetYaxis()->SetTitleSize(0.05);
  xPx_Det0->GetYaxis()->SetTitleOffset(1.0);
  xPx_Det0->Draw("colz");
    
  Can_Name->cd(2);
  yPy_Det0->SetTitle(0);
  yPy_Det0->SetLabelSize(0.05, "x");
  yPy_Det0->SetLabelSize(0.05, "y");
  yPy_Det0->GetXaxis()->SetTitleSize(0.05);
  yPy_Det0->GetXaxis()->SetTitleOffset(1.0);
  yPy_Det0->GetYaxis()->SetTitleSize(0.05);
  yPy_Det0->GetYaxis()->SetTitleOffset(1.0);
  yPy_Det0->Draw("colz");
  
  Can_Name->cd(3);
  dispersion_Det0->SetTitle(0);
  dispersion_Det0->SetLabelSize(0.05, "x");
  dispersion_Det0->SetLabelSize(0.05, "y");
  dispersion_Det0->GetXaxis()->SetTitleSize(0.05);
  dispersion_Det0->GetXaxis()->SetTitleOffset(1.0);
  dispersion_Det0->GetYaxis()->SetTitleSize(0.05);
  dispersion_Det0->GetYaxis()->SetTitleOffset(1.0);
  dispersion_Det0->Draw("colz");
  
  Can_Name->cd(4);
  dpPx_Det0->SetTitle(0);
  dpPx_Det0->SetLabelSize(0.05, "x");
  dpPx_Det0->SetLabelSize(0.05, "y");
  dpPx_Det0->GetXaxis()->SetTitleSize(0.05);
  dpPx_Det0->GetXaxis()->SetTitleOffset(1.0);
  dpPx_Det0->GetYaxis()->SetTitleSize(0.05);
  dpPx_Det0->GetYaxis()->SetTitleOffset(1.0);
  dpPx_Det0->Draw("colz");
  
  Can_Name->cd(5);
  ydp_Det0->SetTitle(0);
  ydp_Det0->SetLabelSize(0.05, "x");
  ydp_Det0->SetLabelSize(0.05, "y");
  ydp_Det0->GetXaxis()->SetTitleSize(0.05);
  ydp_Det0->GetXaxis()->SetTitleOffset(1.0);
  ydp_Det0->GetYaxis()->SetTitleSize(0.05);
  ydp_Det0->GetYaxis()->SetTitleOffset(1.0);
  ydp_Det0->Draw("colz");
  
  Can_Name->cd(6);
  dpPy_Det0->SetTitle(0);
  dpPy_Det0->SetLabelSize(0.05, "x");
  dpPy_Det0->SetLabelSize(0.05, "y");
  dpPy_Det0->GetXaxis()->SetTitleSize(0.05);
  dpPy_Det0->GetXaxis()->SetTitleOffset(1.0);
  dpPy_Det0->GetYaxis()->SetTitleSize(0.05);
  dpPy_Det0->GetYaxis()->SetTitleOffset(1.0);
  dpPy_Det0->Draw("colz");
  dpPy_Det0->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/Det0_dispersion.eps");
  //sprintf(name,"plots/ASCII_inputBeamTurtle_19Nov2018/withSectorBend/Det0_dispersion.eps");
  Can_Name -> Print(name);

// At start of QTA1 ******************************************************
  
  //position and momentum histograms
  
  Can_Name = new TCanvas("xp_Det0a", "xp_Det0a", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  
  xDet0a -> Scale(600/xDet0a->GetMaximum());
  yDet0a -> Scale(620/yDet0a->GetMaximum());
  pxDet0a -> Scale(550/pxDet0a->GetMaximum());
  pyDet0a -> Scale(620/pyDet0a->GetMaximum());
  dpDet0a -> Scale(680/dpDet0a->GetMaximum());
  
  beamspot_Det0a->Scale(1.5);
  
  Can_Name->cd(1);
  xDet0a->SetTitle(0);
  xDet0a->SetLabelSize(0.05, "x");
  xDet0a->SetLabelSize(0.05, "y");
  xDet0a->SetLineColor(2);
  xDet0a->SetLineWidth(1);
  xDet0a->GetXaxis()->SetTitleSize(0.05);
  xDet0a->GetXaxis()->SetTitleOffset(1.0);
  xDet0a->SetMinimum(0);
  xDet0a->Draw();
  xDet0a->GetXaxis()->SetRangeUser(-3.2, 3.2);
  xDet0a->GetYaxis()->SetRangeUser(0., 620);
  //sprintf(name,"Entries: %.0f", xDet0a->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDet0a->SetTitle(0);
  pxDet0a->SetLabelSize(0.05, "x");
  pxDet0a->SetLabelSize(0.05, "y");
  pxDet0a->SetLineColor(2);
  pxDet0a->SetLineWidth(1);
  pxDet0a->GetXaxis()->SetTitleSize(0.05);
  pxDet0a->GetXaxis()->SetTitleOffset(1.0);
  pxDet0a->SetMinimum(0);
  pxDet0a->Draw();
  pxDet0a->GetYaxis()->SetRangeUser(0, 580);
  //sprintf(name,"Entries: %.0f", pxDet0a->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDet0a->SetTitle(0);
  yDet0a->SetLabelSize(0.05, "x");
  yDet0a->SetLabelSize(0.05, "y");
  yDet0a->SetLineColor(2);
  yDet0a->SetLineWidth(1);
  yDet0a->GetXaxis()->SetTitleSize(0.05);
  yDet0a->GetXaxis()->SetTitleOffset(1.0);
  yDet0a->SetMinimum(0);
  yDet0a->Draw();
  yDet0a->GetYaxis()->SetRangeUser(0, 670);
  //sprintf(name,"Entries: %.0f", yDet0a->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDet0a->SetTitle(0);
  pyDet0a->SetLabelSize(0.05, "x");
  pyDet0a->SetLabelSize(0.05, "y");
  pyDet0a->SetLineColor(2);
  pyDet0a->SetLineWidth(1);
  pyDet0a->GetXaxis()->SetTitleSize(0.05);
  pyDet0a->GetXaxis()->SetTitleOffset(1.0);
  pyDet0a->SetMinimum(0);
  pyDet0a->Draw();
  pyDet0a->GetYaxis()->SetRangeUser(0, 670);
  //sprintf(name,"Entries: %.0f", pyDet0a->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDet0a->SetTitle(0);
  dpDet0a->SetLabelSize(0.05, "x");
  dpDet0a->SetLabelSize(0.05, "y");
  dpDet0a->SetLineColor(2);
  dpDet0a->SetLineWidth(1);
  dpDet0a->GetXaxis()->SetTitleSize(0.05);
  dpDet0a->GetXaxis()->SetTitleOffset(1.0);
  dpDet0a->SetMinimum(0);
  dpDet0a->Draw();
  dpDet0a->GetYaxis()->SetRangeUser(0, 700);
  //sprintf(name,"Entries: %.0f", dpDet0a->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_Det0a->SetTitle(0);
  beamspot_Det0a->SetLabelSize(0.05, "x");
  beamspot_Det0a->SetLabelSize(0.05, "y");
  beamspot_Det0a->GetXaxis()->SetTitleSize(0.05);
  beamspot_Det0a->GetXaxis()->SetTitleOffset(1.0);
  beamspot_Det0a->GetYaxis()->SetTitleOffset(1.1);
  beamspot_Det0a->GetYaxis()->SetTitleSize(0.05);
  beamspot_Det0a->Draw("colz");
  //beamspot_Det0a->GetXaxis()->SetRangeUser(-3.2, 3.2);
  //beamspot_Det0a->GetYaxis()->SetRangeUser(-8.2, 8.2);
  
  Can_Name->Write();
  sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/Det0a_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_Det0a", "dpPlots_Det0a", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  //TGaxis::SetMaxDigits(4);
  xPx_Det0a -> Scale(1.5);
  yPy_Det0a -> Scale(1.5);
  dispersion_Det0a -> Scale(1.5);
  dpPx_Det0a -> Scale(1.5);
  ydp_Det0a -> Scale(1.5);
  dpPy_Det0a->Scale(1.5);
  
  Can_Name->cd(1);
  xPx_Det0a->SetTitle(0);
  xPx_Det0a->SetLabelSize(0.05, "x");
  xPx_Det0a->SetLabelSize(0.05, "y");
  xPx_Det0a->GetXaxis()->SetTitleSize(0.05);
  xPx_Det0a->GetXaxis()->SetTitleOffset(1.0);
  xPx_Det0a->GetYaxis()->SetTitleSize(0.05);
  xPx_Det0a->GetYaxis()->SetTitleOffset(1.0);
  xPx_Det0a->Draw("colz");
    
  Can_Name->cd(2);
  yPy_Det0a->SetTitle(0);
  yPy_Det0a->SetLabelSize(0.05, "x");
  yPy_Det0a->SetLabelSize(0.05, "y");
  yPy_Det0a->GetXaxis()->SetTitleSize(0.05);
  yPy_Det0a->GetXaxis()->SetTitleOffset(1.0);
  yPy_Det0a->GetYaxis()->SetTitleSize(0.05);
  yPy_Det0a->GetYaxis()->SetTitleOffset(1.0);
  yPy_Det0a->Draw("colz");
  //yPy_Det0a->GetXaxis()->SetRangeUser(-8.2, 8.2);
  //yPy_Det0a->GetYaxis()->SetRangeUser(-0.55, 0.55);
  
  Can_Name->cd(3);
  dispersion_Det0a->SetTitle(0);
  dispersion_Det0a->SetLabelSize(0.05, "x");
  dispersion_Det0a->SetLabelSize(0.05, "y");
  dispersion_Det0a->GetXaxis()->SetTitleSize(0.05);
  dispersion_Det0a->GetXaxis()->SetTitleOffset(1.0);
  dispersion_Det0a->GetYaxis()->SetTitleSize(0.05);
  dispersion_Det0a->GetYaxis()->SetTitleOffset(1.0);
  dispersion_Det0a->Draw("colz");
  //dispersion_Det0a->GetXaxis()->SetRangeUser(-3.2, 3.2);
  //dispersion_Det0a->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(4);
  dpPx_Det0a->SetTitle(0);
  dpPx_Det0a->SetLabelSize(0.05, "x");
  dpPx_Det0a->SetLabelSize(0.05, "y");
  dpPx_Det0a->GetXaxis()->SetTitleSize(0.05);
  dpPx_Det0a->GetXaxis()->SetTitleOffset(1.0);
  dpPx_Det0a->GetYaxis()->SetTitleSize(0.05);
  dpPx_Det0a->GetYaxis()->SetTitleOffset(1.0);
  dpPx_Det0a->Draw("colz");
  //dpPx_Det0a->GetXaxis()->SetRangeUser(-0.55, 0.55);
  //dpPx_Det0a->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(5);
  ydp_Det0a->SetTitle(0);
  ydp_Det0a->SetLabelSize(0.05, "x");
  ydp_Det0a->SetLabelSize(0.05, "y");
  ydp_Det0a->GetXaxis()->SetTitleSize(0.05);
  ydp_Det0a->GetXaxis()->SetTitleOffset(1.0);
  ydp_Det0a->GetYaxis()->SetTitleSize(0.05);
  ydp_Det0a->GetYaxis()->SetTitleOffset(1.0);
  ydp_Det0a->Draw("colz");
  //ydp_Det0a->GetXaxis()->SetRangeUser(-0.12, 0.12);
  //ydp_Det0a->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(6);
  dpPy_Det0a->SetTitle(0);
  dpPy_Det0a->SetLabelSize(0.05, "x");
  dpPy_Det0a->SetLabelSize(0.05, "y");
  dpPy_Det0a->GetXaxis()->SetTitleSize(0.05);
  dpPy_Det0a->GetXaxis()->SetTitleOffset(1.0);
  dpPy_Det0a->GetYaxis()->SetTitleSize(0.05);
  dpPy_Det0a->GetYaxis()->SetTitleOffset(1.0);
  dpPy_Det0a->Draw("colz");
  //dpPy_Det0a->GetXaxis()->SetRangeUser(-0.55, 0.55);
  //dpPy_Det0a->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->Write();
  sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/Det0a_dispersion.eps");
  Can_Name -> Print(name);
  
  // Between QTA1 and QTB1******************************************************
  
  //position and momentum histograms
  
  Can_Name = new TCanvas("xp_DetAQTA1", "xp_DetAQTA1", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xDetAQTA1->SetTitle(0);
  xDetAQTA1->SetLabelSize(0.05, "x");
  xDetAQTA1->SetLabelSize(0.05, "y");
  xDetAQTA1->GetXaxis()->SetTitleSize(0.05);
  xDetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  xDetAQTA1->SetMinimum(0);
  xDetAQTA1->Draw();
  xDetAQTA1->GetXaxis()->SetRangeUser(-5, 5);
  sprintf(name,"Entries: %.0f", xDetAQTA1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDetAQTA1->SetTitle(0);
  pxDetAQTA1->SetLabelSize(0.05, "x");
  pxDetAQTA1->SetLabelSize(0.05, "y");
  pxDetAQTA1->GetXaxis()->SetTitleSize(0.05);
  pxDetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  pxDetAQTA1->SetMinimum(0);
  pxDetAQTA1->Draw();
  //pxDetAQTA1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pxDetAQTA1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDetAQTA1->SetTitle(0);
  yDetAQTA1->SetLabelSize(0.05, "x");
  yDetAQTA1->SetLabelSize(0.05, "y");
  yDetAQTA1->GetXaxis()->SetTitleSize(0.05);
  yDetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  yDetAQTA1->SetMinimum(0);
  yDetAQTA1->Draw();
  yDetAQTA1->GetXaxis()->SetRangeUser(-10, 10);
  sprintf(name,"Entries: %.0f", yDetAQTA1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDetAQTA1->SetTitle(0);
  pyDetAQTA1->SetLabelSize(0.05, "x");
  pyDetAQTA1->SetLabelSize(0.05, "y");
  pyDetAQTA1->GetXaxis()->SetTitleSize(0.05);
  pyDetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  pyDetAQTA1->SetMinimum(0);
  pyDetAQTA1->Draw();
  //pyDetAQTA1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pyDetAQTA1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDetAQTA1->SetTitle(0);
  dpDetAQTA1->SetLabelSize(0.05, "x");
  dpDetAQTA1->SetLabelSize(0.05, "y");
  dpDetAQTA1->GetXaxis()->SetTitleSize(0.05);
  dpDetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  dpDetAQTA1->SetMinimum(0);
  dpDetAQTA1->Draw();
  dpDetAQTA1->GetXaxis()->SetRangeUser(-1.7, 1.7);
  sprintf(name,"Entries: %.0f", dpDetAQTA1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_DetAQTA1->SetTitle(0);
  beamspot_DetAQTA1->SetLabelSize(0.05, "x");
  beamspot_DetAQTA1->SetLabelSize(0.05, "y");
  beamspot_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  beamspot_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  beamspot_DetAQTA1->GetYaxis()->SetTitleOffset(1.1);
  beamspot_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  beamspot_DetAQTA1->Draw("colz");
  beamspot_DetAQTA1->GetXaxis()->SetRangeUser(-5, 5);
  beamspot_DetAQTA1->GetYaxis()->SetRangeUser(-10, 10);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/DetAQTA1_phaseSpace.eps");
  //sprintf(name,"plots/ASCII_inputBeamTurtle_19Nov2018/withFieldMap/withSectorBend/DetAQTA1_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_DetAQTA1", "dpPlots_DetAQTA1", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xPx_DetAQTA1->SetTitle(0);
  xPx_DetAQTA1->SetLabelSize(0.05, "x");
  xPx_DetAQTA1->SetLabelSize(0.05, "y");
  xPx_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  xPx_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  xPx_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  xPx_DetAQTA1->GetYaxis()->SetTitleOffset(1.0);
  xPx_DetAQTA1->Draw("colz");
  xPx_DetAQTA1->GetXaxis()->SetRangeUser(-5, 5);
  //xPx_DetAQTA1->GetYaxis()->SetRangeUser(-0.55, 0.55);
    
  Can_Name->cd(2);
  yPy_DetAQTA1->SetTitle(0);
  yPy_DetAQTA1->SetLabelSize(0.05, "x");
  yPy_DetAQTA1->SetLabelSize(0.05, "y");
  yPy_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  yPy_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  yPy_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  yPy_DetAQTA1->GetYaxis()->SetTitleOffset(1.0);
  yPy_DetAQTA1->Draw("colz");
  yPy_DetAQTA1->GetXaxis()->SetRangeUser(-10, 10);
  //yPy_DetAQTA1->GetYaxis()->SetRangeUser(-0.55, 0.55);
  
  Can_Name->cd(3);
  dispersion_DetAQTA1->SetTitle(0);
  dispersion_DetAQTA1->SetLabelSize(0.05, "x");
  dispersion_DetAQTA1->SetLabelSize(0.05, "y");
  dispersion_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  dispersion_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  dispersion_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  dispersion_DetAQTA1->GetYaxis()->SetTitleOffset(1.0);
  dispersion_DetAQTA1->Draw("colz");
  dispersion_DetAQTA1->GetXaxis()->SetRangeUser(-5, 5);
  dispersion_DetAQTA1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(4);
  dpPx_DetAQTA1->SetTitle(0);
  dpPx_DetAQTA1->SetLabelSize(0.05, "x");
  dpPx_DetAQTA1->SetLabelSize(0.05, "y");
  dpPx_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  dpPx_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  dpPx_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  dpPx_DetAQTA1->GetYaxis()->SetTitleOffset(1.0);
  dpPx_DetAQTA1->Draw("colz");
  //dpPx_DetAQTA1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  dpPx_DetAQTA1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(5);
  ydp_DetAQTA1->SetTitle(0);
  ydp_DetAQTA1->SetLabelSize(0.05, "x");
  ydp_DetAQTA1->SetLabelSize(0.05, "y");
  ydp_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  ydp_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  ydp_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  ydp_DetAQTA1->GetYaxis()->SetTitleOffset(1.0);
  ydp_DetAQTA1->Draw("colz");
  ydp_DetAQTA1->GetXaxis()->SetRangeUser(-10, 10);
  ydp_DetAQTA1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(6);
  dpPy_DetAQTA1->SetTitle(0);
  dpPy_DetAQTA1->SetLabelSize(0.05, "x");
  dpPy_DetAQTA1->SetLabelSize(0.05, "y");
  dpPy_DetAQTA1->GetXaxis()->SetTitleSize(0.05);
  dpPy_DetAQTA1->GetXaxis()->SetTitleOffset(1.0);
  dpPy_DetAQTA1->GetYaxis()->SetTitleSize(0.05);
  dpPy_DetAQTA1->GetYaxis()->SetTitleOffset(1.0);
  dpPy_DetAQTA1->Draw("colz");
  //dpPy_DetAQTA1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  dpPy_DetAQTA1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/DetAQTA1_dispersion.eps");
  Can_Name -> Print(name);
    
  // Between QTB1 and QTB2******************************************************
  
  //position and angle histograms
  
  Can_Name = new TCanvas("xp_DetAQTB1", "xp_DetAQTB1", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xDetAQTB1->SetTitle(0);
  xDetAQTB1->SetLabelSize(0.05, "x");
  xDetAQTB1->SetLabelSize(0.05, "y");
  xDetAQTB1->GetXaxis()->SetTitleSize(0.05);
  xDetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  xDetAQTB1->SetMinimum(0);
  xDetAQTB1->Draw();
  //xDetAQTB1->GetXaxis()->SetRangeUser(-5, 5);
  sprintf(name,"Entries: %.0f", xDetAQTB1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDetAQTB1->SetTitle(0);
  pxDetAQTB1->SetLabelSize(0.05, "x");
  pxDetAQTB1->SetLabelSize(0.05, "y");
  pxDetAQTB1->GetXaxis()->SetTitleSize(0.05);
  pxDetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  pxDetAQTB1->SetMinimum(0);
  pxDetAQTB1->Draw();
  //pxDetAQTA1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pxDetAQTB1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDetAQTB1->SetTitle(0);
  yDetAQTB1->SetLabelSize(0.05, "x");
  yDetAQTB1->SetLabelSize(0.05, "y");
  yDetAQTB1->GetXaxis()->SetTitleSize(0.05);
  yDetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  yDetAQTB1->SetMinimum(0);
  yDetAQTB1->Draw();
  //yDetAQTB1->GetXaxis()->SetRangeUser(-10, 10);
  sprintf(name,"Entries: %.0f", yDetAQTB1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDetAQTB1->SetTitle(0);
  pyDetAQTB1->SetLabelSize(0.05, "x");
  pyDetAQTB1->SetLabelSize(0.05, "y");
  pyDetAQTB1->GetXaxis()->SetTitleSize(0.05);
  pyDetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  pyDetAQTB1->SetMinimum(0);
  pyDetAQTB1->Draw();
  //pyDetAQTB1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pyDetAQTB1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDetAQTB1->SetTitle(0);
  dpDetAQTB1->SetLabelSize(0.05, "x");
  dpDetAQTB1->SetLabelSize(0.05, "y");
  dpDetAQTB1->GetXaxis()->SetTitleSize(0.05);
  dpDetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  dpDetAQTB1->SetMinimum(0);
  dpDetAQTB1->Draw();
  dpDetAQTB1->GetXaxis()->SetRangeUser(-1.7, 1.7);
  sprintf(name,"Entries: %.0f", dpDetAQTB1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_DetAQTB1->SetTitle(0);
  beamspot_DetAQTB1->SetLabelSize(0.05, "x");
  beamspot_DetAQTB1->SetLabelSize(0.05, "y");
  beamspot_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  beamspot_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  beamspot_DetAQTB1->GetYaxis()->SetTitleOffset(1.1);
  beamspot_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  beamspot_DetAQTB1->Draw("colz");
  //beamspot_DetAQTB1->GetXaxis()->SetRangeUser(-5, 5);
  //beamspot_DetAQTB1->GetYaxis()->SetRangeUser(-10, 10);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/DetAQTB1_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_DetAQTB1", "dpPlots_DetAQTB1", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xPx_DetAQTB1->SetTitle(0);
  xPx_DetAQTB1->SetLabelSize(0.05, "x");
  xPx_DetAQTB1->SetLabelSize(0.05, "y");
  xPx_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  xPx_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  xPx_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  xPx_DetAQTB1->GetYaxis()->SetTitleOffset(1.0);
  xPx_DetAQTB1->Draw("colz");
  //xPx_DetAQTB1->GetXaxis()->SetRangeUser(-5, 5);
  //xPx_DetAQTB1->GetYaxis()->SetRangeUser(-0.55, 0.55);
    
  Can_Name->cd(2);
  yPy_DetAQTB1->SetTitle(0);
  yPy_DetAQTB1->SetLabelSize(0.05, "x");
  yPy_DetAQTB1->SetLabelSize(0.05, "y");
  yPy_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  yPy_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  yPy_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  yPy_DetAQTB1->GetYaxis()->SetTitleOffset(1.0);
  yPy_DetAQTB1->Draw("colz");
  //yPy_DetAQTB1->GetXaxis()->SetRangeUser(-10, 10);
  //yPy_DetAQTB1->GetYaxis()->SetRangeUser(-0.55, 0.55);
  
  Can_Name->cd(3);
  dispersion_DetAQTB1->SetTitle(0);
  dispersion_DetAQTB1->SetLabelSize(0.05, "x");
  dispersion_DetAQTB1->SetLabelSize(0.05, "y");
  dispersion_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  dispersion_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  dispersion_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  dispersion_DetAQTB1->GetYaxis()->SetTitleOffset(1.0);
  dispersion_DetAQTB1->Draw("colz");
  //dispersion_DetAQTB1->GetXaxis()->SetRangeUser(-5, 5);
  dispersion_DetAQTB1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(4);
  dpPx_DetAQTB1->SetTitle(0);
  dpPx_DetAQTB1->SetLabelSize(0.05, "x");
  dpPx_DetAQTB1->SetLabelSize(0.05, "y");
  dpPx_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  dpPx_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  dpPx_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  dpPx_DetAQTB1->GetYaxis()->SetTitleOffset(1.0);
  dpPx_DetAQTB1->Draw("colz");
  //dpPx_DetAQTB1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  dpPx_DetAQTB1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(5);
  ydp_DetAQTB1->SetTitle(0);
  ydp_DetAQTB1->SetLabelSize(0.05, "x");
  ydp_DetAQTB1->SetLabelSize(0.05, "y");
  ydp_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  ydp_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  ydp_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  ydp_DetAQTB1->GetYaxis()->SetTitleOffset(1.0);
  ydp_DetAQTB1->Draw("colz");
  //ydp_DetAQTB1->GetXaxis()->SetRangeUser(-10, 10);
  ydp_DetAQTB1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(6);
  dpPy_DetAQTB1->SetTitle(0);
  dpPy_DetAQTB1->SetLabelSize(0.05, "x");
  dpPy_DetAQTB1->SetLabelSize(0.05, "y");
  dpPy_DetAQTB1->GetXaxis()->SetTitleSize(0.05);
  dpPy_DetAQTB1->GetXaxis()->SetTitleOffset(1.0);
  dpPy_DetAQTB1->GetYaxis()->SetTitleSize(0.05);
  dpPy_DetAQTB1->GetYaxis()->SetTitleOffset(1.0);
  dpPy_DetAQTB1->Draw("colz");
  //dpPy_DetAQTB1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  dpPy_DetAQTB1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/DetAQTB1_dispersion.eps");
  Can_Name -> Print(name);
  
  // End of QTB2******************************************************
  
  //position and angle histograms
  
  Can_Name = new TCanvas("xp_DetAQTB2", "xp_DetAQTB2", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xDetAQTB2->SetTitle(0);
  xDetAQTB2->SetLabelSize(0.05, "x");
  xDetAQTB2->SetLabelSize(0.05, "y");
  xDetAQTB2->GetXaxis()->SetTitleSize(0.05);
  xDetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  xDetAQTB2->SetMinimum(0);
  xDetAQTB2->Draw();
  //xDetAQTB2->GetXaxis()->SetRangeUser(-5, 5);
  sprintf(name,"Entries: %.0f", xDetAQTB2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDetAQTB2->SetTitle(0);
  pxDetAQTB2->SetLabelSize(0.05, "x");
  pxDetAQTB2->SetLabelSize(0.05, "y");
  pxDetAQTB2->GetXaxis()->SetTitleSize(0.05);
  pxDetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  pxDetAQTB2->SetMinimum(0);
  pxDetAQTB2->Draw();
  //pxDetAQTB2->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pxDetAQTB2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDetAQTB2->SetTitle(0);
  yDetAQTB2->SetLabelSize(0.05, "x");
  yDetAQTB2->SetLabelSize(0.05, "y");
  yDetAQTB2->GetXaxis()->SetTitleSize(0.05);
  yDetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  yDetAQTB2->SetMinimum(0);
  yDetAQTB2->Draw();
  //yDetAQTB2->GetXaxis()->SetRangeUser(-10, 10);
  sprintf(name,"Entries: %.0f", yDetAQTB2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDetAQTB2->SetTitle(0);
  pyDetAQTB2->SetLabelSize(0.05, "x");
  pyDetAQTB2->SetLabelSize(0.05, "y");
  pyDetAQTB2->GetXaxis()->SetTitleSize(0.05);
  pyDetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  pyDetAQTB2->SetMinimum(0);
  pyDetAQTB2->Draw();
  //pyDetAQTB2->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pyDetAQTB2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDetAQTB2->SetTitle(0);
  dpDetAQTB2->SetLabelSize(0.05, "x");
  dpDetAQTB2->SetLabelSize(0.05, "y");
  dpDetAQTB2->GetXaxis()->SetTitleSize(0.05);
  dpDetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  dpDetAQTB2->SetMinimum(0);
  dpDetAQTB2->Draw();
  dpDetAQTB2->GetXaxis()->SetRangeUser(-1.7, 1.7);
  sprintf(name,"Entries: %.0f", dpDetAQTB2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_DetAQTB2->SetTitle(0);
  beamspot_DetAQTB2->SetLabelSize(0.05, "x");
  beamspot_DetAQTB2->SetLabelSize(0.05, "y");
  beamspot_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  beamspot_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  beamspot_DetAQTB2->GetYaxis()->SetTitleOffset(1.1);
  beamspot_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  beamspot_DetAQTB2->Draw("colz");
  //beamspot_DetAQTB2->GetXaxis()->SetRangeUser(-5, 5);
  //beamspot_DetAQTB2->GetYaxis()->SetRangeUser(-10, 10);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/DetAQTB2_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_DetAQTB2", "dpPlots_DetAQTB2", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xPx_DetAQTB2->SetTitle(0);
  xPx_DetAQTB2->SetLabelSize(0.05, "x");
  xPx_DetAQTB2->SetLabelSize(0.05, "y");
  xPx_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  xPx_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  xPx_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  xPx_DetAQTB2->GetYaxis()->SetTitleOffset(1.0);
  xPx_DetAQTB2->Draw("colz");
  //xPx_DetAQTB2->GetXaxis()->SetRangeUser(-5, 5);
  //xPx_DetAQTB2->GetYaxis()->SetRangeUser(-0.55, 0.55);
    
  Can_Name->cd(2);
  yPy_DetAQTB2->SetTitle(0);
  yPy_DetAQTB2->SetLabelSize(0.05, "x");
  yPy_DetAQTB2->SetLabelSize(0.05, "y");
  yPy_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  yPy_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  yPy_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  yPy_DetAQTB2->GetYaxis()->SetTitleOffset(1.0);
  yPy_DetAQTB2->Draw("colz");
  //yPy_DetAQTB2->GetXaxis()->SetRangeUser(-10, 10);
  //yPy_DetAQTB2->GetYaxis()->SetRangeUser(-0.55, 0.55);
  
  Can_Name->cd(3);
  dispersion_DetAQTB2->SetTitle(0);
  dispersion_DetAQTB2->SetLabelSize(0.05, "x");
  dispersion_DetAQTB2->SetLabelSize(0.05, "y");
  dispersion_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  dispersion_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  dispersion_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  dispersion_DetAQTB2->GetYaxis()->SetTitleOffset(1.0);
  dispersion_DetAQTB2->Draw("colz");
  //dispersion_DetAQTB2->GetXaxis()->SetRangeUser(-5, 5);
  dispersion_DetAQTB2->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(4);
  dpPx_DetAQTB2->SetTitle(0);
  dpPx_DetAQTB2->SetLabelSize(0.05, "x");
  dpPx_DetAQTB2->SetLabelSize(0.05, "y");
  dpPx_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  dpPx_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  dpPx_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  dpPx_DetAQTB2->GetYaxis()->SetTitleOffset(1.0);
  dpPx_DetAQTB2->Draw("colz");
  //dpPx_DetAQTB2->GetXaxis()->SetRangeUser(-0.55, 0.55);
  dpPx_DetAQTB2->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(5);
  ydp_DetAQTB2->SetTitle(0);
  ydp_DetAQTB2->SetLabelSize(0.05, "x");
  ydp_DetAQTB2->SetLabelSize(0.05, "y");
  ydp_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  ydp_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  ydp_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  ydp_DetAQTB2->GetYaxis()->SetTitleOffset(1.0);
  ydp_DetAQTB2->Draw("colz");
  //ydp_DetAQTB2->GetXaxis()->SetRangeUser(-10, 10);
  ydp_DetAQTB2->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(6);
  dpPy_DetAQTB2->SetTitle(0);
  dpPy_DetAQTB2->SetLabelSize(0.05, "x");
  dpPy_DetAQTB2->SetLabelSize(0.05, "y");
  dpPy_DetAQTB2->GetXaxis()->SetTitleSize(0.05);
  dpPy_DetAQTB2->GetXaxis()->SetTitleOffset(1.0);
  dpPy_DetAQTB2->GetYaxis()->SetTitleSize(0.05);
  dpPy_DetAQTB2->GetYaxis()->SetTitleOffset(1.0);
  dpPy_DetAQTB2->Draw("colz");
  //dpPy_DetAQTB2->GetXaxis()->SetRangeUser(-0.55, 0.55);
  dpPy_DetAQTB2->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/DetAQTB2_dispersion.eps");
  Can_Name -> Print(name);
  
  // start of dipole 1******************************************************
  
  //position and angle histograms
  
  Can_Name = new TCanvas("xp_Det1", "xp_Det1", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xDet1->SetTitle(0);
  xDet1->SetLabelSize(0.05, "x");
  xDet1->SetLabelSize(0.05, "y");
  xDet1->GetXaxis()->SetTitleSize(0.05);
  xDet1->GetXaxis()->SetTitleOffset(1.0);
  xDet1->SetMinimum(0);
  xDet1->Draw();
  //xDet1->GetXaxis()->SetRangeUser(-5, 5);
  sprintf(name,"Entries: %.0f", xDet1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDet1->SetTitle(0);
  pxDet1->SetLabelSize(0.05, "x");
  pxDet1->SetLabelSize(0.05, "y");
  pxDet1->GetXaxis()->SetTitleSize(0.05);
  pxDet1->GetXaxis()->SetTitleOffset(1.0);
  pxDet1->SetMinimum(0);
  pxDet1->Draw();
  //pxDet1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pxDet1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDet1->SetTitle(0);
  yDet1->SetLabelSize(0.05, "x");
  yDet1->SetLabelSize(0.05, "y");
  yDet1->GetXaxis()->SetTitleSize(0.05);
  yDet1->GetXaxis()->SetTitleOffset(1.0);
  yDet1->SetMinimum(0);
  yDet1->Draw();
  //yDet1->GetXaxis()->SetRangeUser(-10, 10);
  sprintf(name,"Entries: %.0f", yDet1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDet1->SetTitle(0);
  pyDet1->SetLabelSize(0.05, "x");
  pyDet1->SetLabelSize(0.05, "y");
  pyDet1->GetXaxis()->SetTitleSize(0.05);
  pyDet1->GetXaxis()->SetTitleOffset(1.0);
  pyDet1->SetMinimum(0);
  pyDet1->Draw();
  //pyDet1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  sprintf(name,"Entries: %.0f", pyDet1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDet1->SetTitle(0);
  dpDet1->SetLabelSize(0.05, "x");
  dpDet1->SetLabelSize(0.05, "y");
  dpDet1->GetXaxis()->SetTitleSize(0.05);
  dpDet1->GetXaxis()->SetTitleOffset(1.0);
  dpDet1->SetMinimum(0);
  dpDet1->Draw();
  //dpDet1->GetXaxis()->SetRangeUser(-1.7, 1.7);
  sprintf(name,"Entries: %.0f", dpDet1->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_Det1->SetTitle(0);
  beamspot_Det1->SetLabelSize(0.05, "x");
  beamspot_Det1->SetLabelSize(0.05, "y");
  beamspot_Det1->GetXaxis()->SetTitleSize(0.05);
  beamspot_Det1->GetXaxis()->SetTitleOffset(1.0);
  beamspot_Det1->GetYaxis()->SetTitleOffset(1.1);
  beamspot_Det1->GetYaxis()->SetTitleSize(0.05);
  beamspot_Det1->Draw("colz");
  //beamspot_Det1->GetXaxis()->SetRangeUser(-5, 5);
  //beamspot_Det1->GetYaxis()->SetRangeUser(-10, 10);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/StartDipole1_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_Det1", "dpPlots_Det1", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xPx_Det1->SetTitle(0);
  xPx_Det1->SetLabelSize(0.05, "x");
  xPx_Det1->SetLabelSize(0.05, "y");
  xPx_Det1->GetXaxis()->SetTitleSize(0.05);
  xPx_Det1->GetXaxis()->SetTitleOffset(1.0);
  xPx_Det1->GetYaxis()->SetTitleSize(0.05);
  xPx_Det1->GetYaxis()->SetTitleOffset(1.0);
  xPx_Det1->Draw("colz");
  //xPx_Det1->GetXaxis()->SetRangeUser(-5, 5);
  //xPx_Det1->GetYaxis()->SetRangeUser(-0.55, 0.55);
    
  Can_Name->cd(2);
  yPy_Det1->SetTitle(0);
  yPy_Det1->SetLabelSize(0.05, "x");
  yPy_Det1->SetLabelSize(0.05, "y");
  yPy_Det1->GetXaxis()->SetTitleSize(0.05);
  yPy_Det1->GetXaxis()->SetTitleOffset(1.0);
  yPy_Det1->GetYaxis()->SetTitleSize(0.05);
  yPy_Det1->GetYaxis()->SetTitleOffset(1.0);
  yPy_Det1->Draw("colz");
  //yPy_Det1->GetXaxis()->SetRangeUser(-10, 10);
  //yPy_Det1->GetYaxis()->SetRangeUser(-0.55, 0.55);
  
  Can_Name->cd(3);
  dispersion_Det1->SetTitle(0);
  dispersion_Det1->SetLabelSize(0.05, "x");
  dispersion_Det1->SetLabelSize(0.05, "y");
  dispersion_Det1->GetXaxis()->SetTitleSize(0.05);
  dispersion_Det1->GetXaxis()->SetTitleOffset(1.0);
  dispersion_Det1->GetYaxis()->SetTitleSize(0.05);
  dispersion_Det1->GetYaxis()->SetTitleOffset(1.0);
  dispersion_Det1->Draw("colz");
  //dispersion_Det1->GetXaxis()->SetRangeUser(-5, 5);
  //dispersion_Det1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(4);
  dpPx_Det1->SetTitle(0);
  dpPx_Det1->SetLabelSize(0.05, "x");
  dpPx_Det1->SetLabelSize(0.05, "y");
  dpPx_Det1->GetXaxis()->SetTitleSize(0.05);
  dpPx_Det1->GetXaxis()->SetTitleOffset(1.0);
  dpPx_Det1->GetYaxis()->SetTitleSize(0.05);
  dpPx_Det1->GetYaxis()->SetTitleOffset(1.0);
  dpPx_Det1->Draw("colz");
  //dpPx_Det1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  //dpPx_Det1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(5);
  ydp_Det1->SetTitle(0);
  ydp_Det1->SetLabelSize(0.05, "x");
  ydp_Det1->SetLabelSize(0.05, "y");
  ydp_Det1->GetXaxis()->SetTitleSize(0.05);
  ydp_Det1->GetXaxis()->SetTitleOffset(1.0);
  ydp_Det1->GetYaxis()->SetTitleSize(0.05);
  ydp_Det1->GetYaxis()->SetTitleOffset(1.0);
  ydp_Det1->Draw("colz");
  //ydp_Det1->GetXaxis()->SetRangeUser(-10, 10);
  //ydp_Det1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->cd(6);
  dpPy_Det1->SetTitle(0);
  dpPy_Det1->SetLabelSize(0.05, "x");
  dpPy_Det1->SetLabelSize(0.05, "y");
  dpPy_Det1->GetXaxis()->SetTitleSize(0.05);
  dpPy_Det1->GetXaxis()->SetTitleOffset(1.0);
  dpPy_Det1->GetYaxis()->SetTitleSize(0.05);
  dpPy_Det1->GetYaxis()->SetTitleOffset(1.0);
  dpPy_Det1->Draw("colz");
  //dpPy_Det1->GetXaxis()->SetRangeUser(-0.55, 0.55);
  //dpPy_Det1->GetYaxis()->SetRangeUser(-1.7, 1.7);
  
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/StartDipole1_dispersion.eps");
  Can_Name -> Print(name);
  
  // end of dipole 1******************************************************
  
  //position and angle histograms
  
  Can_Name = new TCanvas("xp_Det2", "xp_Det2", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xDet2->SetTitle(0);
  xDet2->SetLabelSize(0.05, "x");
  xDet2->SetLabelSize(0.05, "y");
  xDet2->GetXaxis()->SetTitleSize(0.05);
  xDet2->GetXaxis()->SetTitleOffset(1.0);
  xDet2->SetMinimum(0);
  xDet2->Draw();
  sprintf(name,"Entries: %.0f", xDet2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDet2->SetTitle(0);
  pxDet2->SetLabelSize(0.05, "x");
  pxDet2->SetLabelSize(0.05, "y");
  pxDet2->GetXaxis()->SetTitleSize(0.05);
  pxDet2->GetXaxis()->SetTitleOffset(1.0);
  pxDet2->SetMinimum(0);
  pxDet2->Draw();
  sprintf(name,"Entries: %.0f", pxDet2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDet2->SetTitle(0);
  yDet2->SetLabelSize(0.05, "x");
  yDet2->SetLabelSize(0.05, "y");
  yDet2->GetXaxis()->SetTitleSize(0.05);
  yDet2->GetXaxis()->SetTitleOffset(1.0);
  yDet2->SetMinimum(0);
  yDet2->Draw();
  sprintf(name,"Entries: %.0f", yDet2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDet2->SetTitle(0);
  pyDet2->SetLabelSize(0.05, "x");
  pyDet2->SetLabelSize(0.05, "y");
  pyDet2->GetXaxis()->SetTitleSize(0.05);
  pyDet2->GetXaxis()->SetTitleOffset(1.0);
  pyDet2->SetMinimum(0);
  pyDet2->Draw();
  sprintf(name,"Entries: %.0f", pyDet2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDet2->SetTitle(0);
  dpDet2->SetLabelSize(0.05, "x");
  dpDet2->SetLabelSize(0.05, "y");
  dpDet2->GetXaxis()->SetTitleSize(0.05);
  dpDet2->GetXaxis()->SetTitleOffset(1.0);
  dpDet2->SetMinimum(0);
  dpDet2->Draw();
  sprintf(name,"Entries: %.0f", dpDet2->GetEntries());
  NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_Det2->SetTitle(0);
  beamspot_Det2->SetLabelSize(0.05, "x");
  beamspot_Det2->SetLabelSize(0.05, "y");
  beamspot_Det2->GetXaxis()->SetTitleSize(0.05);
  beamspot_Det2->GetXaxis()->SetTitleOffset(1.0);
  beamspot_Det2->GetYaxis()->SetTitleOffset(1.1);
  beamspot_Det2->GetYaxis()->SetTitleSize(0.05);
  beamspot_Det2->Draw("colz");
 
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/EndDipole1_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_Det2", "dpPlots_Det2", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  TGaxis::SetMaxDigits(3);
  
  Can_Name->cd(1);
  xPx_Det2->SetTitle(0);
  xPx_Det2->SetLabelSize(0.05, "x");
  xPx_Det2->SetLabelSize(0.05, "y");
  xPx_Det2->GetXaxis()->SetTitleSize(0.05);
  xPx_Det2->GetXaxis()->SetTitleOffset(1.0);
  xPx_Det2->GetYaxis()->SetTitleSize(0.05);
  xPx_Det2->GetYaxis()->SetTitleOffset(1.0);
  xPx_Det2->Draw("colz");
     
  Can_Name->cd(2);
  yPy_Det2->SetTitle(0);
  yPy_Det2->SetLabelSize(0.05, "x");
  yPy_Det2->SetLabelSize(0.05, "y");
  yPy_Det2->GetXaxis()->SetTitleSize(0.05);
  yPy_Det2->GetXaxis()->SetTitleOffset(1.0);
  yPy_Det2->GetYaxis()->SetTitleSize(0.05);
  yPy_Det2->GetYaxis()->SetTitleOffset(1.0);
  yPy_Det2->Draw("colz");

  Can_Name->cd(3);
  dispersion_Det2->SetTitle(0);
  dispersion_Det2->SetLabelSize(0.05, "x");
  dispersion_Det2->SetLabelSize(0.05, "y");
  dispersion_Det2->GetXaxis()->SetTitleSize(0.05);
  dispersion_Det2->GetXaxis()->SetTitleOffset(1.0);
  dispersion_Det2->GetYaxis()->SetTitleSize(0.05);
  dispersion_Det2->GetYaxis()->SetTitleOffset(1.0);
  dispersion_Det2->Draw("colz");
 
  Can_Name->cd(4);
  dpPx_Det2->SetTitle(0);
  dpPx_Det2->SetLabelSize(0.05, "x");
  dpPx_Det2->SetLabelSize(0.05, "y");
  dpPx_Det2->GetXaxis()->SetTitleSize(0.05);
  dpPx_Det2->GetXaxis()->SetTitleOffset(1.0);
  dpPx_Det2->GetYaxis()->SetTitleSize(0.05);
  dpPx_Det2->GetYaxis()->SetTitleOffset(1.0);
  dpPx_Det2->Draw("colz");
  
  Can_Name->cd(5);
  ydp_Det2->SetTitle(0);
  ydp_Det2->SetLabelSize(0.05, "x");
  ydp_Det2->SetLabelSize(0.05, "y");
  ydp_Det2->GetXaxis()->SetTitleSize(0.05);
  ydp_Det2->GetXaxis()->SetTitleOffset(1.0);
  ydp_Det2->GetYaxis()->SetTitleSize(0.05);
  ydp_Det2->GetYaxis()->SetTitleOffset(1.0);
  ydp_Det2->Draw("colz");
 
  Can_Name->cd(6);
  dpPy_Det2->SetTitle(0);
  dpPy_Det2->SetLabelSize(0.05, "x");
  dpPy_Det2->SetLabelSize(0.05, "y");
  dpPy_Det2->GetXaxis()->SetTitleSize(0.05);
  dpPy_Det2->GetXaxis()->SetTitleOffset(1.0);
  dpPy_Det2->GetYaxis()->SetTitleSize(0.05);
  dpPy_Det2->GetYaxis()->SetTitleOffset(1.0);
  dpPy_Det2->Draw("colz");
 
  Can_Name->Write();
  //sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/EndDipole1_dispersion.eps");
  Can_Name -> Print(name);
  
   // at IFP******************************************************
  
  //position and angle histograms
  
  Can_Name = new TCanvas("xp_IFP", "xp_IFP", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  //TGaxis::SetMaxDigits(3);
  
  xDet3 -> Scale(600/xDet3->GetMaximum());
  yDet3 -> Scale(1050/yDet3->GetMaximum());
  pxDet3 -> Scale(700/pxDet3->GetMaximum());
  pyDet3 -> Scale(1400/pyDet3->GetMaximum());
  dpDet3 -> Scale(680/dpDet3->GetMaximum());
  
  beamspot_Det3->Scale(1.5);
 
  Can_Name->cd(1);
  xDet3->SetTitle(0);
  xDet3->SetLabelSize(0.05, "x");
  xDet3->SetLabelSize(0.05, "y");
  xDet3->SetLineColor(2);
  xDet3->SetLineWidth(1);
  xDet3->GetXaxis()->SetTitleSize(0.05);
  xDet3->GetXaxis()->SetTitleOffset(1.0);
  xDet3->SetMinimum(0);
  xDet3->Draw();
  //sprintf(name,"Entries: %.0f", xDet3->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDet3->SetTitle(0);
  pxDet3->SetLabelSize(0.05, "x");
  pxDet3->SetLabelSize(0.05, "y");
  pxDet3->SetLineColor(2);
  pxDet3->SetLineWidth(1);
  pxDet3->GetXaxis()->SetTitleSize(0.05);
  pxDet3->GetXaxis()->SetTitleOffset(1.0);
  pxDet3->SetMinimum(0);
  pxDet3->Draw();
  //sprintf(name,"Entries: %.0f", pxDet3->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDet3->SetTitle(0);
  yDet3->SetLabelSize(0.05, "x");
  yDet3->SetLabelSize(0.05, "y");
  yDet3->SetLineColor(2);
  yDet3->SetLineWidth(1);
  yDet3->GetXaxis()->SetTitleSize(0.05);
  yDet3->GetXaxis()->SetTitleOffset(1.0);
  yDet3->SetMinimum(0);
  yDet3->Draw();
  //sprintf(name,"Entries: %.0f", yDet3->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDet3->SetTitle(0);
  pyDet3->SetLabelSize(0.05, "x");
  pyDet3->SetLabelSize(0.05, "y");
  pyDet3->SetLineColor(2);
  pyDet3->SetLineWidth(1);
  pyDet3->GetXaxis()->SetTitleSize(0.05);
  pyDet3->GetXaxis()->SetTitleOffset(1.0);
  pyDet3->SetMinimum(0);
  pyDet3->Draw();
  //sprintf(name,"Entries: %.0f", pyDet3->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDet3->SetTitle(0);
  dpDet3->SetLabelSize(0.05, "x");
  dpDet3->SetLabelSize(0.05, "y");
  dpDet3->SetLineColor(2);
  dpDet3->SetLineWidth(1);
  dpDet3->GetXaxis()->SetTitleSize(0.05);
  dpDet3->GetXaxis()->SetTitleOffset(1.0);
  dpDet3->SetMinimum(0);
  dpDet3->Draw();
  //sprintf(name,"Entries: %.0f", dpDet3->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_Det3->SetTitle(0);
  beamspot_Det3->SetLabelSize(0.05, "x");
  beamspot_Det3->SetLabelSize(0.05, "y");
  beamspot_Det3->GetXaxis()->SetTitleSize(0.05);
  beamspot_Det3->GetXaxis()->SetTitleOffset(1.0);
  beamspot_Det3->GetYaxis()->SetTitleOffset(1.1);
  beamspot_Det3->GetYaxis()->SetTitleSize(0.05);
  beamspot_Det3->Draw("colz");
 
  Can_Name->Write();
  sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/IFP_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_IFP", "dpPlots_IFP", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  //TGaxis::SetMaxDigits(3);
  
  xPx_Det3->Scale(1.5);
  yPy_Det3->Scale(1.5);
  dpPx_Det3->Scale(1.5);
  ydp_Det3->Scale(1.5);
  dpPy_Det3->Scale(1.5);
  dispersion_IFP->Scale(1.5);
    
  Can_Name->cd(1);
  xPx_Det3->SetTitle(0);
  xPx_Det3->SetLabelSize(0.05, "x");
  xPx_Det3->SetLabelSize(0.05, "y");
  xPx_Det3->GetXaxis()->SetTitleSize(0.05);
  xPx_Det3->GetXaxis()->SetTitleOffset(1.0);
  xPx_Det3->GetYaxis()->SetTitleSize(0.05);
  xPx_Det3->GetYaxis()->SetTitleOffset(1.0);
  xPx_Det3->Draw("colz");
     
  Can_Name->cd(2);
  yPy_Det3->SetTitle(0);
  yPy_Det3->SetLabelSize(0.05, "x");
  yPy_Det3->SetLabelSize(0.05, "y");
  yPy_Det3->GetXaxis()->SetTitleSize(0.05);
  yPy_Det3->GetXaxis()->SetTitleOffset(1.0);
  yPy_Det3->GetYaxis()->SetTitleSize(0.05);
  yPy_Det3->GetYaxis()->SetTitleOffset(1.0);
  yPy_Det3->Draw("colz");
  
  Can_Name->cd(3);
  dispersion_IFP->SetTitle(0);
  dispersion_IFP->SetLabelSize(0.05, "x");
  dispersion_IFP->SetLabelSize(0.05, "y");
  dispersion_IFP->GetXaxis()->SetTitleSize(0.05);
  dispersion_IFP->GetXaxis()->SetTitleOffset(1.0);
  dispersion_IFP->GetYaxis()->SetTitleSize(0.05);
  dispersion_IFP->GetYaxis()->SetTitleOffset(1.0);
  dispersion_IFP->Draw("colz");
 
  Can_Name->cd(4);
  dpPx_Det3->SetTitle(0);
  dpPx_Det3->SetLabelSize(0.05, "x");
  dpPx_Det3->SetLabelSize(0.05, "y");
  dpPx_Det3->GetXaxis()->SetTitleSize(0.05);
  dpPx_Det3->GetXaxis()->SetTitleOffset(1.0);
  dpPx_Det3->GetYaxis()->SetTitleSize(0.05);
  dpPx_Det3->GetYaxis()->SetTitleOffset(1.0);
  dpPx_Det3->Draw("colz");
  
  Can_Name->cd(5);
  ydp_Det3->SetTitle(0);
  ydp_Det3->SetLabelSize(0.05, "x");
  ydp_Det3->SetLabelSize(0.05, "y");
  ydp_Det3->GetXaxis()->SetTitleSize(0.05);
  ydp_Det3->GetXaxis()->SetTitleOffset(1.0);
  ydp_Det3->GetYaxis()->SetTitleSize(0.05);
  ydp_Det3->GetYaxis()->SetTitleOffset(1.0);
  ydp_Det3->Draw("colz");
 
  Can_Name->cd(6);
  dpPy_Det3->SetTitle(0);
  dpPy_Det3->SetLabelSize(0.05, "x");
  dpPy_Det3->SetLabelSize(0.05, "y");
  dpPy_Det3->GetXaxis()->SetTitleSize(0.05);
  dpPy_Det3->GetXaxis()->SetTitleOffset(1.0);
  dpPy_Det3->GetYaxis()->SetTitleSize(0.05);
  dpPy_Det3->GetYaxis()->SetTitleOffset(1.0);
  dpPy_Det3->Draw("colz");
 
  Can_Name->Write();
  sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/IFP_dispersion.eps");
  Can_Name -> Print(name);
  
  // at PiM1 Tar******************************************************
  
  //position and angle histograms
  /*
  Can_Name = new TCanvas("xp_Tar", "xp_Tar", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  //TGaxis::SetMaxDigits(3);
  
  xDetTar -> Scale(1250/xDetTar->GetMaximum());
  yDetTar-> Scale(860/yDetTar->GetMaximum());
  pxDetTar -> Scale(900/pxDetTar->GetMaximum());
  pyDetTar -> Scale(1350/pyDetTar->GetMaximum());
  dpDetTar-> Scale(680/dpDetTar->GetMaximum());
  
  beamspot_DetTar->Scale(1.5);
  
  Can_Name->cd(1);
  xDetTar->SetTitle(0);
  xDetTar->SetLabelSize(0.05, "x");
  xDetTar->SetLabelSize(0.05, "y");
  xDetTar->SetLineColor(2);
  xDetTar->SetLineWidth(1);
  xDetTar->GetXaxis()->SetTitleSize(0.05);
  xDetTar->GetXaxis()->SetTitleOffset(1.0);
  xDetTar->SetMinimum(0);
  xDetTar->Draw();
  xDetTar->GetYaxis()->SetRangeUser(0,1300);
  //sprintf(name,"Entries: %.0f", xDetTar->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
    
  Can_Name->cd(2);
  pxDetTar->SetTitle(0);
  pxDetTar->SetLabelSize(0.05, "x");
  pxDetTar->SetLabelSize(0.05, "y");
  pxDetTar->SetLineColor(2);
  pxDetTar->SetLineWidth(1);
  pxDetTar->GetXaxis()->SetTitleSize(0.05);
  pxDetTar->GetXaxis()->SetTitleOffset(1.0);
  pxDetTar->SetMinimum(0);
  pxDetTar->Draw();
  pxDetTar->GetYaxis()->SetRangeUser(0,945);
  //sprintf(name,"Entries: %.0f", pxDetTar->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(3);
  yDetTar->SetTitle(0);
  yDetTar->SetLabelSize(0.05, "x");
  yDetTar->SetLabelSize(0.05, "y");
  yDetTar->SetLineColor(2);
  yDetTar->SetLineWidth(1);
  yDetTar->GetXaxis()->SetTitleSize(0.05);
  yDetTar->GetXaxis()->SetTitleOffset(1.0);
  yDetTar->SetMinimum(0);
  yDetTar->Draw();
  yDetTar->GetYaxis()->SetRangeUser(0,900);
  //sprintf(name,"Entries: %.0f", yDetTar->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(4);
  pyDetTar->SetTitle(0);
  pyDetTar->SetLabelSize(0.05, "x");
  pyDetTar->SetLabelSize(0.05, "y");
  pyDetTar->SetLineColor(2);
  pyDetTar->SetLineWidth(1);
  pyDetTar->GetXaxis()->SetTitleSize(0.05);
  pyDetTar->GetXaxis()->SetTitleOffset(1.0);
  pyDetTar->SetMinimum(0);
  pyDetTar->Draw();
  pyDetTar->GetYaxis()->SetRangeUser(0,1450);
  //sprintf(name,"Entries: %.0f", pyDetTar->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(5);
  dpDetTar->SetTitle(0);
  dpDetTar->SetLabelSize(0.05, "x");
  dpDetTar->SetLabelSize(0.05, "y");
  dpDetTar->SetLineColor(2);
  dpDetTar->SetLineWidth(1);
  dpDetTar->GetXaxis()->SetTitleSize(0.05);
  dpDetTar->GetXaxis()->SetTitleOffset(1.0);
  dpDetTar->SetMinimum(0);
  dpDetTar->Draw();
  dpDetTar->GetYaxis()->SetRangeUser(0,700);
  //sprintf(name,"Entries: %.0f", dpDetTar->GetEntries());
  //NewTitle(name, 0.04, 1, 0.7, 0.8, 0.8,0.9);
  
  Can_Name->cd(6);
  beamspot_DetTar->SetTitle(0);
  beamspot_DetTar->SetLabelSize(0.05, "x");
  beamspot_DetTar->SetLabelSize(0.05, "y");
  beamspot_DetTar->GetXaxis()->SetTitleSize(0.05);
  beamspot_DetTar->GetXaxis()->SetTitleOffset(1.0);
  beamspot_DetTar->GetYaxis()->SetTitleOffset(1.1);
  beamspot_DetTar->GetYaxis()->SetTitleSize(0.05);
  beamspot_DetTar->Draw("colz");
 
  Can_Name->Write();
  sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/PiM1Tar_phaseSpace.eps");
  Can_Name -> Print(name);
  
  //dispersion distributions
  
  Can_Name = new TCanvas("dpPlots_Tar", "dpPlots_Tar", 0,0,898,1126);
  Can_Name -> Divide(2,3);
  //TGaxis::SetMaxDigits(3);
  
  xPx_DetTar->Scale(1.5);
  yPy_DetTar->Scale(1.5);
  dispersion_Tar->Scale(1.5);
  dpPx_DetTar->Scale(1.5);
  ydp_DetTar->Scale(1.5);
  dpPy_DetTar->Scale(1.5);
  
  Can_Name->cd(1);
  xPx_DetTar->SetTitle(0);
  xPx_DetTar->SetLabelSize(0.05, "x");
  xPx_DetTar->SetLabelSize(0.05, "y");
  xPx_DetTar->GetXaxis()->SetTitleSize(0.05);
  xPx_DetTar->GetXaxis()->SetTitleOffset(1.0);
  xPx_DetTar->GetYaxis()->SetTitleSize(0.05);
  xPx_DetTar->GetYaxis()->SetTitleOffset(1.0);
  xPx_DetTar->Draw("colz");
     
  Can_Name->cd(2);
  yPy_DetTar->SetTitle(0);
  yPy_DetTar->SetLabelSize(0.05, "x");
  yPy_DetTar->SetLabelSize(0.05, "y");
  yPy_DetTar->GetXaxis()->SetTitleSize(0.05);
  yPy_DetTar->GetXaxis()->SetTitleOffset(1.0);
  yPy_DetTar->GetYaxis()->SetTitleSize(0.05);
  yPy_DetTar->GetYaxis()->SetTitleOffset(1.0);
  yPy_DetTar->Draw("colz");
  
  Can_Name->cd(3);
  dispersion_Tar->SetTitle(0);
  dispersion_Tar->SetLabelSize(0.05, "x");
  dispersion_Tar->SetLabelSize(0.05, "y");
  dispersion_Tar->GetXaxis()->SetTitleSize(0.05);
  dispersion_Tar->GetXaxis()->SetTitleOffset(1.0);
  dispersion_Tar->GetYaxis()->SetTitleSize(0.05);
  dispersion_Tar->GetYaxis()->SetTitleOffset(1.0);
  dispersion_Tar->Draw("colz");
 
  Can_Name->cd(4);
  dpPx_DetTar->SetTitle(0);
  dpPx_DetTar->SetLabelSize(0.05, "x");
  dpPx_DetTar->SetLabelSize(0.05, "y");
  dpPx_DetTar->GetXaxis()->SetTitleSize(0.05);
  dpPx_DetTar->GetXaxis()->SetTitleOffset(1.0);
  dpPx_DetTar->GetYaxis()->SetTitleSize(0.05);
  dpPx_DetTar->GetYaxis()->SetTitleOffset(1.0);
  dpPx_DetTar->Draw("colz");
  
  Can_Name->cd(5);
  ydp_DetTar->SetTitle(0);
  ydp_DetTar->SetLabelSize(0.05, "x");
  ydp_DetTar->SetLabelSize(0.05, "y");
  ydp_DetTar->GetXaxis()->SetTitleSize(0.05);
  ydp_DetTar->GetXaxis()->SetTitleOffset(1.0);
  ydp_DetTar->GetYaxis()->SetTitleSize(0.05);
  ydp_DetTar->GetYaxis()->SetTitleOffset(1.0);
  ydp_DetTar->Draw("colz");
 
  Can_Name->cd(6);
  dpPy_DetTar->SetTitle(0);
  dpPy_DetTar->SetLabelSize(0.05, "x");
  dpPy_DetTar->SetLabelSize(0.05, "y");
  dpPy_DetTar->GetXaxis()->SetTitleSize(0.05);
  dpPy_DetTar->GetXaxis()->SetTitleOffset(1.0);
  dpPy_DetTar->GetYaxis()->SetTitleSize(0.05);
  dpPy_DetTar->GetYaxis()->SetTitleOffset(1.0);
  dpPy_DetTar->Draw("colz");
 
  Can_Name->Write();
  sprintf(name,"plots/ASCII_pionBeamTurtle_Jan2019/PiM1_dispersion.eps");
  Can_Name -> Print(name);
  */
  f_out -> Write();
  f_out->Close();
  cerr<<"End of writing histograms to output rootfile"<<endl<<endl;
 
}


void NewTitle(char *title,double Tsize, int Color, double x1, double y1, double x2, double y2)
{
  TPaveText *pt;
  TText *tx;

  pt = new TPaveText(x1,y1,x2,y2,"NDC");
  pt -> SetFillColor(0);
  pt -> SetTextSize(Tsize);
  pt -> SetTextColor(Color);
  pt -> SetBorderSize(0);
  pt -> SetTextAlign(12);
  tx = pt -> AddText(title);
  pt -> Draw();
}
