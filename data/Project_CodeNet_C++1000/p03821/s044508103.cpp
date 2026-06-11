#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin >> n;
    vector<ll> a(100000), b(100000);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    ll cum = 0;
    for(int i=n-1; i>=0; i--){
        a[i] += cum;
        int tmp = a[i]%b[i];
        if(tmp==0) continue;
        else cum += b[i] - tmp;
    }
    cout << cum << endl;
    return 0;
}