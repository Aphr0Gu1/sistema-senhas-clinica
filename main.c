/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "clinica.h"

int main(void) {
    int opcao;

    do {
        mostrarPainel();

        printf("\n========= MENU PRINCIPAL =========\n");
        printf("01 - Retirar Senha\n");
        printf("02 - Registrar Atendimento\n");
        printf("00 - Sair\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida!\n");
            break;
        }

        switch (opcao) {
            case 1:
                retirarSenha();
                break;

            case 2:
                registrarAtendimento();
                break;

            case 0:
                printf("\nSistema encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
