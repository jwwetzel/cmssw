//////////////////////////////////////////////////////////////////////
//File: HFDarkening.cc
//Description:  simple helper class containing parameterized function
//              to be used for the SLHC darkening calculation in HF.
//              Dose values from FLUKA version 1.0.0.0, contact Sophie Mallows for questions.
//////////////////////////////////////////////////////////////////////

#include "SimG4CMS/Calo/interface/HFDarkening.h"
#include <algorithm>
#include <cmath>

// CMSSW Headers
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

using namespace edm;

HFDarkening::HFDarkening(const edm::ParameterSet& pset)
{
  //HF area of consideration is 1115 cm from interaction point to 1280cm in z-axis
  //Radius (cm) - 13 cm from Beam pipe to 130cm (the top of HF active area)
  //Dose in MRad
  
  //Depth 0: 1115. - 1120. cm
  HFDoseLayerDarkeningPars[0] = pset.getParameter<vecOfDoubles>("doseLayerDepthZero");
  
  //Depth 1: 1120. - 1125. cm
  HFDoseLayerDarkeningPars[1] = pset.getParameter<vecOfDoubles>("doseLayerDepthOne");
  
  //Depth 2: 1125. - 1130. cm
  HFDoseLayerDarkeningPars[2] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwo");
  
  //Depth 3: 1130. - 1135. cm
  HFDoseLayerDarkeningPars[3] = pset.getParameter<vecOfDoubles>("doseLayerDepthThree");
  
  //Depth 4: 1135. - 1140. cm
  HFDoseLayerDarkeningPars[4] = pset.getParameter<vecOfDoubles>("doseLayerDepthFour");
  
  //Depth 5: 1140. - 1145. cm
  HFDoseLayerDarkeningPars[5] = pset.getParameter<vecOfDoubles>("doseLayerDepthFive");
  
  //Depth 6: 1145. - 1150. cm
  HFDoseLayerDarkeningPars[6] = pset.getParameter<vecOfDoubles>("doseLayerDepthSix");
  
  //Depth 7: 1150. - 1155. cm
  HFDoseLayerDarkeningPars[7] = pset.getParameter<vecOfDoubles>("doseLayerDepthSeven");
  
  //Depth 8: 1155. - 1160. cm
  HFDoseLayerDarkeningPars[8] = pset.getParameter<vecOfDoubles>("doseLayerDepthEight");
  
  //Depth 9: 1160. - 1165. cm
  HFDoseLayerDarkeningPars[9] = pset.getParameter<vecOfDoubles>("doseLayerDepthNine");
  
  //Depth 10: 1165. - 1170. cm
  HFDoseLayerDarkeningPars[10] = pset.getParameter<vecOfDoubles>("doseLayerDepthTen");
  
  //Depth 11: 1170. - 1175. cm
  HFDoseLayerDarkeningPars[11] = pset.getParameter<vecOfDoubles>("doseLayerDepthEleven");
  
  //Depth 12: 1175. - 1180. cm
  HFDoseLayerDarkeningPars[12] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwelve");
  
  //Depth 13: 1180. - 1185. cm
  HFDoseLayerDarkeningPars[13] = pset.getParameter<vecOfDoubles>("doseLayerDepthThirteen");
  
  //Depth 14: 1185. - 1190. cm
  HFDoseLayerDarkeningPars[14] = pset.getParameter<vecOfDoubles>("doseLayerDepthTourteen");
  
  //Depth 15: 1190. - 1195. cm
  HFDoseLayerDarkeningPars[15] = pset.getParameter<vecOfDoubles>("doseLayerDepthTifteen");
  
  //Depth 16: 1195. - 1200. cm
  HFDoseLayerDarkeningPars[16] = pset.getParameter<vecOfDoubles>("doseLayerDepthSixteen");
  
  //Depth 17: 1200. - 1205. cm
  HFDoseLayerDarkeningPars[17] = pset.getParameter<vecOfDoubles>("doseLayerDepthSeventeen");
  
  //Depth 18: 1205. - 1210. cm
  HFDoseLayerDarkeningPars[18] = pset.getParameter<vecOfDoubles>("doseLayerDepthEighteen");
  
  //Depth 19: 1210. - 1215. cm
  HFDoseLayerDarkeningPars[19] = pset.getParameter<vecOfDoubles>("doseLayerDepthNineteen");
  
  //Depth 20: 1215. - 1220. cm
  HFDoseLayerDarkeningPars[20] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwenty");
  
  //Depth 21: 1220. - 1225. cm
  HFDoseLayerDarkeningPars[21] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyOne");
  
  //Depth 22: 1225. - 1230. cm
  HFDoseLayerDarkeningPars[22] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyTwo");
  
  //Depth 23: 1230. - 1235. cm
  HFDoseLayerDarkeningPars[23] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyThree");
  
  //Depth 24: 1235. - 1240. cm
  HFDoseLayerDarkeningPars[24] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyFour");
  
  //Depth 25: 1240. - 1245. cm
  HFDoseLayerDarkeningPars[25] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyFive");
  
  //Depth 26: 1245. - 1250. cm
  HFDoseLayerDarkeningPars[26] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentySix");
  
  //Depth 27: 1250. - 1255. cm
  HFDoseLayerDarkeningPars[27] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentySeven");
  
  //Depth 28: 1255. - 1260. cm
  HFDoseLayerDarkeningPars[28] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyEight");
  
  //Depth 29: 1260. - 1265. cm
  HFDoseLayerDarkeningPars[29] = pset.getParameter<vecOfDoubles>("doseLayerDepthTwentyNine");
  
  //Depth 30: 1265. - 1270. cm
  HFDoseLayerDarkeningPars[30] = pset.getParameter<vecOfDoubles>("doseLayerDepthThirty");
  
  //Depth 31: 1270. - 1275. cm
  HFDoseLayerDarkeningPars[31] = pset.getParameter<vecOfDoubles>("doseLayerDepthThirtyOne");
  
  //Depth 32: 1275. - 1280. cm
  HFDoseLayerDarkeningPars[32] = pset.getParameter<vecOfDoubles>("doseLayerDepthThirtyTwo");
  
  //Depth 33: 1280. - 1280. cm
  HFDoseLayerDarkeningPars[33] = pset.getParameter<vecOfDoubles>("doseLayerDepthThirtyThree");

}

