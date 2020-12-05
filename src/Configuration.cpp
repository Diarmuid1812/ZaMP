#include "Configuration.hh"

void Configuration::addMobObject(const char *pName, const char * paramSizeXYZ, const char * paramRGB)
{
  std::shared_ptr<MobileObj> addedObj = std::make_shared<MobileObj>();
  double x,y,z;
  Vector3D sizeXYZ;
  std::string sName(pName);

  std::istringstream streamSizeXYZ;
  streamSizeXYZ.str(paramSizeXYZ);

  //Wczytanie rozmiarów obiektu
  streamSizeXYZ >> x >> y >> z;
  sizeXYZ[0]=x;
  sizeXYZ[1]=y;
  sizeXYZ[2]=z;
  addedObj->SetSize_m(sizeXYZ);
  addedObj->SetName(pName);;
  addedObj->SetColour(paramRGB);
  _SetMobObjects.insert( std::pair<std::string,std::shared_ptr<MobileObj>>(sName,addedObj));
}
