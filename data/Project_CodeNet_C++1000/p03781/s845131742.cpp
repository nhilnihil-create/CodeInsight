#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll nr;
    cin >> nr;
    ll aux = (sqrt(4*2*nr +1)-1)/2;
    if((2*aux+1)*(2*aux+1)<(4*2*nr+1))
        aux++;
    cout<<aux;
    return 0;
}

