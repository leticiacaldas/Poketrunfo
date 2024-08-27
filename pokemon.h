#ifndef POKEMON_H
#define POKEMON_H

typedef struct Pokemon
{
    char name[30];
    char type1[20];
    char type2[20];
    int hp;
    int attack;
    int defense;
    int sp_atk;
    int sp_def;
    int legendary;
    struct Pokemon *prev;
    struct Pokemon *next;
} Pokemon;

#endif // POKEMON_H