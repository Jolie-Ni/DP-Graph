#include <iostream>
#include "Node.h"
#include "Graph.h"
int main() {
    Graph<int> T1(10);
    T1.insert_node(10,5);
    T1.insert_node(10,7);
    T1.insert_node(5,7);
    T1.insert_node(8,7);
    T1.insert_node(8,10);
    T1.print_Graph();
    Graph<int> T2(T1.get_head());
    cout << "======================" << endl;
    //cout << "second graph" << endl;

    T2.print_Graph();


    return 0;
}
