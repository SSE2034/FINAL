#include "inheritance1.hh"

//-------------------------------------------------------------------------------
void test1(){
    SearchGraph sg(9);

    int edge1[] = {2, 3, 4};
    int edge2[] = {1, 3, 8};
    int edge3[] = {1, 2, 4};
    int edge4[] = {1, 3, 5};
    int edge5[] = {4, 6, 7, 8};
    int edge6[] = {5, 7};
    int edge7[] = {5, 6};
    int edge8[] = {2, 5, 9};
    int edge9[] = {8};

    sg.addEdge(2, edge2, 3);
    sg.addEdge(1, edge1, 3);
    sg.addEdge(3, edge3, 3);
    sg.addEdge(4, edge4, 3);
    sg.addEdge(5, edge5, 4);
    sg.addEdge(6, edge6, 2);
    sg.addEdge(7, edge7, 2);
    sg.addEdge(8, edge8, 3);
    sg.addEdge(9, edge9, 1);

    printf("\n--------- BFS --------- \n");
    sg.runBFS(4);
    printf("\n--------- DFS --------- \n");
    sg.runDFS(4);
}


//-------------------------------------------------------------------------------
void GraphVec::addEdge(int _node, int* _edges, int _length){
    assert(_node !=0 && _node<=N);
    for(int i=0; i<_length; i++){
        graph[_node].push_back(_edges[i]);
    }
}


//-------------------------------------------------------------------------------
void SearchGraph::runDFS(int _start){

    //TODO: FILL YOUR CODE HERE
}


void SearchGraph::runBFS(int _start){

    //TODO: FILL YOUR CODE HERE
}

