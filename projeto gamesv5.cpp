#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

BOOL WINAPI tratar_controle(DWORD evento) {
    if (evento == CTRL_C_EVENT) {
        return TRUE;
    }
    return FALSE;
}

void exibir_menu() {
    system("cls");
    printf("===== JOGOS BACANAS =====\n");
    printf("1: Perguntas e Respostas\n");
    printf("2: Cobra na Caixa!\n");
    printf("3: Gousmas War\n");
    printf("4: Sair\n");
    printf("=========================\n");
    printf("Escolha uma opcao: ");
}

void limpar_tela() {
    system("cls");
}

void limpar_buffer() {
    while (getchar() != '\n');
}

void pausar() {
    while (getchar() != '\n');
    system("cls");
}

int ler_opcao(int min, int max) {
    int valor;
    while (1) {
        if (scanf("%d", &valor) == 1 && valor >= min && valor <= max) {
            limpar_buffer();
            return valor;
        }
        limpar_buffer();
        printf("Opcao invalida! Digite uma opcao valida: ");
    }
}

int tem_gousma_viva(int status[][2], int jogador) {
    for (int i = 0; i < 2; i++)
        if (status[jogador][i] == 0) return 1;
    return 0;
}

int primeira_viva(int status[][2], int jogador) {
    for (int i = 0; i < 2; i++)
        if (status[jogador][i] == 0) return i;
    return -1;
}

int exibir_gousmas(int furia[][2], int status[][2], int jogador, int apenas_vivas) {
    int count = 0;
    for (int i = 0; i < 2; i++) {
        if (apenas_vivas && status[jogador][i] != 0) continue;
        count++;
        if (status[jogador][i] == 0)
            printf(" %d: Gousma %d (Furia %d/5) [VIVA]\n", count, i + 1, furia[jogador][i]);
        else
            printf(" %d: Gousma %d [MORTA]\n", count, i + 1);
    }
    return count;
}

int indice_real(int status[][2], int jogador, int escolha, int apenas_vivas) {
    int count = 0;
    for (int i = 0; i < 2; i++) {
        if (apenas_vivas && status[jogador][i] != 0) continue;
        count++;
        if (count == escolha) return i;
    }
    return -1;
}

