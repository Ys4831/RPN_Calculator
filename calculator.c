#include <stdio.h>
#include <string.h>
#include <math.h>

typedef float val;
#define Y stack[stacksize - 2]
#define X stack[stacksize - 1]

val stack[9];
int stacksize = 0;

void display_stack() { 
    int i;

    for (i = 0; i < stacksize; i++) {
        printf("    %g\n", stack[i]);
    }
}

void display_result(int code) {
    switch (code) {
        case 0 : 
            display_stack();
            break;
        case 1 : 
            printf("Unknow command\n");
            break;
        case 2 : 
            printf("Stack too small\n");
            break;
        case 3 :                                                                //template
            printf("\n");
            break;
    }
}

int main () {
    
    char cmd[255];

    printf("For help, enter h\n");
    printf("Enter command : ");

    while (1) {
        scanf("%s", cmd);   
        int error_code = 0;

        if(strcmp(cmd, "q") == 0) {
            break;
        } else if (strcmp(cmd, "help") == 0) {
            printf("\nCOMMAND\n'h' = help\n'q' = quit\n\'+' = addition\n'*' = multiplication\n'chs' = change sign\n'inv' = inverse\n");
        } else if (strcmp(cmd, "+") == 0) {                                     //+
            if (stacksize < 2) {
                error_code = 2;
            } else {
                Y = X + Y;
                stacksize--;
            }        
        } else if (strcmp(cmd, "*") == 0) {                                     //*
            if (stacksize < 2) {
                error_code = 2;
            } else {
                Y = X * Y;
                stacksize--;         
            }
        } else if (strcmp(cmd, "chs") == 0) {
            X = -X;
        } else if ((cmd[0] >= 48) && (cmd[0] <= 57)) {                          //number
            val nb;
            sscanf(cmd, "%g", &nb);
            stack[stacksize] = nb;
            stacksize++;            
        } else {                                                                //error
            error_code = 1;
        }
        display_result(error_code);
    }
    return 0;
}
