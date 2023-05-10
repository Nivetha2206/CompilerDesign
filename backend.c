#include <stdio.h>

int main() {
    char statements[10][10];
    int reg = 0; // Register counter
    printf("Enter the number of statements: ");
    int num_statements;
    scanf("%d", &num_statements);
    printf("Enter the statements:\n");
    for (int i = 0; i < num_statements; i++) {
        scanf("%s", statements[i]);
    }
    printf("\n\tStatements\tTarget code\n");
    for (int i = 0; i < num_statements; i++) {
        char dest_var = statements[i][0];
        char op = statements[i][3];
        char src_var = statements[i][4];
        int reg_no = src_var - '0';
        if (reg_no < 0 || reg_no > 9) { // If src_var is not a number, it must be a variable
            printf("\tmov %c, R%d\n", src_var, ++reg);
            reg_no = reg;
        }
        printf("\t%s R%d, %c\n", op == '=' ? "mov" : op == '+' ? "add" : op == '-' ? "sub" : op == '*' ? "mul" : "div", reg_no, dest_var);
        printf("\t\t\t\t\t\t");
        printf("%s\n", op == '=' ? "" : op == '+' || op == '-' ? "add" : "mul");
    }
    return 0;
}