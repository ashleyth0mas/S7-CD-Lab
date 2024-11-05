#include <stdio.h>
#include <string.h>

void main() {
    char stack[20], ip[20], opt[10][10][1], ter[10];
    int i, j, k, n, top = 0, col = 0, row = 0;

    // Initialize stack and input arrays
    for (i = 0; i < 20; i++) {
        stack[i] = '\0';
        ip[i] = '\0';
    }
    // Initialize operator precedence table with empty values
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            opt[i][j][0] = '\0';
        }
    }

    printf("Enter the number of terminals:\n");
    scanf("%d", &n);
    printf("\nEnter the terminals:\n");
    scanf("%s", ter);

    // Read operator precedence table values
    printf("\nEnter the table values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value for %c %c: ", ter[i], ter[j]);
            scanf("%s", opt[i][j]);
        }
    }

    // Display the operator precedence table
    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n\t");
    for (i = 0; i < n; i++) {
        printf("\t%c", ter[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%c", ter[i]);
        for (j = 0; j < n; j++) {
            printf("\t%c", opt[i][j][0]);
        }
        printf("\n");
    }

    stack[top] = '$';
    printf("\nEnter the input string (end with $): ");
    scanf("%s", ip);

    i = 0;
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, ip);

    while (i <= strlen(ip)) {
        for (k = 0; k < n; k++) {
            if (stack[top] == ter[k])
                col = k;
            if (ip[i] == ter[k])
                row = k;
        }

        if ((stack[top] == '$') && (ip[i] == '$')) {
            printf("String is accepted\n");
            break;
        } else if ((opt[col][row][0] == '<') || (opt[col][row][0] == '=')) {
            stack[++top] = ip[i];
            printf("Shift %c", ip[i]);
            i++;
        } else if (opt[col][row][0] == '>') {
            while (stack[top] != '<') {
                --top;
            }
            top--;
            printf("Reduce");
        } else {
            printf("\nString is not accepted\n");
            break;
        }

        printf("\n");
        for (k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");
        for (k = i; k < strlen(ip); k++) {
            printf("%c", ip[k]);
        }
        printf("\t\t\t");
    }
}
