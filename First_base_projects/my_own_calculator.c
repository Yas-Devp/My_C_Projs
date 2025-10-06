#include <stdio.h>
#include <stdbool.h>

void test(){
	double x=0, y=0;
    char oper = ' ';
    
    printf("enter values of x , operation type(+ - / *) and y :\n");
    scanf("%lf", &x);
    printf(" ");
    fflush(stdout);
    getchar();
    scanf("%c", &oper);
    scanf("%lf", &y);
    
    if(oper == '+'){
          printf(" =\n%.2lf", x+y);
    }else if(oper == '*'){
          printf(" =\n%.2lf", x*y);
    }else if(oper == '-'){
          printf(" =\n%.2lf", x-y);
    }else if(oper == '/'){
          printf(" =\n%.2lf", x/y);
    }
    
}

int main(){
    
    bool repeat = true;
    char answer= ' ';
    
    while(repeat){
        test();
        printf("\n------------------------------------------------\ndo you want to start again: (y / n)\n");
        getchar();
        scanf("%c", &answer);
        printf("\n-----------------------------------------------\n");
        if(answer == 'n' || answer == 'N'){
        	repeat = false;
        	printf("Finished in 0.0000s");
        }
    }
    
    return 0;
}

