#ifndef QUEUE_H
#define QUEUE_H

#include "event.h"

// Circular queue
struct Queue {
    Event* buffer;
    int capacity;
    int head;
    int tail;
    int count;
};

Queue* queue_create(int capacity);
void queue_destroy(Queue* q);
bool queue_isEmpty(const Queue* q);
bool queue_isFull(const Queue* q);
bool queue_enqueue(Queue* q, Event e);
bool queue_dequeue(Queue* q, Event* out);

#endif
