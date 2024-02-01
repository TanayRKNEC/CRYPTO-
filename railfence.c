#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void railFenceDecrypt(char message[], int rails,char* decrypted, int len)
{
    int rail, i, j = 0, k = 0;
    
    for (rail = 0; rail < rails; rail++)
    {
        i = rail;
        j = 0;
        while (i < len)
        {
            decrypted[i] = message[k++]; 
            if (rail == 0 || rail == rails - 1)
                i += 2 * (rails - 1);
            else
            {
                if (j % 2 == 0)
                    i += 2 * (rails - rail - 1);
                else
                    i += 2 * rail;
                j++;
            }
        }
    }
    decrypted[len] = '\0';
}


void railFenceEncrypt(char message[], int rails,char* encrypted, int len)
{
    int rail, i, j = 0, k = 0;

    for (rail = 0; rail < rails; rail++)
    {
        i = rail;
        j = 0;
        while (i < len)
        {
            encrypted[k++] = message[i];
            if (rail == 0 || rail == rails - 1)
                i += 2 * (rails - 1);
            else
            {
                if (j % 2 == 0)
                    i += 2 * (rails - rail - 1);
                else
                    i += 2 * rail;
                j++;
            }
        }
    }
    encrypted[k] = '\0';
}

int main()
{
    char message[100];
    int size, rails;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    for (size = 0; message[size] != '\0'; ++size);

    char encrypted[size],decrypted[size];

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    railFenceEncrypt(message,rails,encrypted,size);
    railFenceDecrypt(encrypted,rails,decrypted,size);

    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
}