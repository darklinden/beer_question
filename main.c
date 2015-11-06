//
//  main.c
//
//  Created by darklinden on 6/11/2015.
//  Copyright © 2015 darklinden. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define get_beer( __beer__, __cash__, __cost__) \
{ \
__beer__ += (int)floorf(__cash__ / __cost__); \
__cash__ = __cash__ % __cost__; \
}

#define drink_beer(__beer__, __bottle__, __cap__, __drunk__) \
{ \
__bottle__ += __beer__; \
__cap__ += __beer__; \
__drunk__ += __beer__; \
__beer__ = 0; \
}

#define do_log() \
{ \
printf("\n***************************\n"); \
printf(" money:   %d\n", money); \
printf(" beer:    %d\n", beer); \
printf(" bottle:  %d\n", bottle); \
printf(" cap:     %d\n", cap); \
printf(" drunk:   %d\n", drunk); \
printf("***************************\n"); \
}

int main() { //int argc, const char * argv[]
    
    int money               = 10;
    int beer                = 0;
    int bottle              = 0;
    int cap                 = 0;
    
    int beer_cost_money     = 2;
    int beer_cost_bottle    = 2;
    int beer_cost_cap       = 4;

    int drunk = 0;
    
    do {
        drink_beer(beer, bottle, cap, drunk);
        
        get_beer(beer, money, beer_cost_money);
        get_beer(beer, bottle, beer_cost_bottle);
        get_beer(beer, cap, beer_cost_cap);
        
        do_log();
        
    } while (beer > 0);
    
    printf("\n************* ah at last *************\n");
    
    do_log();
    
    return 0;
}
