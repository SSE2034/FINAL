//TODO: Problem 2-2
//TODO: Problem 2-2

#include <vector>
#include <unistd.h>
#include <cstdint>

#define CACHE_LINE_SIZE 8
#define HIT_LATENCY 1
#define MISS_LATENCY 5

typedef class CACHELINE {
    private:
    std::vector <uint8_t> byte_array;

    public:
    CACHELINE() {byte_array.resize(CACHE_LINE_SIZE, 0);}
    
    uint8_t at(uint8_t idx) const {return byte_array.at(idx);}
    void at(uint8_t idx, uint8_t new_data) {byte_array.at(idx) = new_data;}
}CacheLine;

typedef unsigned addr_t;

//TODO: Problem 2-2
