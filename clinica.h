
#include <stdio.h>
#include <string.h>
#include "clinica.h"

// Dados compartilhados pelas funcoes deste modulo
static Paciente pacientes[MAX_PACIENTES];
static int total = 0;

static int contadorNormal = 0;
static int contadorPreferencial = 0;
static int contadorUrgente = 0;

// Classifica o paciente conforme as regras
static char classificarPaciente(Paciente p) {
    if (p.idade > 80) {
        return 'U';
    }

    if (p.gestante == 'S' ||
        p.necessidadeEspecial == 'S') {
        return 'P';
    }

    return 'N';
}

// Localiza a proxima senha, respeitando prioridades
int proximoPaciente(void) {
    char prioridades[] = {'U', 'P', 'N'};

    for (int p = 0; p < 3; p++) {
        for (int i = 0; i < total; i++) {
            if (!pacientes[i].atendido &&
                pacientes[i].tipo == prioridades[p]) {
                return i;
            }
        }
    }

    return -1;
}

// Exibe a proxima senha no painel
void mostrarPainel(void) {
    int posicao = proximoPaciente();

    printf("\n================================\n");
    printf("       PAINEL DA CLINICA\n");
    printf("================================\n");

    if (posicao == -1) {
        printf("Nenhuma senha aguardando.\n");
    } else {
        printf("PROXIMA SENHA: %s\n",
               pacientes[posicao].senha);
    }

    printf("================================\n");
}

// Cadastra paciente e gera senha
void retirarSenha(void) {
    if (total >= MAX_PACIENTES) {
        printf("\nLimite de pacientes atingido!\n");
        return;
    }

    Paciente p = {0};

    printf("\n====== RETIRAR SENHA ======\n");

    printf("Nome: ");
    scanf(" %99[^\n]", p.nome);

    printf("Idade: ");
    if (scanf("%d", &p.idade) != 1 ||
        p.idade < 0 || p.idade > 130) {
        printf("Idade invalida!\n");
        return;
    }

    printf("Genero (F/M/O): ");
    scanf(" %c", &p.genero);

    if (p.genero == 'F' || p.genero == 'f') {
        printf("Esta gestante? (S/N): ");
        scanf(" %c", &p.gestante);
    }

    printf("Possui necessidade especial? (S/N): ");
    scanf(" %c", &p.necessidadeEspecial);

    // Padroniza respostas minusculas
    if (p.gestante == 's') {
        p.gestante = 'S';
    }

    if (p.necessidadeEspecial == 's') {
        p.necessidadeEspecial = 'S';
    }

    p.tipo = classificarPaciente(p);

    // Geracao automatica de senhas
    switch (p.tipo) {
        case 'U':
            contadorUrgente++;
            snprintf(p.senha, sizeof(p.senha),
                     "U%03d", contadorUrgente);
            break;

        case 'P':
            contadorPreferencial++;
            snprintf(p.senha, sizeof(p.senha),
                     "P%03d", contadorPreferencial);
            break;

        default:
            contadorNormal++;
            snprintf(p.senha, sizeof(p.senha),
                     "N%03d", contadorNormal);
            break;
    }

    p.atendido = 0;
    pacientes[total] = p;
    total++;

    printf("\n================================\n");
    printf("        SENHA GERADA\n");
    printf("================================\n");
    printf("Paciente: %s\n", p.nome);
    printf("Senha: %s\n", p.senha);

    if (p.tipo == 'U') {
        printf("Categoria: URGENTE\n");
    } else if (p.tipo == 'P') {
        printf("Categoria: PREFERENCIAL\n");
    } else {
        printf("Categoria: NORMAL\n");
    }

    printf("================================\n");
}

// Registra o atendimento
void registrarAtendimento(void) {
    int posicao = proximoPaciente();

    if (posicao == -1) {
        printf("\nNao ha pacientes aguardando.\n");
        return;
    }

    printf("\n====== REGISTRAR ATENDIMENTO ======\n");

    printf("Senha: %s\n",
           pacientes[posicao].senha);

    printf("Paciente: %s\n",
           pacientes[posicao].nome);

    printf("Idade: %d\n",
           pacientes[posicao].idade);

    pacientes[posicao].atendido = 1;

    printf("\nAtendimento registrado!\n");
}