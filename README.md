![Banner](https://github.com/mateusdanie/RedBlackTree/blob/master/ARN%20work%20tree%20.png)

# Trabalho de implementação de uma árvore rubro negra 
[![NPM](https://img.shields.io/npm/l/react)](https://github.com/mateusdanie/RedBlackTree/blob/master/LICENSE) 

# Sobre o projeto

Esse projeto visa a implementação de uma árvore rubro negra, para a disciplina de Estrutura de Dados Avançada. Neste projeto, está presente as funções de adição e remoção de nós, bem como a função de calcular a quantidade de nós da árvore por meio de pós ordem. Todas as funções citadas estão em ARN.h.

# Funções

## Dicionário

RN = Rubro Negra.

## Explicações

createTree: Tem a função de setar os valores do nó externo bem como instânciar a raiz com o nó externo.

rotationL: Faz a rotação simples para esquerda de um determinado nó passado por parâmetro.

rotationR: Faz a rotação simples para direita de um determinado nó passado por parâmetro.

routeRN: Dependendo da cor do nó pai, avô e tio, vamos determinar as rotações necéssarias ao adicionar, bem como a recolorização para que a árvore mantenha as propriedades de uma RN.

## Caso 1 RouteRN
![Rota1](https://github.com/mateusdanie/RedBlackTree/blob/master/Rota1.png)

## Caso 2 RouteRN
![Rota2](https://github.com/mateusdanie/RedBlackTree/blob/master/Rota2.png)

## Caso 3 RouteRN
![Rota3](https://github.com/mateusdanie/RedBlackTree/blob/master/Rota3.png)

insertRN: Insere um nó na RN e faz as rotações necéssarias para que a árvore mantenha as propriedades de uma RN.

searchNode: Procura um nó com uma chave especifica e retorna esse nó.

moveFather: Troca os pais e filhos dos nós passados como parâmetro.

successor: Procura o nó mais a esquerda da RN.

removeRouteRN: Dependendo da cor do nó pai, avô e tio, vamos determinar as rotações necéssarias ao remover, bem como a recolorização para que a árvore mantenha as propriedades de uma RN.

countNodes: Conta a quantidades de nós da árvore RN.

freeRN: Limpa a RN da memória por pós-ordem

# Tecnologias utilizadas
Linguagem C

# Autor

Mateus Daniel de Lima da Silva

www.linkedin.com/in/mateus-daniel
