#ifndef LRU_H
#define LRU_H

#include "common.h"

class LRU;


class LRUNode {
    private:
    LRUNode *prev;
    LRUNode *next;
    addr_t key;
    CacheLine value;

    friend class LRU;
    friend class LRUNode;

    public:
    LRUNode();
    ~LRUNode();
};


class LRU {
    private:
    LRUNode *front_ptr;
    LRUNode *back_ptr;

    size_t size;

    public:

    LRU();
    ~LRU();

    void push(addr_t key, CacheLine value);
    addr_t front_key() const {return front_ptr->key;}
    CacheLine front_value() const {return front_ptr->value;}
    void pop();
    CacheLine at(addr_t key);
    void at(addr_t key, CacheLine value);
    bool available(addr_t key);

    size_t get_size() const {return size;}
    bool empty() const {return size == 0;}
};

#endif
