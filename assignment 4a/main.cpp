//
//  main.cpp
//  assignment 4a
//
//  Created by Aakash Anand Mishra on 11/28/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string>
#include "structure.h"
#include "table.h"
#include "queue.h"
using namespace std;
/* This funcion is used to convert the input "enter" or "exit" to uppercase*/
void stringtoupper(string &s){
    for(unsigned int l =0; l<s.length();l++){
        s[l] = toupper(s[l]);
        
    }
}



int main(int argc, const char * argv[]) {
    unsigned int inlen = 0; //to check the length of the words in the list
    graph Check; // graph is defined
    string input;   // to get the input in the line for the list
    ifstream commandfile;  // this is used to access the input wordlist
    commandfile.open("/Users/aakashanandmishra/Desktop/assignment 4a/assignment 4a/Program4AlternativeFall2014words"); // takes wordlist and streams it in input
    int i = 0;
    /* takes the input and adds it to the graph*/
    while (getline(commandfile, input))
    {istringstream istr(input);
    
        Check.insert_into_graph_structure(input,i);
        i = i+ 1;
        inlen = int(input.length());
        
       }
    /* this is used in order to add the edges in the adjacency list
     the logic is as follows:
     1.checks all the vertices and then adds all the vertices to the adjacency list of the array elements
     2. the condition for adding is if
     */
    for (int j=0; j<i; j++) {
        for (int k =0; k<i; k++) {
            
        
        int l = Check.compare(j,k);
        if (l == (inlen - 1)) {
            graphnode* first = Check.create_new(Check.graph_structure[k].key);
            graphnode* start = &Check.graph_structure[j];
            graphnode* add = Check.move_to_last(start);
            add->next = first;
            }
        }
    }

/*prompts the user to either enter or exit the program*/
cout<<"Please type Enter to find paths and Exit to quit"<<endl;
    string in1;
    cin>>in1;
    stringtoupper(in1);
    /*if the user enters the program then:
     1.checks whether the user inputs words present in the wordlist
     2.if words are present it checks for the path distance 
     3.if path distance is less than the length of the word the path is printed 
     4.else it prints that the input string cannnot be converted to the destination
     5.it will ask the user recursively to enter the source and destination
     */
    while (in1 == "ENTER") {

   cout<<"Enter starting word "<<endl;
    string in;
    cin>>in;
    int c = Check.lookup(in);
    if (c != -1) {
    
    
   cout<<"Enter the destination "<<endl;
    string k;
    cin>>k;
        int c1 = Check.lookup(k);
        if (c1 != -1) {
            Check.short_path(k);
            int len = Check.path(in);
            if (len <= inlen ){
                cout<< "path exists and is as follows: "<<endl;
                Check.path_elements(in);
            }
            else{
                cout << "The starting string cannot be converted into the destination "<<endl;
            }
        }
    }
        Check.clear_table();
        cout<<"Please type Enter to find paths and Exit to quit "<<endl;
        cin>>in1;
       stringtoupper(in1);
        
        
        
    }
    
    
}
