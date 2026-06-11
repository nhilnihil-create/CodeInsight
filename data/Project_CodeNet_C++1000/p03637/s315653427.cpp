#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n)cin>>a[i];
    map<int,int> mp;
    rep(i,n){
        if(a[i]%4==0){
            mp[4]++;
        }
        else if(a[i]%2==0){
            mp[2]++;
        }
    }
    int rem = n - mp[2] - mp[4];
    if(rem<=mp[4]||mp[2]==0&&rem<=mp[4]+1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}