#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char number[20];
    int valid = 1;
    printf("Enter a telecom number: ");
    scanf("%s", number);
    int len = strlen(number);
    if (len != 11){
        valid = 0;
    }
    else if (number[0] != '0' || number[1] != '1'){
        valid = 0;
    }
    else{
        for (int i = 0; i < len; i++){
            if (!isdigit(number[i])){
                valid = 0; 
                break;
            }
        }
    }
    if (valid){
        printf("%s is a valid telecom number.\n", number);
    }
    else{
        printf("%s is an invalid number.\n", number);
    }
    return 0;
}
