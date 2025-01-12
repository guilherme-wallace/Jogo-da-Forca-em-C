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

void forca() {
    int maximoDeTentativas = 6;
    char palavra[100];
    char acertos[52];
    char letrasTentadas[52];
    int tentativas = 0;
    int erros = 0;

    printf("Informa a pavrada secreta: ");
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