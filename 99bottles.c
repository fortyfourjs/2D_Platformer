#include <stdio.h>

int main()
{
    for(int i = 99; i>=1; i--)
        if (i>1)
        {
            printf("%d bottles of beer \ntake one down, \n", i);
            
        }
        else
        {
            printf("%d bottle of beer ", i);
        }
        
}
