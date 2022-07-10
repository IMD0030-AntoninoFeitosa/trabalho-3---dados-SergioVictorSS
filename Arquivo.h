#include "AtributoInstancia.h"
class ArquivoController{
   const int c;
   const int p;
  public:
    const std::string NomeArquivo;
    ArquivoController(std::string pNomeArquivo, int pC, int pP);
    std::vector<Atributo> cabecalho;
    std::vector<std::vector<AtributoInstancia>> linhas;

    std::string lerLinhaCabecalho(std::vector<std::string> cabecalho, int nLinha);
    std::string lerLinhaColuna(std::vector<std::string> colunas, int nLinha);
    
};