#include <stdio.h>

int SackProblem( int maxW, int* values, int* weights, int n )
{
    int dp[n+1][maxW+1];

    for ( int i = 0 ; i <= n ; ++i )
    {
        for ( int w = 0 ; w <= maxW ; ++w )
        {
            if ( i == 0 || w == 0 )
            {
                dp[i][w] = 0;
            }
            else if ( weights[i-1] <= maxW )
            {
                dp[i][w] = (values[i-1] + dp[i-1][w-weights[i-1]] > dp[i-1][w]) \
                            ? values[i-1] + dp[i-1][w-weights[i-1]]             \
                            : dp[i-1][w];  // 선택하는 경우와 선택하지 않는 경우 비교
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][maxW] ;
}

int main()
{
    int values[] = {60,100,120};
    int weights[] = {10,20,30};
    int maxW = 50 ;

    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum Value : %d\n", SackProblem(maxW, values, weights, n));

    return 0;
}