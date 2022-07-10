#include <iostream>
#include "LeitorArquivo.h"
int main() {
  LeitorArquivo *leitor = new LeitorArquivo("mixed.txt",0,0);
  return leitor->LerArquivo();
}