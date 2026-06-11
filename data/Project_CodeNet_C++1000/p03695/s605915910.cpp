#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >>a[i];
        if(a[i]>3200)a[i]=3200;
        mp[(a[i]/400)]++;
    }
    int ans=0;
    for(int i=0;i<8;i++)ans+=(mp[i] > 0);
    cout << max(ans,1) << " " << ans + mp[8];
}