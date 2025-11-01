#include <stdio.h>
#include <string.h>

void addBook(int isbn[], char title[][50], float price[], int qty[], int *count);
void makeSale(int isbn[], int qty[], int count);
void lowStock(int isbn[], char title[][50], int qty[], float price[], int count);

int main() {
    int isbn[100];
    char title[100][50];
    float price[100];
    int qty[100];
    int count = 0;
    int ch;

    while (1) {
        printf("\n--- LIBERTY BOOKS MENU ---\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addBook(isbn, title, price, qty, &count);
                break;
            case 2:
                makeSale(isbn, qty, count);
                break;
            case 3:
                lowStock(isbn, title, qty, price, count);
                break;
            case 4:
                printf("Exiting system... Bye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addBook(int isbn[], char title[][50], float price[], int qty[], int *count) {
    int id, exists = 0;
    printf("Enter ISBN: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (isbn[i] == id) {
            exists = 1;
            break;
        }
    }

    if (exists) {
        printf("Book with this ISBN already exists!\n");
    } else {
        isbn[*count] = id;
        printf("Enter title: ");
        scanf(" %[^\n]", title[*count]);
        printf("Enter price: ");
        scanf("%f", &price[*count]);
        printf("Enter quantity: ");
        scanf("%d", &qty[*count]);
        (*count)++;
        printf("Book added!\n");
    }
}

void makeSale(int isbn[], int qty[], int count) {
    int id, sold, found = 0;
    printf("Enter ISBN to sell: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (isbn[i] == id) {
            found = 1;
            printf("Enter number of copies sold: ");
            scanf("%d", &sold);
            if (sold > qty[i]) {
                printf("Not enough stock!\n");
            } else {
                qty[i] -= sold;
                printf("Sale processed! Remaining stock: %d\n", qty[i]);
            }
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void lowStock(int isbn[], char title[][50], int qty[], float price[], int count) {
    int flag = 0;
    printf("\n--- LOW STOCK REPORT (Qty < 5) ---\n");
    for (int i = 0; i < count; i++) {
        if (qty[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Qty: %d\n", isbn[i], title[i], price[i], qty[i]);
            flag = 1;
        }
    }
    if (!flag) {
        printf("All books sufficiently stocked.\n");
    }
}