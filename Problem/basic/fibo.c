#include <stdio.h>

// Bottom-Up
int fibonacci( const int n )
{
    if ( n == 0 )
    {
        return 0;
    }
    if ( n == 1 )
    {
        return 1;
    }

    int dp[ n+1 ] ;

    dp[0] = 0 ;
    dp[1] = 1 ;

    for ( int i = 2 ; i <= n ; ++i )
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fibonacciTop( int* dp, const int n )
{
    if ( n == 0 )
    {
        return 0 ;
    }
    if ( n == 1 )
    {
        return 1 ;
    }

    if ( dp[n] != -1 )
    {
        return dp[n] ;
    }

    dp[n] = fibonacciTop( dp, n - 1 ) + fibonacciTop( dp, n - 2 ) ;

    return dp[n] ;
}

// Top-Down
int fibonacciWrapper( int n )
{
    int dp[10000];

    for ( int i = 0 ; i < 10000; ++i )
    {
        dp[i] = -1 ;
    }

    return fibonacciTop( dp, n) ;
}

int main()
{
    printf("Fibonacci : %d\n", fibonacci(15));
    printf("Fibonacci : %d\n", fibonacciWrapper(15));
    return 0;
}