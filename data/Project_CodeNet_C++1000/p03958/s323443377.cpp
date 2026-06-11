#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll k,t;
    cin >> k >> t;
    vector<int> a(t);
    int i,j;
    for(i=0;i<t;i++)cin >> a.at(i);
    sort(a.begin(),a.end());

    ll sum=0;
    ll ans=0;
    for(i=0;i<t-1;i++){
        sum+=a.at(i);
    }
    if(sum+1>=a.at(t-1))ans=0;
    else ans = a.at(t-1) - sum -1;
    cout << ans << endl;
    return 0;
}