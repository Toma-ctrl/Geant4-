//exemple B1DetectorConstruction.cc, take example but modify for a wall 


#include "B1DetectorConstruction.hh"     

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"         //not mandatory for a wall
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"


B1DetectorConstruction::B1DetectorConstruction():
  G4VUSerDetectorConstruction(),
  fScoringVolume(0)
{ }


B1DetectorConstruction::~B1DetectorConstruction()
{ }

G4PhysicalVolume* B1DetectorConstruction::Construct()
{
  //nist get the material
  G4NistManager* nist = G4NistManager::Instance();
  
  //geometry 
  G4Double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_WATER");
  
  //World
  
  G4Double world_sizeXY = 1.2*env_sizeXY;
  G4Double world_sizeZ = 1.2*env_sizeZ;
  G4Material* world_mat = nist->FindOrBuild("G4_AIR");
  
  G4Box* solidWorld = new G4Box("World", 0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);
  
  G4LogicalVolume* logicWordl = 
    new G4LogicalVolume(solideWorld,
                        world_mat,
                        "World");
  
  G4PhysicalVolume* physWorld =
    new G4PVPlacement(0,                      //no rotation
                      G4ThreeVector(),        //default (0,0,0) so place origin 
                      logicWorld,             //it's logical Volume
                      "World",
                      0,                     //its mother volume himself so none
                      false,                 //no boolean ope
                      0,                     //nb of copy
                      checkOverLaps);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  


