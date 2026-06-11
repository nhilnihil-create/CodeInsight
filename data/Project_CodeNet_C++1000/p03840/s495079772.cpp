#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long I, O, J, L, temp;
    cin>>I>>O>>temp>>J>>L>>temp>>temp;

    long long ans = O + (I/2)*2 + (J/2)*2 + (L/2)*2;
    if (I && J && L) {
        I--, J--, L--;
        ans = max(ans, O + (I/2)*2 + (J/2)*2 + (L/2)*2 + 3);
    }
    cout<<ans<<endl;
}
