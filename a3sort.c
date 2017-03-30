/*
*   Author:     Brindle, Hamish | Set 2E
*   Course:     COMP 2510
*   Date:       March 29, 2017
*   Title:      a3sort.c
*   Purpose:    The comparison and sorting functions used while ordering the
*               student record list.
*/

#include <string.h>
#include "a3header.h"

/* Parameterized records (*r1, *r2) def for use in comparison functions */
#define R1 (*(const record **)r1)
#define R2 (*(const record **)r2)

int cmp_id(const void *r1, const void *r2) {
        return strcmp(R1->id, R2->id);
}

int cmp_last(const void *r1, const void *r2) {
        return strcmp(R1->name.last, R2->name.last);
}

int cmp_first(const void *r1, const void *r2) {
        return strcmp(R1->name.first, R2->name.first);
}

/* Ascending name order */
int cmp_namep(const void *r1, const void *r2) {
        if (cmp_last(r1, r2) == 0) {
                return cmp_first(r1, r2);
        } else {
                return cmp_last(r1, r2);
        }
}

/* Descending name order */
int cmp_namem(const void *r1, const void *r2) {
        if (cmp_last(r2, r1) == 0) {
                return cmp_first(r2, r1);
        } else {
                return cmp_last(r2, r1);
        }
}

/* Ascending order of score */
int cmp_scorep(const void *r1, const void *r2) {
        if (R1->score > R2->score)
                return 1;
        else if (R1->score < R2->score)
                return -1;
        else
                return 0;
}

/* Descending order of score */
int cmp_scorem(const void *r1, const void *r2) {
        if (R1->score > R2->score)
                return -1;
        else if (R1->score < R2->score)
                return 1;
        else
                return 0;
}

/* Order descending score / descending name */
int cmp_sm_nm(const void *r1, const void *r2) {
        if (cmp_scorem(r1, r2) == 0)
                return cmp_namem(r1, r2);
        else
                return cmp_scorem(r1, r2);
}

/* Order ascending score / ascending name */
int cmp_sp_np(const void *r1, const void *r2) {
        if (cmp_scorep(r1, r2) == 0)
                return cmp_namep(r1, r2);
        else
                return cmp_scorep(r1, r2);
}

/* Order descending name / descending score */
int cmp_nm_sm(const void *r1, const void *r2) {
        if (cmp_namem(r1, r2) == 0)
                return cmp_scorem(r1, r2);
        else
                return cmp_namem(r1, r2);
}

/* Order ascending name / ascending score */
int cmp_np_sp(const void *r1, const void *r2) {
        if (cmp_namep(r1, r2) == 0)
                return cmp_scorep(r1, r2);
        else
                return cmp_namep(r1, r2);
}

/* Order ascending name / descending score */
int cmp_np_sm(const void *r1, const void *r2) {
        if (cmp_namep(r1, r2) == 0)
                return cmp_scorem(r1, r2);
        else
                return cmp_namep(r1, r2);
}

/* Order ascending score / descending name */
int cmp_sp_nm(const void *r1, const void *r2) {
        if (cmp_scorep(r1, r2) == 0)
                return cmp_namem(r1, r2);
        else
                return cmp_scorep(r1, r2);
}

/* Order descending score / ascending name */
int cmp_sm_np(const void *r1, const void *r2) {
        if (cmp_scorem(r1, r2) == 0)
                return cmp_namep(r1, r2);
        else
                return cmp_scorem(r1, r2);
}

/* Order descending name / ascending score */
int cmp_nm_sp(const void *r1, const void *r2) {
        if (cmp_namem(r1, r2) == 0)
                return cmp_scorep(r1, r2);
        else
                return cmp_namem(r1, r2);
}

void sort(const int argc, char * argv[], record_list *precord) {
        size_t arg_len;

        if (argc == 1) {
                /* Sort by student ID */
                qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_id);
        } else if (argc == 2) {
                arg_len = strlen(argv[1]);
                if (strcmp(argv[1], "s+n-") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_sp_nm);
                } else if (strcmp(argv[1], "s-n+") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_sm_np);
                } else if (strcmp(argv[1], "n+s-") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_np_sm);
                } else if (strcmp(argv[1], "n-s+") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_nm_sp);
                } else if (strcmp(argv[1], "n+s+") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_np_sp);
                } else if (strcmp(argv[1], "n-s-") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_nm_sm);
                } else if (strcmp(argv[1], "s+n+") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_sp_np);
                } else if (strcmp(argv[1], "s-n-") == 0 && arg_len == 4) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_sm_nm);
                } else if (strcmp(argv[1], "n+") == 0 && arg_len == 2) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_np_sp);
                } else if (strcmp(argv[1], "n-") == 0 && arg_len == 2) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_nm_sm);
                } else if (strcmp(argv[1], "s+") == 0 && arg_len == 2) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_sp_np);
                } else if (strcmp(argv[1], "s-") == 0 && arg_len == 2) {
                        qsort(REC_LIST, NUM_REC, sizeof(REC_LIST_I(0)), cmp_sm_nm);
                } else {
                        fprintf(stderr, "%s\n", "Unable to recognize flag.");
                        exit(0);
                }
        }
}
