//
//  countSymbolsArray.c
//  
//
//  Created by USER on 28.12.16.
//
//

#include "countSymbolsArray.h"
#include <stdio.h>

int main()
{
    char *array[]= {"qwert", "yuiop", "asdfg", "hjkl"};
    size_t charSize = sizeof (char);
    size_t floatSize = sizeof (float);
    size_t intSize = sizeof (int);
    printf("\nChar size: %zu\n", charSize);
    printf("\nFloat size: %zu\n", floatSize);
    printf("\nInt size: %zu\n", intSize);

    printf("\nArray's content:%p\n", array);
    printf("\nAmount bits in array: %zu\n", sizeof array);
    printf("\nAmount bits in array: %zu\n", sizeof array[1]);
    printf("\nAddress in array: %p\n", &array[2]);
    printf("\nAddress in array: %p\n", &array[3]);

    return 0;
}
