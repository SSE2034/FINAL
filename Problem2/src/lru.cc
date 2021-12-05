#include "lru.h"


LRUNode::LRUNode() {
    prev = NULL;
    next = NULL;
}


LRUNode::~LRUNode() {
    prev = NULL;
    next = NULL;
    return;
}


LRU::LRU() {
    front_ptr = NULL;
    back_ptr = NULL;
    size = 0;
}

LRU::~LRU() {
    LRUNode *cur = front_ptr;

    for (size_t i=0; i<size; size++) {
        LRUNode *next = cur->next;
        delete cur;
        cur = next;
    }
}


void LRU::push(addr_t key, CacheLine value) {

    LRUNode *new_node = new LRUNode;
    new_node->key = key;
    new_node->value = value;

    if (back_ptr != NULL) {
        new_node->prev = back_ptr;
        back_ptr->next = new_node;
        back_ptr = new_node;
    } else {
        new_node->prev = NULL;
        new_node->next = NULL;
        back_ptr = new_node;
        front_ptr = new_node;
    }

    size++;
}


void LRU::pop() {

    if (front_ptr == NULL) return;

    addr_t return_key = front_ptr->key;
    LRUNode *delete_node = front_ptr;
    front_ptr = front_ptr->next;

    delete delete_node;
    size--;
}


bool LRU::available(addr_t key) {
    LRUNode *current = front_ptr;

    for (size_t i=0; i<size; i++) {
        if (current->key == key) break;
        else current = current->next;
    }

    return current != NULL;
}


CacheLine LRU::at(addr_t key) {

    //TODO: Problem 2-4
}


void LRU::at(addr_t key, CacheLine value) {
    //TODO: Problem 2-4
}

