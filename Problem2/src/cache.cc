#include "memory.h"

CacheLine Cache::read(addr_t read_addr, unsigned &time) {
    bool is_hit = cache_array->available(read_addr);

    if (is_hit) time += HIT_LATENCY;
    else time += MISS_LATENCY;

    if (is_hit) {
        return cache_array->at(read_addr);
    } else if (capacity > cache_array->get_size()) {
        CacheLine fill_data = m_mem.read(read_addr);

        cache_array->push(read_addr, fill_data);
        return fill_data;
    } else {
        addr_t evict_addr;
        CacheLine evict_data;

        evict_addr = cache_array->front_key();
        evict_data = cache_array->front_value();
        m_mem.write(evict_addr, evict_data);
        cache_array->pop();

        CacheLine fill_data = m_mem.read(read_addr);
        cache_array->push(read_addr, fill_data);

        return fill_data;
    }
}

void Cache::write(addr_t write_addr, CacheLine write_data, unsigned &time) {

    //TODO: Problem 2-3
}

void Cache::load_mem_file(std::string file_name) {m_mem.load(file_name);}

void Cache::store_mem_file(std::string file_name) {m_mem.store(file_name);}
