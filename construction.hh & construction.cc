//construction.hh

#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
class MyDetectorConstruction : public G4VUserDetectorConstruction

{
public:
        MyDetectorConstruction();
        ~MyDetectorConstruction();
        
        virtual G4VPhysicalVolume *Construct();
        };   
        
#endif         



//construction.cc


#include  "construction.hh"

 MyDetectorConstruction::MyDetectorConstruction()
 {}
 
  MyDetectorConstruction::~MyDetectorConstruction()
  {}
   G4VPhysicalVolume *MyDetectorConstruction::Construct()
   {
   
   G4NistManager *nist = G4NistManager::Instance();
   G4Material *worldMat= nist->FindOrBuildMaterial("G4_AIR");
   
   G4Box *solidworld=new G4Box("solidworld",0.5*m,0.5*m,0.5*m);
   
   G4LogicalVolume *logicworld=new G4LogicalVolume(solidworld,worldMat,"logicWorld");
   
   G4VPhysicalVolume *physWorld= new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),logicworld,"physworld",0,false,0,true);
   
   return physWorld;
   
   }
