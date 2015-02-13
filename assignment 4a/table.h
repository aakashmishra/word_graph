//
//  table.h
//  assignment 4a
//
//  Created by Aakash Anand Mishra on 12/2/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#ifndef assignment_4a_table_h
#define assignment_4a_table_h

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string>
#include "structure.h"
#include "queue.h"
using namespace std;

// this structure of the array is defined
struct prev_condition{
    string prev;
    bool condition;
    string name;
};

class table{
public:
    prev_condition table_array[1000];
    
    // the contents of the table are initialized
    table(){
        for (int i = 0; i<1000; i++) {
            table_array[i].condition = false;
            table_array[i].prev = "none";
            table_array[i].name = "none";
        }
    }
    // this function adds the input string to the table
    void add(string input){
        int i = 0;
        if (table_array[0].name == "none") {
            table_array[0].name = input;
        }
        do{
            
        }while (table_array[i].name != "none");
    }
    
    // returns the position of the entry in the table
    int lookup(string input, int k){
        int i = 0;
        for (int j = 0; j<k; j++) {
            if(table_array[j].name == input){
                i = j;
            }
        }
        return i;
    }
    
    // prints the table not necessary but used for checking purposes
    void print_Table(int i){
        for(int j = 0; j<i; j++){
            cout<<table_array[j].name<<" "<<table_array[j].condition<<" "<<table_array[j].prev<<endl;

        }
    }
    // deletes all the entries in the table 
    void del_table(int i){
        for(int j = 0; j<i; j++){
            table_array[j].condition = false;
            table_array[j].prev = "none" ;
            
        }
    }
    
};

#endif
