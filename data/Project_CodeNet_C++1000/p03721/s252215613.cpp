#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, a, b, j;
    ll k;

    cin >> n >> k;
    vector<ll> v(100001);

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[a] += b;
    }

    j = 0;
    while(1){
        if(v[j] != 0) k -= v[j];
        if(k <= 0) break;
        j++;
    }

    cout << j;
}
