#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,t;
    cin >> n >> t;
    vector<ll> people(n);
    for(int i=0; i<n; i++){
        cin >> people.at(i);
    }
    ll ans = t;
    for(int i=1; i<n; i++){
        if(people.at(i-1)+t<=people.at(i)) ans+=t;
        else ans+=t-(people.at(i-1)+t-people.at(i));
    }
    cout << ans << endl;
}