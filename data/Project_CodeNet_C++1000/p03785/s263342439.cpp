#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, c, k; cin >> n >> c >> k;
    vector<ll> t(n);
    for(int i=0; i<n; i++)  cin >> t.at(i);
    sort(t.begin(), t.end());
    ll timer = t.at(0)+k, bus=1, cnt=1;
    for(int i=1; i<n; i++){
        if(t.at(i)<=timer && cnt+1<=c) {
            cnt += 1;   continue;
        }
        timer = t.at(i)+k;
        bus += 1;
        cnt = 1;
    }
    cout << bus << endl;

}