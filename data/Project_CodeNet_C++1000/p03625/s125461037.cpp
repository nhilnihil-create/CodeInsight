#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    vector<ll> leng(n, 0);
    ll tmp = 0;
    for(int j = 0; j < 2; j++){
        for(ll i = tmp; i < n - 1; i++){
            if(a[i] == a[i + 1]){
                leng[j] = a[i];
                tmp = i + 2;
                break;
            }
        }
    }
    cout << leng[0] * leng[1] << endl;
}