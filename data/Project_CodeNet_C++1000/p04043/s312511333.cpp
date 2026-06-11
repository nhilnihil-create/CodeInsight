//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    vector<ll>a(3);
    rep(i,3)cin>>a[i];
    sort(a.begin(),a.end());
    if(a[0]==5&&a[1]==5&&a[2]==7)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}






