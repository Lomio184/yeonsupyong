#include <stdio.h>

typedef struct Node
{
    int value ;
    Node* prev ;
    Node* next ;

    Node(int value) : value(value), prev(nullptr), next(nullptr) {}
} Node ;


class DoublyLL
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLL() : head(nullptr), tail(nullptr) {}

    void Insert( int value ) 
    {
        Node *newNode = new Node( value ) ;

        if ( head == nullptr )
        {
            head = tail = newNode ;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail ;
            tail = newNode;
        }
    }

    bool Remove( int value )
    {
        Node* temp = head; 

        while ( temp != nullptr )
        {
            if ( temp->value == value )
            {
                if ( temp->prev != nullptr )
                {
                    temp->prev->next = temp->next ;
                }
                else
                {
                    head = temp->next ;
                }

                if ( temp->next != nullptr )
                {
                    temp->next->prev = temp->prev ;
                }
                else
                {
                    tail = temp->prev ;
                }

                delete temp ;

                return true ;
            }

            temp = temp->next ;
        }

        return false ;
    }

    void Show()
    {
        Node *temp = head;

        while ( temp != nullptr )
        {
            printf("%d\t", temp->value ) ;
            temp = temp->next ;
        }

        printf("\n");
    }

    void ReverseShow()
    {
        Node* temp = tail; 
        while ( temp != nullptr )
        {
            printf("%d\t", temp->value );
            temp = temp->prev ;
        }
        printf("\n");
    }
};

int main() {
    DoublyLL dll;

    // 노드 추가
    dll.Insert(10);
    dll.Insert(20);
    dll.Insert(40);
    dll.Insert(60);
    dll.Insert(20);

    dll.Show() ;
    dll.Remove( 20 );
    dll.Show() ;
    return 0;
}