/*
*   Author:     Brindle, Hamish | Set 2E
*   Course:     COMP 2510
*   Date:       March 29, 2017
*   Title:      a3record.c
*   Purpose:    Read in records and store in Dynamically allocated memory.
*               Record inputs are subject to validation.
*/

#include <ctype.h>
#include <string.h>
#include "a3header.h"

#ifndef LINESIZE
#define LINESIZE 256
#define NUM_REC precord->nused
#define NUM_ALLOC precord->nalloc
#define REC_LIST precord->data
#define REC_LIST_I(x) precord->data[x]
#endif

void fix_name(char name[]);

void print(record_list *precord);

int validate_record(const char id[], const char fname[], const char lname[], const char score[]);

int read_record(record_list *precord) {
        char line[LINESIZE];
        char id[IDSIZE];
        char fname[NAMESIZE];
        char lname[NAMESIZE];
        char sscore[3];
        int score;
        int mem_block;
        size_t i;

        /* Initialize record list */
        precord->data = 0;
        precord->nalloc = 0;
        precord->nused = 0;
        mem_block = 1;
        #ifdef DEBUG
                fprintf(stderr, "%s", "#");
        #endif

        while(fgets(line, LINESIZE, stdin)) {
                /* If list is full, make room; increase by mem_block (x2) */
                if (NUM_REC == NUM_ALLOC) {
                        record **temp = realloc(REC_LIST, (NUM_ALLOC + mem_block) * sizeof(record*));
                        REC_LIST = temp;
                        NUM_ALLOC += mem_block;
                        mem_block *= 2;
                #ifdef DEBUG
                        fprintf(stderr, "%s", "#");
                #endif
                }

                /* In our list of pointers, the next available spot is selected, then in that spot in memory,
                   we allocate enough space for another record */
                REC_LIST_I(NUM_REC) = malloc(sizeof(record));

                /* Read in List of records */
                if (sscanf(line, "%s %s %s %s", id, fname, lname, sscore) == 4 && validate_record(id, fname, lname, sscore)) {

                        for (i = 0; id[i] != '\0'; i++)
                                REC_LIST_I(NUM_REC)->id[i] = id[i];
                        REC_LIST_I(NUM_REC)->id[i] = '\0';

                        fix_name(fname);
                        for (i = 0; fname[i]; i++) {
                                REC_LIST_I(NUM_REC)->name.first[i] = fname[i];
                        }
                        REC_LIST_I(NUM_REC)->name.first[i] = '\0';

                        fix_name(lname);
                        for (i = 0; lname[i]; i++) {
                                REC_LIST_I(NUM_REC)->name.last[i] = lname[i];
                        }
                        REC_LIST_I(NUM_REC)->name.last[i] = '\0';

                        if (sscanf(sscore, "%d", &score) == 1) {
                                REC_LIST_I(NUM_REC)->score = score;
                                NUM_REC += 1;
                        }
                }
        }
        return 1;
}

/* Changes any upper-case letters in the name to lowercase */
void fix_name(char name[]) {
        size_t i;
        char temp[NAMESIZE];

        for (i = 0; name[i] != '\0'; i++) {
                /* Assigning first name after turned lowercase */
                temp[i] = tolower(name[i]);
        }
        temp[i] = '\0';

        for (i = 0; i < strlen(temp); i++) {
                name[i] = temp[i];
        }
}

/* Confirms proper input; follows requirements of the record */
int validate_record(const char id[], const char fname[], const char lname[], const char sscore[]) {
        size_t i;
        size_t id_num_count;
        int score;

        id_num_count = 0;

        /* Id */
        if (id[0] != 'a' || strlen(id) < 9)
                return 0;
        for (i = 1; i < strlen(id) - 1; i++)
                if (!isdigit(id[i]) || ++id_num_count > 8)
                        return 0;

        /* Name */
        if (strlen(fname) > NAMESIZE || strlen(fname) == 0)
                return 0;
        if (strlen(lname) > NAMESIZE || strlen(lname) == 0)
                return 0;

        /* Score */
        for (i = 0; i < strlen(sscore); i++) {
                if (!isdigit(sscore[i]))
                        return 0;
        }
        sscanf(sscore, "%d", &score);
        if (score > 100 || score < 0)
                return 0;

        return 1;
}

/* Displays list of records */
void print(record_list *precord) {
        size_t i;

        for (i = 0; i < NUM_REC; i++) {
                fprintf(stdout, "%s : %s, %s : %d\n",
                    REC_LIST_I(i)->id,
                    REC_LIST_I(i)->name.last,
                    REC_LIST_I(i)->name.first,
                    REC_LIST_I(i)->score);
        }
}
