#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, const char *key);
void decrypt(char *text, const char *key);

int main() {
    char message[1024];
    char key[1024];
    int option;
    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y') {
        printf("===== VIGENERE CIPHER =====\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        while ((getchar()) != '\n'); // limpiar buffer

        printf("Enter the message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        printf("Enter the key (letters only): ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        // Convert key to uppercase for uniformity
        for (int i = 0; key[i]; i++) {
            key[i] = toupper(key[i]);
        }

        if (option == 1) {
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
        } else if (option == 2) {
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
        } else {
            printf("Invalid option.\n");
        }

        printf("\nAnother operation? (y/n): ");
        scanf(" %c", &repeat);
    }

    return 0;
}

void encrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int keyShift = key[keyIndex % keyLen] - 'A';

            text[i] = (text[i] - base + keyShift) % 26 + base;
            keyIndex++;
        }
    }
}

void decrypt(char *text, const char *key) {
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int keyShift = key[keyIndex % keyLen] - 'A';

            text[i] = (text[i] - base - keyShift + 26) % 26 + base;
            keyIndex++;
        }
    }
}
