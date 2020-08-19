//
// Created by Nan Ni on 2020-08-19.
//

#ifndef DP_GRAPH_NODE_H
#define DP_GRAPH_NODE_H
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Node {

private:
    T val;
    vector<Node*> edges;

public:

    Node(){
        val = 0;
        edges = {};
    }

    Node(T value){
        val = value;
    }

    Node(T value,vector<Node<T>*> egs){
        val = value;
        edges = egs;
    }

    void set_val(T value){
        val = value;
    }

    T get_val(){
        return val;
    }

    void set_edges(vector<Node<T>*> egs){
        edges = egs;
    }

    vector<Node*> get_edges(){
        return edges;
    }

    ~Node(){

    }

};


#endif //DP_GRAPH_NODE_H
