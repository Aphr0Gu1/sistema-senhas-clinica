## Como compilar

gcc src/main.c src/clinica.c -o clinica

## Como executar no Windows

.\clinica.exe

## Modularização

O sistema foi dividido em três arquivos:

- main.c: menu e fluxo principal.
- clinica.c: lógica de cadastro, senhas e atendimento.
- clinica.h: estruturas e declarações das funções.
