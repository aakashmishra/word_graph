//
//  queue.h
//  assignment 4a
//
//  Created by Aakash Anand Mishra on 12/2/14.
//  Copyright (c) 2014 Aakash Anand Mishra. All rights reserved.
//

#ifndef __assignment_4a__queue__
#define __assignment_4a__queue__

#include <stdio.h>
#include <iostream>

using namespace std;

//defining the path


template< class que > class Queue

{
    
private:
    
    int length;
    
    que *in_array;
    
    int front;
    
    int rear;
    
    
    
public:

    
    Queue(int x=1000): length(x), in_array(new que[length]) // queue constructor
    
    { front = 0;                    // initial values of rear and front are 0 and the queue is made of the length
        rear = 0;
    }
;//default constructor //maximum size of the array that will store Queue
    
    ~Queue()//destructor
    
    {delete [] in_array;}
    
    bool IsFull()  // turns out to be 1 if queue is full
    
    {if((rear + 1) %  length == front )
        return 1;
    else
        return 0;
    }

    void push(que x) // pushes the element into the queue
    
    {
        if(!Queue<que>::IsFull())
        {in_array[rear] = x;
            rear = (rear + 1) % length;
        }
    }
    bool IsEmpty()
    
    {if( rear  == front ){
        return 1;
    }
    else{
        return 0;
    }
    }
    
    
    
  que pop()  // element is popped
    
    {que val;
        if(!Queue<que>::IsEmpty())
        {val = in_array[front];
            front = ( front + 1 ) % length;
        }
        else
        {cout << "Queue is Empty : "; // if queue is empty shows "Queue is Empty"
        }
        return val;
    }
    
    
    que first() const // returns the front object
    {
        return in_array[front];
        
    }
    

    
    que back() const  // returns the rear object
    
    {
        return in_array[rear];
        
    }
    

    
    int size() const
    
    {
        return ((rear-front +length)%length ); // returns the size of the queue
        
    }



    
};
#endif /* defined(__assignment_4a__queue__) */

