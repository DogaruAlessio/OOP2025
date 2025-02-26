//1
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int ConvertireNumar(const char* sir)
{
    int num = 0;
    int c = strlen(sir);

    for (int i = 0; i <= c; i++)
    {
        if (sir[i] != '\0')
        {
            if (sir[i] >= '0' && sir[i] <= '9')
                num = num * 10 + (sir[i] - '0');
        }
    }
    return num;
}

int main()
{
    char numere[100];
    int suma = 0;
    FILE* fisier;

    if (fopen_s(&fisier, "in.txt", "r") != 0)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    while (fgets(numere, 100, fisier) != NULL)
    {
        suma = suma + ConvertireNumar(numere);
    }

    fclose(fisier);
    cout << suma;
    return 0;
}



//2
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 1000

void sortWords(char* words[], int n) {
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (strlen(words[i]) < strlen(words[j]) || (strlen(words[i]) == strlen(words[j]) && strcmp(words[i], words[j]) > 0)) 
            {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    char sentence[MAX_LEN], *words[MAX_WORDS];
    int word_count = 0;
    char* context;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LEN, stdin);
    sentence[strcspn(sentence, "\n")] = 0;

    char* token = strtok_s(sentence, " ", &context);
    while (token) {
        words[word_count++] = token;
        token = strtok_s(NULL, " ", &context);
    }

    sortWords(words, word_count);

    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}



//3
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}