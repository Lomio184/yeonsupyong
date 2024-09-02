#include <stdio.h>

typedef struct Element
{
    int value ;
    Element *next;
} E ;

Element* MakeFirstElement( int value ) 
{
    Element *element = new Element();
    element->value = value ;
    element->next = nullptr;

    return element;
}

bool Connect( Element* first, int value )
{
    if ( first == nullptr )
    {
        return false ;
    }

    Element *second = new Element() ;
    second->value = value ;
    second->next  = nullptr;

    Element *temp = first ;

    while ( temp->next != nullptr )
    {
        temp = temp->next;
    }

    temp->next = second ;

    return true ;
}

bool Disconnect(Element** first, int find_val)
{
    if (*first == nullptr)
    {
        return false;
    }

    Element *temp = *first;
    Element *previous = nullptr;

    while (temp != nullptr)
    {
        if (temp->value == find_val)
        {
            if (previous == nullptr)
            {
                *first = temp->next; 
                delete temp;
            }
            else
            {
                previous->next = temp->next;
                delete temp;
            }
            return true;
        }
        else
        {
            previous = temp;
            temp = temp->next;
        }
    }

    return false; // find_val을 찾지 못한 경우
}

void Show( Element* element )
{
    Element* temp = element ;
    
    while ( temp != nullptr )
    {
        printf("%d\t", temp->value );
        temp = temp->next ; 
    }
    printf("\n");

    return ;
}

int main( int argc, char **argv )
{
    Element *first = MakeFirstElement(1);
    
    for ( int i = 2; i < 6 ; ++i )
    {
        Connect( first, i );
    }
    Show(first);

    if (false == Disconnect( &first, 1 ))
    {
        printf("Can't find value");
    }

    Show(first );
    return 0;
}