# 🏥 Sistema de Gerenciamento de Senhas — Clínica Médica

Sistema acadêmico desenvolvido em **linguagem C**, com o objetivo de gerenciar senhas e organizar a ordem de atendimento de pacientes em uma clínica de especialidades médicas.

## 📌 Funcionalidades

- Cadastro de pacientes com nome, idade e gênero.
- Identificação de gestantes e pessoas com necessidades especiais.
- Geração automática de senhas.
- Classificação dos pacientes por prioridade.
- Painel que apresenta a próxima senha.
- Registro de atendimentos realizados.

## 🎫 Classificação das senhas

| Senha | Categoria | Critério |
|---|---|---|
| U001 | Urgente | Pacientes com mais de 80 anos |
| P001 | Preferencial | Gestantes ou pessoas com necessidades especiais |
| N001 | Normal | Pacientes que não se enquadram nas categorias anteriores |

As prioridades seguem as regras propostas no exercício acadêmico.

## 🛠️ Tecnologias e conceitos

- Linguagem C
- Estruturas `struct`
- Vetores
- Funções e modularização
- Estruturas condicionais e de repetição
- Manipulação de strings

## 📁 Estrutura do projeto

```text
sistema-senhas-clinica/
├── src/
│   ├── main.c
│   ├── clinica.c
│   └── clinica.h
├── README.md
└── .gitignore
```

## ⚙️ Como compilar

É necessário ter o compilador GCC instalado.

```bash
gcc scr/main.c scr/clinica.c -o clinica
```

## ▶️ Como executar no Windows

Após compilar, execute no terminal:

```powershell
.\clinica.exe
```

## 🧩 Modularização

O sistema está dividido em três arquivos:

- **main.c:** controla o menu e o fluxo principal do programa.
- **clinica.c:** implementa o cadastro de pacientes, a geração de senhas e o registro dos atendimentos.
- **clinica.h:** contém a estrutura dos pacientes e as declarações das funções.

## 🚀 Melhorias futuras

- [ ] Implementar armazenamento em arquivos.
- [ ] Criar histórico de atendimentos.
- [ ] Melhorar a validação dos dados.
- [ ] Desenvolver uma interface gráfica.

## 👨‍💻 Autor

Desenvolvido por [Aphr0Gu1](https://github.com/Aphr0Gu1).

Projeto acadêmico para estudo de lógica de programação e modularização em linguagem C.

**Observação:** sistema desenvolvido para fins educacionais, não destinado à triagem clínica real.
