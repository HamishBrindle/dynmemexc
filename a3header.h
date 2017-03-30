/*
*   Author:     Brindle, Hamish | Set 2E
*   Course:     COMP 2510
*   Date:       March 29, 2017
*   Title:      a3header.h
*   Purpose:    A3 header file containing definitions and structs.
*/

#ifndef A3_H
#define A3_H

#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 20
#define IDSIZE 10
#define LINESIZE 256
#define MEM_BLK 2
#define NUM_REC precord -> nused
#define NUM_ALLOC precord -> nalloc
#define REC_LIST precord -> data
#define REC_LIST_I(x) precord -> data[x]

typedef struct {
    char last[NAMESIZE];  /* last name (1 word), e.g., homer */
    char first[NAMESIZE]; /* first name (1 word), e.g., simpson */
} name;

typedef struct {
    name name;
    char id[IDSIZE];    /* stdID */
    int score;          /* between 0 & 100 inclusive, e.g., 25 */
} record;

typedef struct {
    record **data;  /* pointers to dynamic array of pointers */
    size_t nalloc;  /* number of pointers allocated */
    size_t nused;   /* number of pointers used */
} record_list;

void input_record(record_list *precord);

#endif
