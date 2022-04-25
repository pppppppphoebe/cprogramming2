#ifndef MYALGO_H
#define MYALGO_H
#include "basic.h"
#define MAX_algorithm 2
extern int relation_map[MAX_person][MAX_person];
extern char algo_name[MAX_algorithm][10];
void _map_init();
void algo_init();
BOOL _DFS(int now_person, int to_find);
BOOL _BFS(int ini_person, int to_find);
#endif