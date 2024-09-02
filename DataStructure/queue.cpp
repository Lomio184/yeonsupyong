#include <stdio.h>

class Queue
{
private:
    int *queue ;
    int front ;
    int rear; 
    int maxSize ;
    int count ;

public:
    Queue( int size ):
        front(0),
        rear(0),
        maxSize( size ),
        count(0)
    {
        queue = new int[maxSize];
        return ;
    }

    ~Queue() 
    {
        delete[] queue ;
    }

    bool IsEmpty() const
    {
        return count == 0 ;
    }

    bool IsFull() const
    {
        return count == maxSize ;
    }

    bool Enqueue( int value )
    {
        if ( IsFull() == true )
        {
            return false ;
        }

        queue[rear] = value ;
        rear = (rear + 1) % maxSize ;
        count++;
        return true ;
    }

    bool Dequeue( int& value )
    {
        if ( IsEmpty() == true )
        {
            return false ;
        }

        value = queue[front];
        front = (front+1)%maxSize;
        printf("Front : %d\n", front);
        count--;

        return true ;
    }

    void FullRecovery()
    {
        for ( int i = 0 ; i < maxSize ; ++i )
        {
            printf("%d\t", queue[i]);
        }
    }

    int Size() const 
    {
        return count ;
    }
};

int main() {
    Queue cq(6);

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50);

    int value;
    cq.Dequeue(value);
    printf("Dequeue Value : %d\n", value );

    cq.Dequeue(value);
    printf("Dequeue Value : %d\n", value );

    cq.FullRecovery();
    return 0;
}