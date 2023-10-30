#include <stdio.h>  // Biblioteca padrão para entrada/saída.
#include <cs50.h>   // Biblioteca CS50 para interação com o usuário.
#include <string.h> // Biblioteca para manipulação de strings.
#include <ctype.h>  // Biblioteca para funções de caracteres.
#include <math.h>   // Biblioteca para funções matemáticas.

int ColemanForm();  // Protótipo da função ColemanForm.

int main()
{
    string texto = get_string("Texto: "); // Solicita ao usuário que insira um texto.
    int letras = 0;
    int palavras = 1;
    int frases = 0;
    int tamanhoTexto = strlen(texto);

    for (int i = 0; i <= tamanhoTexto; i++)
    {
        if (isalpha(texto[i]))
        {
            letras++;  // Conta as letras no texto.
        }
        if (isspace(texto[i]))
        {
            palavras++; // Conta as palavras no texto.
        }
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            frases++;  // Conta as frases no texto.
        }
    }

    // Calcula o índice Coleman-Liau e imprime na tela.
    printf("Grade: %d\n", ColemanForm(letras, frases, palavras));
}

int ColemanForm(int letras, int frases, int palavras)
{
    float index;
    float L = ((float)letras / palavras) * 100;
    float S = ((float)frases / palavras) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    if (index < 1)
    {
        printf("Grade Menor que 1\n"); // Mensagem se o índice for menor que 1.
    }
    if (index > 16)
    {
        printf("Grade16+\n"); // Mensagem se o índice for maior que 16.
    }

    return index;  // Retorna o índice calculado.
}