HFDarkening::~HFDarkening()
{}

double HFDarkening::dose(int layer, double Radius)
{
  // Radii are 13-17, 17-20, 20-24, 24-29, 29-34, 34-41, 41-48, 48-58, 58-69, 69-82, 82-98, 98-116, 116-130
  // These radii are specific to the geometry of the dose map, which closely matches HF Tower Geometry,
  // but not exactly.
  if (layer < 0 || layer > 32)
  {
    return 0.;
  }
  
  int radius = 0;
  if (Radius > 13.0 && Radius <= 17.0) radius = 0;
  if (Radius > 17.0 && Radius <= 20.0) radius = 1;
  if (Radius > 20.0 && Radius <= 24.0) radius = 2;
  if (Radius > 24.0 && Radius <= 29.0) radius = 3;
  if (Radius > 29.0 && Radius <= 34.0) radius = 4;
  if (Radius > 34.0 && Radius <= 41.0) radius = 5;
  if (Radius > 41.0 && Radius <= 48.0) radius = 6;
  if (Radius > 48.0 && Radius <= 58.0) radius = 7;
  if (Radius > 58.0 && Radius <= 69.0) radius = 8;
  if (Radius > 69.0 && Radius <= 82.0) radius = 9;
  if (Radius > 82.0 && Radius <= 98.0) radius = 10;
  if (Radius > 98.0 && Radius <= 116.0) radius = 11;
  if (Radius > 116.0 && Radius <= 130.0) radius = 12;
  if (Radius > 130.0) return 0.;
  
  
  return HFDoseLayerDarkeningPars[layer][radius];
}

double HFDarkening::degradation(double mrad)
{
  return (exp(-1.44*pow(mrad/100,0.44)*0.2/4.343));
}

double HFDarkening::int_lumi(double intlumi)
{
  return (intlumi/3000.);
}
