#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    /* COMPLETARDO */
    struct s_node *head;
    priority_t max_priority;
    size_t size;

};

struct s_node {
    /* COMPLETARDO */
    pstack_elem elem;
    priority_t priority;
    struct s_node *next;
};

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    /* COMPLETARDO */
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    return NULL;
}


static bool invrep(pstack s) {
    if (s == NULL) return false;
    struct s_node *current = s->head;
    while (current != NULL && current->next != NULL) {
        if (current->priority < current->next->priority) {
            return false;
        }
        current = current->next;
    }
    return true;
}

pstack pstack_empty(priority_t max_priority) {
    /* COMPLETARDO */
    pstack s = malloc(sizeof(struct s_pstack));
    assert(s != NULL);
    s->head = NULL;
    s->max_priority = max_priority;
    s->size = 0;
    assert(invrep(s) && pstack_is_empty(s));
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    /* COMPLETARDO */
    assert(priority <= s->max_priority);

    struct s_node *new_node = create_node(e, priority);
    if (s->head == NULL || s->head->priority < priority) {
        new_node->next = s->head;
        s->head = new_node;
    } else {
        struct s_node *current = s->head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    s->size++;    
    assert(invrep(s) && !pstack_is_empty(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    assert(invrep(s));
    /* COMPLETARDO */
    return s->size == 0u;
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETARDO */
    return s->head->elem;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETARDO */
    return s->head->priority;
}

size_t pstack_size(pstack s) {
    assert(invrep(s));
    /* COMPLETARDO */
    return s->size;
}

pstack pstack_pop(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    /* COMPLETARDO */
    struct s_node *temp = s->head;
    s->head = s->head->next;
    temp = destroy_node(temp);
    s->size--;
    assert(invrep(s));
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    /* COMPLETARDO */
    while (s->head != NULL) {
        s = pstack_pop(s);
    }
    free(s);
    return s;
}

