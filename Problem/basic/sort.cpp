#include <stdio.h>

void show( int *arr, int arr_sz )
{
    for ( int i = 0 ; i < arr_sz ; ++i )
    {
        printf("%d\t", arr[i] );
    }
    printf("\n");
}

void bubble_sort( int *arr, int arr_sz )
{
    for ( int i = 0 ; i < arr_sz - 1; ++i )
    {
        for ( int j = 0 ; j < arr_sz - i - 1; ++j )
        {
            if ( arr[j] > arr[j+1] )
            {
                int temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
        }
    }
}

int partition( int arr[], int low, int high )
{
    int pivot = arr[high] ;
    int  i = low - 1 ;

    for ( int j = low ; j < high ; ++j )
    {
        if ( arr[j] < pivot )
        {
            i++ ;

            int temp = arr[i] ;
            arr[i] = arr[j] ;
            arr[j] = temp ;
        }
    }

    int temp = arr[i+1]; 
    arr[i+1] = arr[high] ;
    arr[high] = temp ;

    return i + 1 ;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main( int argc, char **argv )
{
    const int arr_sz = 7; 
    int arr[arr_sz] = { 4,5,6,7,8,1,2 };
    int arr2[arr_sz] = { 4,5,6,7,8,1,2 };
    int arr3[arr_sz] = { 4,5,6,7,8,1,2 };

    show( arr, arr_sz ); 
    bubble_sort( arr, arr_sz );
    show( arr, arr_sz ); 

    show( arr2, arr_sz ) ;
    quickSort( arr2, 0, arr_sz - 1 ) ;
    show( arr2, arr_sz ) ;

    return 0;
} 