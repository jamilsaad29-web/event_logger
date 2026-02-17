#include "sort.h"
#include <cstring>

// Insertion sort by timestamp
void insertion_sort(EventLog* log) {
    int n = log_size(log);

    for (int i = 1; i < n; i++) {
        Event key = log_get(log, i);
        int j = i - 1;

        while (j >= 0 && log_get(log, j).timestamp > key.timestamp) {
            log_set(log, j + 1, log_get(log, j));
            j--;
        }

        log_set(log, j + 1, key);
    }
}

// Return sorting function
SortFn get_sort(const char* name) {
    if (strcmp(name, "insertion") == 0)
        return insertion_sort;

    return NULL;
}
