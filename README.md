# Exercicio_Sincronizacao
Exercício sobre sincronização. CESAR School; 3º Período; Turma A; 2022.1; 05/2022

## Objetivo
Este código possui como objetivo realizar o somatório dos valores de uma matriz quadrada através de threads.

## Funcionamento
Este código recebe do usuário a ordem de uma matriz quadrada e os valores dessa matriz, com isso é criada uma quantidade de threads igual a ordem da matriz.

A função para criar threads recebe como parâmetro um array de inteiros que possui os números da respectiva fila da matriz durante a iteração, bem como uma função para 
relizar o somatório desses valores. O array dado é convertido via casting para "void" então tranformado novamente via casting para um array de inteiros dentro da função
que realiza o somatório. Essa função incrementa uma variável global que armazena o somatório de todos os valores da matriz, para evitar que múltiplas threads acessem 
essa variável global é utilizada uma trava mutex que previne este problema. Finalmente, após todas as threads alterarem essa variável global, o programa unifica as 
thredas com a principal "main" e imprime o valor resultante do somatório.
## Instalação
``` sh
git clone https://github.com/Matheus-F-M/Exercicio_Sincronizacao.git
```
## Comandos do Makefile:
### Compile
``` sh
make binary 
```

### Run
``` sh
make run 
```

### Clean
``` sh
make clean 
```
