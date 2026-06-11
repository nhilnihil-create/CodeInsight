#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N; cin >> N;
    ll ans = 0;
    int data[N];
    map<int,ll> mp{};
    
    for(int i=0;i<N;i++) cin >> data[i];
    sort(data,data+N);

    for(int i=0;i<N;i++){ mp[data[i]]++; }
    
    for(int i=data[0];i<=data[N-1];i++){
        ll sum;
        sum = mp[i-1] + mp[i] + mp[i+1];
        if(sum > ans) ans = sum;
    }
    cout << ans << endl;
}