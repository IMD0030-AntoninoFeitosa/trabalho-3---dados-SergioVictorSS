#include "vector"
#include <iostream>
class Atributo{
public:
  bool complexo;
  std::string nome;
  std::vector<std::string> valores;

  Atributo(bool pComplexo);
  bool IsComplexo();
  
};