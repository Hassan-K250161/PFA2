#include <stdio.h>

void updateSector(int grid[3][3]);
void querySector(int grid[3][3]);
void runDiagnostic(int grid[3][3]);
void displayMenu();

int main() {
    int grid[3][3] = {0};
    int choice;

    printf("--- IESCO Power Grid Monitoring System ---\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            updateSector(grid);
        } 
        else if (choice == 2) {
            querySector(grid);
        } 
        else if (choice == 3) {
            runDiagnostic(grid);
        } 
        else if (choice == 4) {
            printf("Exiting system... Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid chice! Try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Update Sevtor Status\n");
    printf("2. Query Sector Status\n");
    printf("3. Run System Diagnostic\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void updateSector(int grid[3][3]) {
    int row, col, flag, action;

    printf("Enter row (0-2): ");
    scanf("%d", &row);
    printf("Enter column (0-2): ");
    scanf("%d", &col);

    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("Select flag to update:\n");
    printf("0. Power Status (1=ON, 0=OFF)\n");
    printf("1. Overload Warning (1=Overloaded, 0=Normal)\n");
    printf("2. Maintenance Required (1=Yes, 0=No)\n");
    printf("Enter flag bit (0-2): ");
    scanf("%d", &flag);

    printf("Enter 1 to SET or 0 to CLEAR the flag: ");
    scanf("%d", &action);

    if (action == 1) {
        grid[row][col] |= (1 << flag);
    } else {
        grid[row][col] &= ~(1 << flag);
    }

    printf("Sector [%d][%d] updated successfully!\n", row, col);
}

void querySector(int grid[3][3]) {
    int row, col;
    printf("Enter row (0-2): ");
    scanf("%d", &row);
    printf("Enter column (0-2): ");
    scanf("%d", &col);

    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid coordinates!\n");
        return;
    }

    int value = grid[row][col];

    printf("\n--- Sector [%d][%d] Status ---\n", row, col);
    printf("Power Status: %s\n", (value & 1) ? "ON" : "OFF");
    printf("Overload Warning: %s\n", (value & 2) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (value & 4) ? "YES" : "NO");
}

void runDiagnostic(int grid[3][3]) {
    int overloadCount = 0, maintenanceCount = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] & 2)
                overloadCount++;
            if (grid[i][j] & 4)
                maintenanceCount++;
        }
    }

    printf("\n--- System Diagnostic ---\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Maintenance Required: %d\n", mainteanceCount);
}