#include "memory.h"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {

    using namespace std;
    string in_file;
    string out_file;
    unsigned max_size;
    string cmd_file;

    unsigned time = 0;

    if (argc != 5) {
        cout << "Argument Error!" << endl;
        return 1;
    } else {
        max_size = stoi(argv[1]);
        in_file = argv[2];
        out_file = argv[3];
        cmd_file = argv[4];
    }

    Cache cache(max_size);

    cache.load_mem_file(in_file);

    cout << "Current Time : " << time << endl; 

    ifstream cmd_in(cmd_file);

    while (true) {
        int cmd;
        cmd_in >> cmd;

        if (cmd_in.eof()) break;

        if (cmd == 0) {
            addr_t addr;
            CacheLine data;
            cmd_in >> addr;

            addr = addr - addr % CACHE_LINE_SIZE;

            data = cache.read(addr, time);

            cout << "Read " << addr << " Finish At Time " << time << " : ";
            for (size_t i=0; i<CACHE_LINE_SIZE; i++) cout << (unsigned) data.at(i) << " ";
            cout << "\n";

        } else if (cmd == 1) {
            addr_t addr;
            CacheLine data;

            cmd_in >> addr;

            addr = addr - addr % CACHE_LINE_SIZE;
            
            for (size_t i=0; i<CACHE_LINE_SIZE; i++) {
                unsigned byte;
                cmd_in >> byte;
                data.at(i, (uint8_t)byte);
            }

            cache.write(addr, data, time);

            cout << "Write " << addr << " Finish At Time " << time << endl;

        } else {
            cout << "Undefine Command Try Again" << endl;
        }

    }

    cache.store_mem_file(out_file);

    return 0;

}
