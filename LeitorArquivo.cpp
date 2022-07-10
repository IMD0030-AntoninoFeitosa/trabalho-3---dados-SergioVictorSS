#include "LeitorArquivo.h"
#include "Util.h"
#include <fstream>
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

int LeitorArquivo::LerArquivo(){

    string filename(arquivo.NomeArquivo);
    vector<string> lines;
    string line;
    string retorno = "";
    ifstream input_file(arquivo.NomeArquivo);
    if (!input_file.is_open()) {
        return EXIT_FAILURE;
    }
    int aux = 0;
    while (getline(input_file, line)){
        aux++;
        if(line == "@info"){
          ModoOperacao=0;
        }else if(line == "@data"){
          ModoOperacao=1;
        }else if(ModoOperacao){
          retorno = arquivo.lerLinhaColuna(Util::partirLinha(line,','),aux);
        }else{
          retorno = arquivo.lerLinhaCabecalho(Util::partirLinha(line,' '),aux);       
        }
      if(retorno != ""){
        cout << retorno;
        return EXIT_FAILURE;
      }
    }
    input_file.close();
    cout << "Arquivo lido com sucesso!";
    return EXIT_SUCCESS;
};

LeitorArquivo::LeitorArquivo(string NomeArquivo,int c, int p) : arquivo(NomeArquivo,c,p){
    
};