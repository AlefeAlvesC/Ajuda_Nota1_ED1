# Ajuda_Nota1_ED1
Resolução do exercício de ajuda para a primeira nota de ED1

A resolução desse exercício se dá primeiramente pela leitura de um arquivo txt, com auxílio das funções fopen, fscanf e fclose.
A leitura dentro desse arquivo, ocorre de palavra em palavra, e ao encontrar uma palavra nova criamos uma lista dessa nova palavra,
possibilitando assim o monitoramento desta em caso de uma nova ocorrência. A cada ocorrência de uma palavra, dependendo da posição(linha) desta
devemos criar um novo nodo(ou nó) ou em caso de já haver um nodo para tal linha, apenas incrementamos a variável vezes no nodo correspondente.
