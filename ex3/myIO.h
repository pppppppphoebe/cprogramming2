#ifndef MYIO_H
#define MYIO_H
#define _print(x)  printf(#x": "); _print_relation();
void _build_map();                              //deal with input: person1 number_of_friend friend1, friend2...
void _check_argument(int argc, char **argv);    //check whether the arguments are correct.
void _print_relation();                         //print the path from person1 to person2
void _err_message(int condition);               //print error message
#endif