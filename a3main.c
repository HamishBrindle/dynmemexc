/*
*   Author:     Brindle, Hamish | Set 2E
*   Course:     COMP 2510
*   Date:       March 29, 2017
*   Title:      a3main.c
*   Purpose:    Dynamically allocate memory for input of student records as well
*               as sorting by ID, name, and score (sort order indicated with used
*               of "n+", "s+", "n-", and "s-" flags).
*/

#include "a3sort.c"
#include "a3record.c"

int main(int argc, char *argv[]) {
    record_list records;
    if (argc > 2) {
        return 0;
    }
    read_record(&records);
    sort(argc, argv, &records);
    print(&records);

    return 0;
}
