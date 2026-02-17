#include "queue.h"

// Create queue
Queue* queue_create(int capacity) {
    Queue* q = new Queue;
    q->buffer = new Event[capacity];
    q->capacity = capacity;
    q->head = q->tail = q->count = 0;
    return q;
}

// Free memory
void queue_destroy(Queue* q) {
    delete[] q->buffer;
    delete q;
}

// Check empty
bool queue_isEmpty(const Queue* q) {
    return q->count == 0;
}

// Check full
bool queue_isFull(const Queue* q) {
    return q->count == q->capacity;
}

// Add event
bool queue_enqueue(Queue* q, Event e) {
    if (queue_isFull(q)) return false;

    q->buffer[q->tail] = e;
    q->tail = (q->tail + 1) % q->capacity;
    q->count++;
    return true;
}

// Remove event
bool queue_dequeue(Queue* q, Event* out) {
    if (queue_isEmpty(q)) return false;

    *out = q->buffer[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->count--;
    return true;
}
