#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector <int> p(n);
    for(int&i : p)
        scanf("%d",&i) ,i--;

    vector <int> a(n) ,b(n);
    for(int i=0; i<n; i++)
        a[i] = n*i+1;
    for(int i=0; i<n; i++)
        b[p[i]] = n*n-a[p[i]]+i;

    for(int&i:a) printf("%d ",i); printf("\n");
    for(int&i:b) printf("%d ",i); printf("\n");
}
