//
//  structure.h
//  assignment 4a
//
//  Created by Aakash Anand Mishra on 11/28/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#ifndef assignment_4a_structure_h
#define assignment_4a_structure_h

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string>
#include "queue.h"
#include "table.h"

using namespace std;
// structure of the graphnode is used having a string and a pointer
struct graphnode{
    string key;
    graphnode *next;
};
class graph{
public:
    Queue<string> H; // a queue is defined in the class
    table  t;  // the table to store the path is defined
    int elements; // counts the total no of elements
    graphnode* root; //the root is defined
    graphnode graph_structure[1000]; // the array to store the initial words
    // the graph constructor initialises all the elements as null
    graph(){
        for (int  j= 0; j<1000; j++) {
            graph_structure[j].next = NULL;
        }
    }
    // this function is used to create a new graphnode
    graphnode* create_new(string key_in){
        graphnode* obj = new graphnode;
        obj->key = key_in;
        obj->next = NULL;
        return obj;
    }
    /*
     this function does the following:
     1.inserts the elements into the array
     2.updates the elements
     3.adds that element to the table as well
     */
    void insert_into_graph_structure(string key_in,int i){
        graphnode* root_in = create_new(key_in);
        graph_structure[i].key = root_in->key;
        graph_structure[i].next = root_in->next;
        elements =elements + 1;
        t.table_array[i].name = key_in;
        t.table_array[i].prev = "none";
        t.table_array[i].condition = false;
    
    }
    /*
     compares the two strings in the array places and returns the no of matching characters
     */
    int compare(int i,int j){
        string comp = graph_structure[i].key;
        int comp_value = 0;
            if (j!= i) {
                for (int k =0; k<comp.length(); k++) {
                    if(comp[k] == graph_structure[j].key[k]){
                        comp_value = comp_value + 1;
                    }
                }
          
        }
        return comp_value;
        
    }
    
   /*this function was used during the building time to see the last node in the list of a particular array element*/
    graphnode* move_to_last(graphnode* move){
        if (move->next == NULL) {
            return move;
        }
        else{
            move = move_to_last(move->next);
            
        }
    return move;
    }
    /*this function will search whether the string is present within the array or not and returns the position in the table
     */
    int lookup(string input){
        int i = -1;
        for (int j =0 ; j<elements; j++) {
            if (graph_structure[j].key == input) {
                i = j;
            }
                    }
        if (i == -1) {
            cout<<"invalid input"<<endl;
        }
        return i;
    }
    /*
     this function finds the short path from the source and updates the table accordingly
     */
    int short_path(string source){
        graphnode* iter;
        int k = lookup(source);
        H.push(graph_structure[k].key);
        t.table_array[k].condition = true;
            while (!H.IsEmpty()) {
                string popstring = H.pop();
                int no = lookup(popstring);
                iter = &graph_structure[no];
                        while(iter->next != NULL){
                            string check= iter->next->key;
                            int checkno = t.lookup(check,elements);
                            if (t.table_array[checkno].condition == false) {
                                t.table_array[checkno].prev = popstring;
                                t.table_array[checkno].condition = true;
                                H.push(check);
                            }
                            iter = iter->next;
                        }
                    }
        return 0;
        
    }
    /* this function returns the path length between the source and destination
     */
    int path(string input){
        int k = 0;
        int i;
        string k1;
        i = t.lookup(input,elements);
        while (t.table_array[i].prev != "none") {
            k1 = t.table_array[i].prev;
            i = t.lookup(k1,elements);
            k = k + 1;
        }
        return k;
    }
    /* this function prints the path between the source and destination
     */

    int path_elements(string input){
        int k = 0;
        int i;
        string k1;
        i = t.lookup(input,elements);
        cout<<input<<endl;
        while (t.table_array[i].prev != "none") {
            k1 = t.table_array[i].prev;
            i = t.lookup(k1,elements);
            cout<<k1<<endl;
        }
        return k;
    }
    
    // this function clears the table
    void clear_table(){
        t.del_table(elements);
    }
};





#endif
