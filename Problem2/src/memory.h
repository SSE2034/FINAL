#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"
#include "lru.h"
#include <map>
#include <string>

class Memory {
    private:
    std::map<addr_t, CacheLine> memory_space;

    //TODO: Problem 2-1

    CacheLine read(addr_t read_addr);
    void write(addr_t write_addr, CacheLine write_data);
    void load(std::string file_name);
    void store(std::string fille_name);

    public:
    Memory(){};

};

//Fully Associative LRU Cache
class Cache {
    private:
    LRU *cache_array;
    Memory m_mem;
    size_t capacity;

    public:
    Cache(size_t max_size) {
        capacity = max_size;
        cache_array = new LRU;
    }
    ~Cache(){};

    CacheLine read(addr_t read_addr, unsigned &time);
    void write(addr_t write_addr, CacheLine write_data, unsigned &time);

    void load_mem_file(std::string file_name);
    void store_mem_file(std::string file_name);
};

#endif