int main()
{
    SetConsoleCtrlHandler(tratar_controle, TRUE);

    int esc;
    int r, r2, r3, r4, r5;

    srand(time(NULL));

    do {
        exibir_menu();
        esc = ler_opcao(1, 4);

        switch (esc)
        {
            case 1:
                limpar_tela();
                printf("===== PERGUNTAS E RESPOSTAS =====\n\n");

                printf("1: Qual e o maior roedor do mundo?\n");
                printf(" 1: Rato obeso\n 2: Esquilo\n 3: Capivara\n 4: Chinchila\n");
                printf("Resposta: ");
                r = ler_opcao(1, 4);
                if (r == 3)
                    printf("Resposta certa!\n\n");
                else
                    printf("Voce errou!\n\n");
                printf("Pressione ENTER para continuar...");
                pausar();

                printf("2: Onde fica o Brasil?\n");
                printf(" 1: Africa\n 2: Europa\n 3: Asia\n 4: America do Sul\n");
                printf("Resposta: ");
                r2 = ler_opcao(1, 4);
                if (r2 == 4)
                    printf("Resposta certa!\n\n");
                else
                    printf("Voce errou!\n\n");
                printf("Pressione ENTER para continuar...");
                pausar();

                printf("3: Quantas cores tem o arco-iris?\n");
                printf(" 1: 7 cores\n 2: 20 cores\n 3: 5 cores\n 4: 3 cores\n");
                printf("Resposta: ");
                r3 = ler_opcao(1, 4);
                if (r3 == 1)
                    printf("Resposta certa!\n\n");
                else
                    printf("Voce errou!\n\n");
                printf("Pressione ENTER para continuar...");
                pausar();

                printf("4: Qual foi o maior aviao comercial do mundo?\n");
                printf(" 1: Boeing 727\n 2: Antonov 225\n 3: Airbus A380\n 4: Embraer 195\n");
                printf("Resposta: ");
                r4 = ler_opcao(1, 4);
                if (r4 == 2)
                    printf("Resposta certa!\n\n");
                else
                    printf("Voce errou!\n\n");
                printf("Pressione ENTER para continuar...");
                pausar();

                printf("5: A franquia de Star Wars comeca a partir de qual episodio?\n");
                printf(" 1: Episodio 4\n 2: Episodio 1\n 3: Rogue One\n 4: Episodio 3\n");
                printf("Resposta: ");
                r5 = ler_opcao(1, 4);
                if (r5 == 1)
                    printf("Resposta certa!\n\n");
                else
                    printf("Voce errou!\n\n");
                printf("Pressione ENTER para voltar ao menu...");
                pausar();
                break;

            case 2:
            {
                limpar_tela();
                printf("===== COBRA NA CAIXA =====\n\n");

                char *nomes[7] = {"indiana(nao jones)", "Lara", "Nathan", "juninho", "cleiton", "jeffrey", "bing chilling"};

                printf("--- Escolha de Nomes ---\n\n");

                printf("Jogador 1, escolha seu nome:\n");
                for (int i = 0; i < 7; i++)
                    printf(" %d: %s\n", i + 1, nomes[i]);
                int escolha_j1 = ler_opcao(1, 7) - 1;
                char *nome_j1 = nomes[escolha_j1];

                limpar_tela();
                printf("===== COBRA NA CAIXA =====\n\n");
                printf("--- Escolha de Nomes ---\n\n");

                printf("Jogador 2, escolha seu nome:\n");
                for (int i = 0; i < 7; i++)
                    printf(" %d: %s\n", i + 1, nomes[i]);
                int escolha_j2 = ler_opcao(1, 7) - 1;
                char *nome_j2 = nomes[escolha_j2];

                limpar_tela();
                printf("===== COBRA NA CAIXA =====\n\n");
                printf("%s vs %s\n\n", nome_j1, nome_j2);

                int turno = rand() % 2;
                printf("Sorteando quem comeca...\n\n");
                printf(">>> %s comeca! <<<\n\n", turno == 0 ? nome_j1 : nome_j2);
                printf("Pressione ENTER para continuar...");
                pausar();

                // 0 = vazia, 1 = cobra, 2 = botao
                int caixas[5] = {0, 0, 0, 1, 2};

                // embaralha as caixas — algoritmo Fisher-Yates
                for (int i = 4; i > 0; i--) {
                    int j = rand() % (i + 1);
                    int temp = caixas[i];
                    caixas[i] = caixas[j];
                    caixas[j] = temp;
                }

                int abertas[5] = {0, 0, 0, 0, 0};
                int vencedor = -1;
                int perdedor = -1;

                while (vencedor == -1 && perdedor == -1)
                {
                    limpar_tela();
                    printf("===== COBRA NA CAIXA =====\n\n");

                    char *nome_turno = turno == 0 ? nome_j1 : nome_j2;

                    // exibe caixas
                    for (int i = 0; i < 5; i++)
                        printf(abertas[i] ? "     " : " ___ ");
                    printf("\n");
                    for (int i = 0; i < 5; i++)
                        printf(abertas[i] ? "     " : "|   |");
                    printf("\n");
                    for (int i = 0; i < 5; i++)
                        printf(abertas[i] ? "     " : "|___|");
                    printf("\n");
                    for (int i = 0; i < 5; i++)
                        printf("  %d  ", i + 1);
                    printf("\n\n");

                    printf("Turno de %s!\n\n", nome_turno);
                    printf("Escolha uma caixa:\n");

                    int opcoes[5] = {-1, -1, -1, -1, -1};
                    int count = 0;
                    for (int i = 0; i < 5; i++) {
                        if (!abertas[i]) {
                            opcoes[count++] = i;
                            printf(" %d: Caixa %d\n", count, i + 1);
                        }
                    }

                    int escolha = ler_opcao(1, count) - 1;
                    int caixa = opcoes[escolha];
                    abertas[caixa] = 1;

                    printf("\n%s abriu a caixa %d...\n\n", nome_turno, caixa + 1);

                    if (caixas[caixa] == 0)
                        printf("A caixa estava VAZIA!\n\n");
                    else if (caixas[caixa] == 1) {
                        printf("SSSSSS... TEM UMA COBRA! %s PERDEU!\n\n", nome_turno);
                        perdedor = turno;
                        vencedor = 1 - turno;
                    }
                    else {
                        printf("VOCE ENCONTROU O BOTAO! %s VENCEU!\n\n", nome_turno);
                        vencedor = turno;
                    }

                    if (vencedor == -1 && perdedor == -1) {
                        printf("Pressione ENTER para continuar...");
                        pausar();
                        turno = 1 - turno;
                    }
                }

                char *nome_vencedor = vencedor == 0 ? nome_j1 : nome_j2;
                printf("==============================\n");
                printf("  %s VENCEU O JOGO!\n", nome_vencedor);
                printf("==============================\n\n");

                printf("O que deseja fazer?\n");
                printf(" 1: Jogar novamente\n");
                printf(" 2: Voltar ao menu\n");
                int opcao_fim = ler_opcao(1, 2);
                if (opcao_fim == 1)
                    esc = 2;
                pausar();
                break;
            }

            case 3:
            {
                limpar_tela();
                printf("===== GOUSMAS WAR =====\n\n");

                int furia[2][2]  = {{1, 1}, {1, 1}};
                int status[2][2] = {{0, 0}, {0, 0}};
                int turno    = 0;
                int vencedor = -1;

                while (1)
                {
                    limpar_tela();
                    printf("===== GOUSMAS WAR =====\n\n");

                    for (int j = 0; j < 2; j++) {
                        printf("--- Jogador %d ---\n", j + 1);
                        exibir_gousmas(furia, status, j, 0);
                        printf("\n");
                    }

                    if (!tem_gousma_viva(status, 0)) { vencedor = 2; break; }
                    if (!tem_gousma_viva(status, 1)) { vencedor = 1; break; }

                    int inimigo = 1 - turno;
                    printf("=== Turno do Jogador %d ===\n", turno + 1);

                    printf("\nEscolha sua gousma para atacar:\n");
                    int n_atk = exibir_gousmas(furia, status, turno, 1);
                    int gousma_atk = indice_real(status, turno, ler_opcao(1, n_atk), 1);

                    printf("\nEscolha a gousma inimiga para atacar:\n");
                    int n_alvo = exibir_gousmas(furia, status, inimigo, 1);
                    int gousma_alvo = indice_real(status, inimigo, ler_opcao(1, n_alvo), 1);

                    int dano = furia[turno][gousma_atk];
                    furia[inimigo][gousma_alvo] += dano;
                    printf("\nGousma %d atacou Gousma %d causando %d de furia!\n",
                           gousma_atk + 1, gousma_alvo + 1, dano);

                    if (furia[inimigo][gousma_alvo] >= 5)
                    {
                        status[inimigo][gousma_alvo] = 1;
                        printf("\nGousma %d do Jogador %d MORREU!\n", gousma_alvo + 1, inimigo + 1);

                        if (tem_gousma_viva(status, inimigo))
                        {
                            printf("\nJogador %d escolha:\n", inimigo + 1);
                            printf(" 1: Reviver (divide furia com gousma viva)\n");
                            printf(" 2: Atacar com a gousma viva\n");
                            int decisao = ler_opcao(1, 2);

                            int gousma_viva = primeira_viva(status, inimigo);

                            if (decisao == 1)
                            {
                                int total = furia[inimigo][gousma_viva] + furia[inimigo][gousma_alvo];
                                furia[inimigo][gousma_viva] = total / 2;
                                furia[inimigo][gousma_alvo] = total - furia[inimigo][gousma_viva];
                                status[inimigo][gousma_alvo] = 0;
                                printf("\nGousma %d revivida! Furia: G%d=%d | G%d=%d\n",
                                       gousma_alvo + 1,
                                       gousma_viva + 1, furia[inimigo][gousma_viva],
                                       gousma_alvo + 1, furia[inimigo][gousma_alvo]);
                            }
                            else
                            {
                                printf("\nEscolha qual gousma inimiga atacar:\n");
                                int n_contra = exibir_gousmas(furia, status, turno, 1);
                                int alvo_contra = indice_real(status, turno, ler_opcao(1, n_contra), 1);

                                int dano_contra = furia[inimigo][gousma_viva];
                                furia[turno][alvo_contra] += dano_contra;
                                printf("\nGousma %d atacou Gousma %d causando %d de furia!\n",
                                       gousma_viva + 1, alvo_contra + 1, dano_contra);

                                if (furia[turno][alvo_contra] >= 5)
                                {
                                    status[turno][alvo_contra] = 1;
                                    printf("\nGousma %d do Jogador %d MORREU!\n", alvo_contra + 1, turno + 1);
                                }
                            }
                        }
                    }

                    printf("\nPressione ENTER para continuar...");
                    pausar();
                    turno = 1 - turno;
                }

                printf("\n==============================\n");
                printf("  Jogador %d VENCEU O JOGO!\n", vencedor);
                printf("==============================\n\n");
                printf("Pressione ENTER para voltar ao menu...");
                pausar();
                break;
            }

            case 4:
                limpar_tela();
                printf("Saindo... Ate logo!\n");
                break;
        }

    } while (esc != 4);

    return 0;
}