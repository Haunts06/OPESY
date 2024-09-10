/*
CSOPESY S11 / S12
Group 1: Ching, Donato, Harder, Javier
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//COLORS FOR PRINTING
void black(){
    printf("\033[0;30m");
}
void red(){
    printf("\033[0;31m");
}
void green(){
    printf("\033[0;32m");
}
void yellow(){
    printf("\033[0;33m");
}
void blue(){
    printf("\033[0;34m");
}
void purple(){
    printf("\033[0;35m");
}
void cyan(){
    printf("\033[0;36m");
}
void white(){
    printf("\033[0;37m");
}

//ASCIIART
void asciiart(){
    printf("  _____  _____  ____  _____  ______  _______     __ \n");
    printf(" / ____|/ ____|/ __  |  __  |  ____|/ ____      / / \n");
    printf("| |    | (___ | |  | | |__) | |__  | (___     _/ /  \n");
    printf("| |      ___  | |  | |  ___/|  __|   ___        /   \n");
    printf("| |____ ____) | |__| | |    | |____ ____) |  | |    \n");
    printf("  _____|_____/  ____/|_|    |______|_____/   |_|    \n");
}

//HEADER PRINTING
void header(){
    green();
    printf("Hello, Welcome to CSOPESY commandline!\n");
    yellow();
    printf("Type 'exit' to quit, 'clear' to clear the screen\n");
}


int main(){
    asciiart();
    header();
    char response[20];
    return 0;
}