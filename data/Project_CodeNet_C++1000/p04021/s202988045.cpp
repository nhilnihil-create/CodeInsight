#include <bits/stdc++.h>
#define NMAX 100010
using namespace std;
long long n, i, rez, x;
struct elem_poz
{
    long long val;
    int poz_initial;
    int poz_schimbat;
}v[1000005];
bool Sortare(elem_poz A, elem_poz B)
{
    return A.val<B.val;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        v[i].val=x;
        v[i].poz_initial=i;
    }
    sort(v+1, v+n+1, Sortare);


    for (int i=1; i<=n; i++)
        v[i].poz_schimbat=i;

    for (int i=1; i<=n; i++)
        if (v[i].poz_initial%2!=v[i].poz_schimbat%2)
            rez++;
    cout<<rez/2;
    return 0;
}