#include <stdio.h>    // Biblioteca padrão para entrada/saída.
#include <stdlib.h>   // Biblioteca para funções de conversão e alocação dinâmica.
#include <string.h>   // Biblioteca para manipulação de strings.
#include <ctype.h>    // Biblioteca para funções de caracteres.
#include <cs50.h>     // Biblioteca CS50 para interação com o usuário.

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./cesar chave\n"); // Verifica se o usuário forneceu exatamente um argumento.
        return 0;
    }

    string chave = argv[1]; // Obtém a chave do argumento de linha de comando.

    for (int i = 0; i < strlen(chave); i++)
    {
        if (!isdigit(chave[i]))
        {
            printf("./cesar chave\n"); // Verifica se a chave é um número.
            return 0;
        }
    }

    int c = atoi(chave); // Converte a chave para um número inteiro.

    string textoSimples = get_string("Texto Simples: "); // Solicita o texto simples ao usuário.
    int tamanho = strlen(textoSimples);
    char textoCodificado[tamanho + c]; // Aloca espaço para o texto codificado.

    for (int i = 0; i < tamanho; i++)
    {
        if (isalpha(textoSimples[i]))
        {
            char caractere = isupper(textoSimples[i]) ? 'A' : 'a'; // Obtém o caractere base ('A' ou 'a').
            textoCodificado[i] = (textoSimples[i] - caractere + c) % 26 + caractere; // Realiza a cifra de César.
        }
        else
        {
            textoCodificado[i] = textoSimples[i]; // Mantém caracteres não alfabéticos inalterados.
        }
    }
    textoCodificado[tamanho] = '\0'; // Adiciona o caractere nulo ao final do texto codificado.

    printf("Texto Codificado: %s\n", textoCodificado); // Imprime o texto codificado.

    return 0;
}
