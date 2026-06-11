#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, ar[100];

    scanf("%d %d", &n, &l);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }

    sort(ar, ar+n);

    int sum = 0;

    for(int i=n-1; i>=(n-l); i--)
    {
        sum = sum + ar[i];
    }

    printf("%d\n", sum);

    return 0;
}