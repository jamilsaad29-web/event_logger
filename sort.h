#ifndef SORT_H
#define SORT_H

#include "event_log.h"

// Sorting function pointer
typedef void (*SortFn)(EventLog* log);

void insertion_sort(EventLog* log);
SortFn get_sort(const char* name);

#endif

