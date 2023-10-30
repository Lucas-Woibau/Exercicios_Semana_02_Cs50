#include <stdio.h>  // Biblioteca padrão para entrada/saída.
#include <cs50.h>   // Biblioteca CS50 para interação com o usuário.
#include <string.h> // Biblioteca para manipulação de strings.
#include <ctype.h>  // Biblioteca para funções de caracteres.

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("O valor deve conter 26 letras\n"); // Verifica se o usuário forneceu exatamente um argumento de 26 letras.
        return 0;
    }

    string letras = argv[1]; // Obtém o alfabeto personalizado do argumento de linha de comando.

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(letras[i]))
        {
            printf("O valor deve conter 26 letras\n"); // Verifica se o alfabeto contém apenas letras.
            return 0;
        }
    }

    string textoSimples = get_string("Texto Simples :"); // Solicita o texto simples ao usuário.
    int tamanhoTexto = strlen(textoSimples);

    for (int i = 0; i < tamanhoTexto; i++)
    {
        if (isalpha(textoSimples[i]))
        {
            char caractere = isupper(textoSimples[i]) ? 'A' : 'a'; // Obtém o caractere base ('A' ou 'a').
            int indice = tolower(textoSimples[i]) - 'a'; // Calcula o índice no alfabeto personalizado.
            textoSimples[i] = isupper(textoSimples[i]) ? toupper(letras[indice]) : letras[indice]; // Substitui o caractere de acordo com o alfabeto personalizado.
        }
        else
        {
            textoSimples[i] = textoSimples[i]; // Mantém caracteres não alfabéticos inalterados.
        }
    }

    printf("Texto Codificado: %s\n", textoSimples); // Imprime o texto codificado.

    return 0;
}
