/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main ()
{
    ll x,y;
    cin>>x>>y;
    ll z=x-y;
    if (z>=-1 && z<=1) cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;

    return 0;
}
