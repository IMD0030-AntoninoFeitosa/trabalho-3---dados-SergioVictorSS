#include "Arquivo.h"
class LeitorArquivo {
  ArquivoController arquivo;
  int ModoOperacao;
  public:
    int LerArquivo();
    std::vector<std::string> partirLinha(std::string linha, char delimitador);
    LeitorArquivo(std::string NomeArquivo, int c, int p);
};