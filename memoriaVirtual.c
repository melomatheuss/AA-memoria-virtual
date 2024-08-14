#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TAMANHO_PAGINA 4096

int main() {
    FILE *arquivo;
    long tamanhoArquivo;
    size_t quantidadePaginasVirtuais;

    // Abrir o arquivo biblia.txt
    if ((arquivo = fopen("biblia.txt", "r")) == NULL) {
        perror("ERRO: Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Obter o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    if (tamanhoArquivo < 0) {
        perror("ERRO: Não foi possível obter o tamanho do arquivo");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Calcular a quantidade de páginas virtuais
    quantidadePaginasVirtuais = (size_t)((tamanhoArquivo + TAMANHO_PAGINA - 1) / TAMANHO_PAGINA);

    // Exibir as informações calculadas
    printf("O arquivo lido possui %ld bytes.\n", tamanhoArquivo);

    // Alocar memória para o conteúdo do arquivo
    char *conteudoArquivo = malloc(tamanhoArquivo);
    if (!conteudoArquivo) {
        perror("ERRO: Não foi possível alocar memória");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Ler o conteúdo do arquivo para a memória
    size_t tamanhoLido = fread(conteudoArquivo, 1, tamanhoArquivo, arquivo);
    if (ferror(arquivo) || tamanhoLido != tamanhoArquivo) {
        perror("ERRO: Falha ao ler o arquivo");
        free(conteudoArquivo);
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Manipular endereços de memória
    char *enderecoUltimoByte = conteudoArquivo + tamanhoArquivo - 1;

    // Imprimir os últimos 10 bytes do arquivo
    printf("Últimos 10 bytes do arquivo:\n");
    size_t start = tamanhoArquivo > 10 ? tamanhoArquivo - 10 : 0;
    for (size_t i = 0; i < 10 && start + i < tamanhoArquivo; i++) {
        printf("0x%02x ", (unsigned char)*(conteudoArquivo + start + i));
    }
    printf("\n");

    // Verificar e imprimir a mensagem sobre os últimos 6 bytes
    printf("Os últimos 6 bytes do arquivo são 'Amen.\\n'?\n");
    if (tamanhoArquivo >= 6 && strncmp(enderecoUltimoByte - 5, "Amen.\n", 6) != 0) {
        printf("ERRO: Os últimos 6 bytes não são 'Amen.\n'\n");
    } else {
        printf("Sim, os últimos 6 bytes são 'Amen.'\n\n");
    }

    // Fechar o arquivo e liberar a memória alocada
    fclose(arquivo);
    free(conteudoArquivo);

    return 0;
}
