#include "Atributo.h"
class AtributoInstancia{
  Atributo base;
  float valorNumerico;
  std::string valorComplexo;
  bool indefinido;
public:  
  AtributoInstancia(Atributo pBase);
  Atributo GetBase();
  bool setarValorNumerico(float x);
  bool setarValorString(std::string p);
  bool isIndefinido();
  void setIndefinido(bool pIndefinido);
  
};