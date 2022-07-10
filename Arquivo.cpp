#include "Arquivo.h"
#include "Util.h"
#include "algorithm"
ArquivoController::ArquivoController(std::string pNomeArquivo, int pC, int pP) : NomeArquivo(pNomeArquivo),p(pP),c(pC) {
};
std::string ArquivoController::lerLinhaCabecalho(std::vector<std::string> pCabecalho, int nLinha){
  if(pCabecalho[0] != "@attribute")
    return "Erro no arquivo. Linha " + std::to_string(nLinha)  + ", coluna 1 @attribute esperado e " + pCabecalho[0] + " dado";
  if(pCabecalho.size() != 3)
    return "Erro no arquivo. Linha" +  std::to_string(nLinha) + ", três argumentos esperados";
  Atributo atributo = new Atributo(0);
  atributo.complexo = pCabecalho[2] != "numeric";
  
  atributo.nome= pCabecalho[1];
  if(atributo.IsComplexo()){
    if(Util::quantidadeEmString(pCabecalho[2],'{') != 1)
      return "Erro no arquivo linha " + std::to_string(nLinha) + ". Tipo complexo espera abertura de chave!";
        if(Util::quantidadeEmString(pCabecalho[2],'}') != 1)
      return "Erro no arquivo linha " + std::to_string(nLinha) + ". Tipo complexo espera fechamento de chave!";
    pCabecalho[2] = Util::removerChar(pCabecalho[2],'{');
    pCabecalho[2] = Util::removerChar(pCabecalho[2],'}');
    
       atributo.valores = Util:: partirLinha(pCabecalho[2],','); 
  };
  cabecalho.push_back(atributo);
  return "";
};
std::string ArquivoController::lerLinhaColuna(std::vector<std::string> colunas, int nLinha){
  std::vector<AtributoInstancia> linha;
  if(colunas.size() != cabecalho.size())
    return "Erro no arquivo: " + std::to_string(nLinha) + " - número de valores forneciedos insuficientes";
  for(int i = 0; i < colunas.size();i++){
    Atributo base = cabecalho[i];
    AtributoInstancia dado(base);
    if(colunas[i] == "?"){
      dado.setIndefinido(true);
    }else{
 if(base.IsComplexo()){
        if(std::find(base.valores.begin(), base.valores.end(),colunas[i])==base.valores.end())
          return "Erro no arquivo linha" + std::to_string(nLinha) + ", coluna " + std::to_string(i) + " - valor inexistente na lista de possibilidades";
   
   dado.setarValorString(Util::removerChar(Util::removerChar(colunas[i],'"'),'"'));
    }else{     
      dado.setarValorNumerico(std::stof(colunas[i]));
    }    
  }
    linha.push_back(dado);
}
  linhas.push_back(linha);
  return "";
  };