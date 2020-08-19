//
// Created by Nan Ni on 2020-08-19.
//

#ifndef DP_GRAPH_GRAPH_H
#define DP_GRAPH_GRAPH_H
#include "Node.h"
#include <queue>
#include <unordered_set>
#include <string>
#include <unordered_map>
template<class T>
class Graph{
private:
    Node<T>* head;

public:
    Graph();

    Graph(Node<T>* hd);

    Graph(T val);

    Node<T>* get_head();

    void insert_node(T val1,T val2);

    Node<T>* find(T val);

    void print_Graph();

    ~Graph();

};

template<class T>
Graph<T>::Graph(){

}


template<class T>
Graph<T>::Graph(T val) {
    Node<T>* new_node = new Node<T>(val);
    head = new_node;
}

//creates a deep copy
template<class T>
Graph<T>::Graph(Node<T>* hd){
    unordered_map<Node<T>*,Node<T>*> look_up;
    queue<Node<T>*> all_nodes;
    unordered_set<Node<T>*> visited;
    all_nodes.push(hd);
    visited.insert(hd);
    //BFS traverse
    while(!all_nodes.empty()){
        Node<T> * current = all_nodes.front();
        all_nodes.pop();
        vector<Node<T>*> egs = current->get_edges();
        for(typename vector<Node<T>*>::iterator itr = egs.begin(); itr != egs.end();itr++){
            //T val = (*itr)->get_val();
            if(visited.find(*itr) == visited.end()){
                all_nodes.push(*itr);
                visited.insert(*itr);
            }
        }

        Node<T>* new_node = new Node<T>(current->get_val());
        look_up.insert(pair<Node<T>*,Node<T>*>(current,new_node));
        if(head == nullptr){
            head = new_node;
        }
    }

    //after all nodes have been allocated
    //set up edges and relation
    for(typename unordered_map<Node<T>*,Node<T>*>::iterator itr = look_up.begin();itr != look_up.end();itr++){
        Node<T>* cur_ptr = itr->second;
        vector<Node<T>*> cur_edge;
        vector<Node<T>*> egs = itr->first->get_edges();
        for(typename vector<Node<T>*>::iterator it = egs.begin();it != egs.end();it ++){
            Node<T>* edge_ptr = look_up.find(*it)->second;
            cur_edge.push_back(edge_ptr);
        }
        cur_ptr->set_edges(cur_edge);
    }

}


template<class T>
Node<T> *Graph<T>::get_head() {
    return head;
}


//if both val found within graph,create an edge for them
//if one found, insert a node and create an edge
//if neither found, insertion failed
template<class T>
void Graph<T>::insert_node(T val1, T val2) {
    //search for val1
    Node<T>* ptr1 = this->find(val1);
    Node<T>* ptr2 = this->find(val2);
    if(ptr1== nullptr && ptr2 == nullptr){
        cout << "insertion failed" << endl;
        return;
    }
    else if(ptr1 == nullptr){
        vector<Node<T>*> egs;
        egs.push_back(ptr2);
        Node<T>* new_node = new Node<T>(val1,egs);
        //add edge
        vector<Node<T>*> temp = ptr2->get_edges();
        temp.push_back(new_node);
        ptr2->set_edges(temp);
    }
    else if(ptr2 == nullptr){
        vector<Node<T>*> egs;
        egs.push_back(ptr1);
        Node<T>* new_node = new Node<T>(val2,egs);
        //add edge
        vector<Node<T>*> temp = ptr1->get_edges();
        temp.push_back(new_node);
        ptr1->set_edges(temp);
    }
    else{
        vector<Node<T>*> egs1 = ptr1->get_edges();
        egs1.push_back(ptr2);
        ptr1->set_edges(egs1);
        vector<Node<T>*> egs2 = ptr2->get_edges();
        egs2.push_back(ptr1);
        ptr2->set_edges(egs2);
    }
}


template<class T>
Node<T> *Graph<T>::find(T val) {
    queue<Node<T>*> myQ;
    unordered_set<Node<T>*> visited;
    myQ.push(head);
    visited.insert(head);
    while(!myQ.empty()){
        Node<T>* current = myQ.front();
        myQ.pop();
        if(current->get_val() == val){
            return current;
        }
        vector<Node<T>*> egs = current->get_edges();
        for(typename vector<Node<T>*>::iterator itr = egs.begin();itr != egs.end();itr++){
            if(visited.find(*itr) == visited.end()){
                myQ.push(*itr);
                visited.insert(*itr);
            }
        }
    }

    return nullptr;
}



template<class T>
void Graph<T>::print_Graph() {
    //node:   ,edge:()
    queue<Node<T>*> myQ;
    unordered_set<Node<T>*> visited;
    myQ.push(head);
    visited.insert(head);
    while(!myQ.empty()){
        Node<T>* current = myQ.front();
        myQ.pop();

        vector<Node<T>*> egs = current->get_edges();
        for(typename vector<Node<T>*>::iterator itr = egs.begin();itr != egs.end();itr++){
            if(visited.find(*itr) == visited.end()){
                myQ.push(*itr);
                visited.insert(*itr);
            }
        }
    }

    //all nodes are kept in visited
    for(typename unordered_set<Node<T>*>::iterator itr = visited.begin();itr!=visited.end();itr++){
        vector<Node<T>*> egs = (*itr)->get_edges();
        cout << "Node";
        cout << ": ";
        cout << (*itr)->get_val();
        cout << ". Edges: ";
        for(typename vector<Node<T>*>::iterator it = egs.begin(); it != egs.end();it++){
            cout << (*it)->get_val();
            cout << " ,";
        }
        cout << endl;
    }

}


template<class T>
Graph<T>::~Graph(){
    
}



#endif //DP_GRAPH_GRAPH_H
