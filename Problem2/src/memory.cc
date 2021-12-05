#include "memory.h"
#include <fstream>
#include <iostream>


void Memory::load(std::string file_name) {
    std::ifstream fin(file_name);

    while (true) {
       addr_t addr;
       CacheLine data;

       fin >> addr;
       if (fin.eof()) break;

       for (size_t i=0; i<CACHE_LINE_SIZE; i++) {
           unsigned byte;
           fin >> byte;
           data.at(i, (uint8_t)byte);
       }

       memory_space[addr] = data;
    }

    fin.close();
}

void Memory::store(std::string file_name) {
    //TODO: Problem 2-5
}

CacheLine Memory::read(addr_t read_addr) {

    if (memory_space.find(read_addr) != memory_space.end()) {
        return memory_space[read_addr];
    } else {
        CacheLine new_line;
        memory_space[read_addr] = new_line;
        return new_line;
    }
}

void Memory::write(addr_t write_addr, CacheLine write_data) {memory_space[write_addr] = write_data;}
