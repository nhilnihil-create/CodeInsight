#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100003];

int main()
{
    int N,x;
    scanf("%d",&N);
    while (N--)
    {
        int t;
        scanf("%d",&t);
        a[t]++;
        a[t + 1]++;
        a[t + 2]++;
    }
      x=*max_element(a + 2, a + 100000) ;
     printf("%d",x);
    return 0;
}