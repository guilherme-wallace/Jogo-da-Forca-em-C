// Jogo da Forca -> ---- -- ----- :D
// passo 1 - fazer a Main -> Introduzá o game 
// passo 2 - função forca -> Fazá a lógica do game enquanto chama as funções de verificação
// passo 3 - funções auxiliares de verificação
// fim - correção de bugs e deixar o jogo bonitinho (fazer função para limpar o console)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void limparTela() {
    system("cls");
}

void mostraPalavra(char *palavra, char *acertos) {
    printf("Palavra: ");
    for (int i = 0; i < strlen(palavra); i++){
        if (acertos[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
}

void initAcertos(char *acertos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        acertos[i] = 0;
    }
}

int verificaLetra(char letra, char *letrasTentadas, int numeroDeTentativas) {
    for (int i = 0; i < numeroDeTentativas; i++) {
        if (letrasTentadas[i] == letra) {
            return 1;
        }
    }
    return 0;
}

int verificarAcerto(char letra, char *palavra, char *acertos) {
    int acertou = 0;
    for (int i = 0; i < strlen(palavra); i++) {
        if (tolower(palavra[i]) == letra && !acertos[i]) {
            acertos[i] = 1;
            acertou = 1;
        }
    }
    return acertou;
}

void forca() {
    int maximoDeTentativas = 6, tentativas = 0, erros = 0;
    char palavra[100], acertos[52], letrasTentadas[52], letra;

    printf("Informe a pavrada secreta: ");
    scanf("%s", palavra);
    getchar();

    limparTela();
    initAcertos(acertos, strlen(palavra));

    while (erros < maximoDeTentativas) {
        limparTela();
        printf("Jogo Da forca\n\n");
        mostraPalavra(palavra, acertos);

        printf("Letras que você tentou: ");
        for (int i = 0; i < tentativas; i++) {
            printf("%c ", letrasTentadas[i]);
        }
        printf("\n");
        printf("Tentativas restantes: %d\n\n", maximoDeTentativas - erros);
        printf("Informe uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        if (verificaLetra(letra, letrasTentadas, tentativas)) {
            printf("\nVocê já tentou essa letra. Tente novamente.\n");
            getchar();
            continue;
        }

        letrasTentadas[tentativas++] = letra;

        if (!verificaAcerto(letra, palavra, acertos)) {
            erros++;
        }
    }
    
}

int main() {
    char restart;
    do {
        forca();
        printf("\nQuer jogar de novo? (s/n): ");
        scanf(" %c", &restart);
    } while (tolower(restart) == 's');

    printf("bye bye! \n");
    return 0;    
}