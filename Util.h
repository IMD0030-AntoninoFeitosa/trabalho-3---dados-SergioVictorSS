#include "iostream"
#include "vector"
class Util{
public:
  static std::vector<std::string> partirLinha(std::string linha, char delimitador);
  static int quantidadeEmString(std::string s,char c);
  static std::string removerChar(std::string s,char remover);

};