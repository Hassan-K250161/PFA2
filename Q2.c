#include <stdio.h>
#include <string.h>

void getCustomer(char cname[], char cnic[]);
void showItems(int stock[], int price[]);
void addItem(int stock[], int cart[]);
float makeBill(int cart[], int price[], float *discount);
void showSlip(char cname[], char cnic[], int cart[], int price[], float total, float discount);

int main() {
    char cname[50], cnic[20];
    int stock[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};
    int cart[4] = {0, 0, 0, 0};
    int choice;
    float total = 0, discount = 0;

    getCustomer(cname, cnic);

    while (1) {
        printf("\n--- SuperMart Menu ---\n");
        printf("1. Show Items\n");
        printf("2. Add to Cart\n");
        printf("3. Make Bill\n");
        printf("4. Show Invoice\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showItems(stock, price);
        } 
        else if (choice == 2) {
            addItem(stock, cart);
        } 
        else if (choice == 3) {
            total = makeBill(cart, price, &discount);
        } 
        else if (choice == 4) {
            showSlip(cname, cnic, cart, price, total, discount);
        } 
        else if (choice == 5) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid option, try again.\n");
        }
    }

    return 0;
}

void getCustomer(char cname[], char cnic[]) {
    printf("Enter your name: ");
    scanf("%s", cname);
    printf("Enter your CNIC: ");
    scanf("%s", cnic);
}

void showItems(int stock[], int price[]) {
    printf("\nCode\tStock\tPrice\n");
    for (int i = 0; i < 4; i++) {
        printf("00%d\t%d\t%d\n", i + 1, stock[i], price[i]);
    }
}

void addItem(int stock[], int cart[]) {
    int code, qty;
    printf("Enter item code (001-004): ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (code >= 1 && code <= 4) {
        int i = code - 1;
        if (qty <= stock[i]) {
            cart[i] += qty;
            stock[i] -= qty;
            printf("Item added!\n");
        } else {
            printf("Not enough in stock.\n");
        }
    } else {
        printf("Invalid code.\n");
    }
}

float makeBill(int cart[], int price[], float *discount) {
    float total = 0;
    char promo[20], ans[5];
    *discount = 0;

    for (int i = 0; i < 4; i++) {
        total += cart[i] * price[i];
    }

    printf("Do you have promo code? (yes/no): ");
    scanf("%s", ans);
    if (strcmp(ans, "yes") == 0) {
        printf("Enter promo code: ");
        scanf("%s", promo);
        if (strcmp(promo, "Eid2025") == 0) {
            *discount = total * 0.25;
            printf("25%% discount applied!\n");
        } else {
            printf("Invalid code.\n");
        }
    }

    printf("Total without discount: %.2f\n", total);
    printf("Total with discount: %.2f\n", total - *discount);
    return total;
}

void showSlip(char cname[], char cnic[], int cart[], int price[], float total, float discount) {
    printf("\n--- Invoice ---\n");
    printf("Customer: %s\n", cname);
    printf("CNIC: %s\n", cnic);
    printf("\nCode\tQty\tPrice\tTotal\n");

    for (int i = 0; i < 4; i++) {
        if (cart[i] > 0) {
            printf("00%d\t%d\t%d\t%d\n", i + 1, cart[i], price[i], cart[i] * price[i]);
        }
    }

    printf("\nBill without discount: %.2f\n", total);
    printf("Bill with discount: %.2f\n", total - discount);
}