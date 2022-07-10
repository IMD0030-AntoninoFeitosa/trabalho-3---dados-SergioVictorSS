#include "Util.h"
std::vector<std::string> Util::partirLinha(std::string linha, char delimitador){
  std::string palavra("");
  std::vector<std::string> partida;
  for(char c: linha){
    if(c == delimitador){
      partida.push_back(palavra);
      palavra = "";
    }else{
      palavra += c;
    }
    
  }
  partida.push_back(palavra);
  return partida;
}
int Util::quantidadeEmString(std::string s,char c){
    int qtd = 0;
    for(char i : s){
      if(i == c)
        qtd++;
    }
    return  qtd;
  }
std::string Util::removerChar(std::string s,char remover){
  std::string nova("");
  for(char c: s){
    if(c != remover)
      nova+=c;
  }
  return nova;
};

