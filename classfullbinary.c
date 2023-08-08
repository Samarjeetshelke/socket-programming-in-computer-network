#include <stdio.h>

int validornot(char *s)
{
    int i;
    int flg = 0;
    int x = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '.')
        {
            flg++;
        }
        else{
             if (s[i] != '0' && s[i] != '1')
            {
                x = 1;
                break;
            }
        }
       
        i++;
    }
    printf("%d & %d",x,flg);
    if (flg == 3 && x == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    char ip[40];
    int flg = 0;
    int i = 0;

    printf("\nEnter The ip: ");
    scanf("%s", ip);

    if (validornot(ip))
    {
        
            if (ip[0] == '0')
            {
                printf("\nBelog to the A class. ");
                flg = 1;
            }
            else if (ip[1] == '0')
            {
                printf("\nBelong to the B class. ");
                flg = 2;
            }
            else if (ip[2] == '0')
            {
                printf("\nBelong to the C class. ");
                flg = 3;
            }
            else if (ip[3] == '0')
            {
                printf("\nBelong to the D class. ");
            }
            else if (ip[4] == '0')
            {
                printf("\nBelong to the E class. ");
            }
            else
            {
                printf("\nNOT DEFINED!");
            }
        
    }
    else{
        printf("Invalid IP address");
    }

}