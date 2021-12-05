/**
 * @file: inheritance1.hh
 * @author: Sang Jae Park <mainpower4309@gmail.com>
 * 
 */
#ifndef __INHERITANCE1_HH__
#define __INHERITANCE1_HH__

#include <stdio.h>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>

void test1();

//-------------------------------------------------------------------------------
class GraphVec{
public:
    GraphVec(int _N) : N(_N), graph(new std::vector<int>[_N+1]){}

public:
    // Member Functions
    void addEdge(int _node, int* _edges, int _length);

//TODO: select public/private/protected
    int N;
    std::vector<int>* graph;
};


//-------------------------------------------------------------------------------
class SearchGraph : public GraphVec{

public:
    SearchGraph(int _N) : GraphVec(_N){}
    
public:
    void runBFS(int _start);
    void runDFS(int _start);
    
};

#endif
