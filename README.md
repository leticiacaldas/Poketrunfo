# Poketrunfo

Poketrunfo é um jogo de cartas baseado em Pokémon, onde dois jogadores competem comparando atributos de seus Pokémons. O objetivo é ganhar todas as cartas do adversário.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- `main.c`: Contém a função principal e a lógica do jogo.
- `jogo.c`: Implementa as funções relacionadas à fila e ao jogo.
- `busca.c`: Implementa funções de busca relacionadas aos Pokémons.
- `pokedex.c`: Contém a implementação da Pokedex e manipulação de dados dos Pokémons.
- `jogo.h`: Cabeçalho com as definições de estruturas e declarações de funções para o jogo.
- `pokedex.h`: Cabeçalho com as definições de estruturas e declarações de funções para a Pokedex.

## Compilação e Execução

### Usando Visual Studio Code

1. **Configuração do `tasks.json`**:
   Certifique-se de que o arquivo `.vscode/tasks.json` está configurado corretamente para compilar todos os arquivos `.c`.

   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "Compilar C",
               "type": "shell",
               "command": "gcc",
               "args": [
                   "-g",
                   "${workspaceFolder}/main.c",
                   "${workspaceFolder}/jogo.c",
                   "${workspaceFolder}/busca.c",
                   "${workspaceFolder}/pokedex.c",
                   "-o",
                   "${workspaceFolder}/poketrunfo",
                   "-lm"
               ],
               "group": {
                   "kind": "build",
                   "isDefault": true
               },
               "problemMatcher": ["$gcc"],
               "detail": "Compilar o programa C"
           }
       ]
   }









  **.vscode/launch.json**


 ```json

   {
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Executar Poketrunfo",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/poketrunfo",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compilar C",
            "miDebuggerPath": "/usr/bin/gdb",
            "logging": {
                "engineLogging": true
            }
        }
    ]
}


**Estruturas e Funções**

Estruturas:

FilaNode: Representa um nó na fila, contendo um Pokémon e um ponteiro para o próximo nó.
Fila: Representa a fila, contendo ponteiros para o primeiro e o último nó.
Funções
Fila *criarFila(): Cria e inicializa uma nova fila.
void enfileirar(Fila *fila, Pokemon *pokemon): Adiciona um Pokémon à fila.
Pokemon *desenfileirar(Fila *fila): Remove e retorna o primeiro Pokémon da fila.
int filaVazia(Fila *fila): Verifica se a fila está vazia.
int compararAtributo(Pokemon *carta1, Pokemon *carta2, int atributoEscolhido): Compara um atributo específico entre dois Pokémons.
int escolherAtributo(): Permite ao jogador escolher um atributo para comparar.

Contribuição:
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests.



