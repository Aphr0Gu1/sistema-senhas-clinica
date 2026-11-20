
#ifndef CLINICA_H
#define CLINICA_H

#define MAX_PACIENTES 100

// Estrutura que representa um paciente
typedef struct {
    char nome[100];
    int idade;
    char genero;
    char gestante;
    char necessidadeEspecial;
    char senha[10];
    char tipo;
    int atendido;
} Paciente;

// Funcoes disponiveis para o sistema
void retirarSenha(void);
void registrarAtendimento(void);
void mostrarPainel(void);
int proximoPaciente(void);

#endif