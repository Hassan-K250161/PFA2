#include <stdio.h>
#include <string.h>

void encodeMessage(char msg[]);
void decodeMessage(char msg[]);
void toggleBits(char msg[]);

int main() {
    char msg[200];
    int choice;

    while (1) {
        printf("\n--- TCS Message System ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if (choice == 1) {
            printf("Enter message to encode: ");
            scanf(" %[^\n]", msg);
            encodeMessage(msg);
        }
        else if (choice == 2) {
            printf("Enter message to decode: ");
            scanf(" %[^\n]", msg);
            decodeMessage(msg);
        }
        else if (choice == 3) {
            printf("Exiting system...\n");
            break;
        }
        else {
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}

void encodeMessage(char msg[]) {
    int len = strlen(msg);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }

    toggleBits(msg);

    printf("Encoded message: %s\n", msg);
}

void decodeMessage(char msg[]) {
    int len = strlen(msg);
    char temp;

    toggleBits(msg);

    for (int i = 0; i < len / 2; i++) {
        temp = msg[i];
        msg[i] = msg[len - i - 1];
        msg[len - i - 1] = temp;
    }

    printf("Decoded message: %s\n", msg);
}

void toggleBits(char msg[]) {
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ (1 << 1);
        msg[i] = msg[i] ^ (1 << 4);
    }
}