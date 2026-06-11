#include <bits/stdc++.h>
const int N = 44721;
using namespace std;
int sum[N];
int main()
{
 
 
    for (int i = 1; i <= N; i++)
    {
        sum[i] = sum[i-1] + i;
    }
    int x;
    while (~scanf("%d", &x))
    {
        int loc = lower_bound(sum, sum + N, x) - sum;
  
        printf("%d\n", loc);
    }   
    return 0;
}
