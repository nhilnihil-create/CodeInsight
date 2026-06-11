/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main ()
{
    ll k;
    ll ara[52];
    cin>>k;
    ll t=k/50;
    for (int i=0;i<50;i++) ara[i]=i+t;
    t=k%50;
    for (int i=0;i<t;i++) {
        ara[i]+=50;
        for (int j=0;j<50;j++) if (j!=i) ara[j]--;
    }
    cout<<50<<endl;
    for (int i=0;i<50;i++) cout<<ara[i]<<' ';

    return 0;
}
