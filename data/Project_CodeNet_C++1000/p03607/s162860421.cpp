#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        mp[a]++;
    }
    int ans=0;
    for(auto u:mp)if(u.second%2==1)ans++;
    cout << ans;
}