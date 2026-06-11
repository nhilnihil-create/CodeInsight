#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void cxxio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    cxxio();
    ll I, O, J, L, _;
    cin>>I>>O>>_>>J>>L;
    ll ans=O;
    if (I&&J&&L&&I%2+J%2+L%2>=2)
        ans+=3, I--, J--, L--;
    ans+=I/2*2;
    ans+=J/2*2;
    ans+=L/2*2;
    cout<<ans<<'\n';
}
