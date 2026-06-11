#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
        mp[a[i]-1]++;
        mp[a[i]+1]++;
        ans=max(ans,max(mp[a[i]],max(mp[a[i]-1],mp[a[i]+1])));
    }
    cout << ans;
}