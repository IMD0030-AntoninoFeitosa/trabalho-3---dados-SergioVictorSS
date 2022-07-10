#include "AtributoInstancia.h"
AtributoInstancia::AtributoInstancia(Atributo pBase) : base(pBase){
  indefinido = false;
};

Atributo AtributoInstancia::GetBase(){
  return base;
};
  bool AtributoInstancia::setarValorNumerico(float x){
    if(base.IsComplexo())
      return  false;
    valorNumerico = x;
    return true;
  };
  bool AtributoInstancia::setarValorString(std::string p){
    if(!base.IsComplexo())
      return false;
    valorComplexo = p;
    return true;
  };
  bool AtributoInstancia::isIndefinido(){
    return indefinido;
  };
  void AtributoInstancia::setIndefinido(bool pIndefinido){
    indefinido = pIndefinido;
  };