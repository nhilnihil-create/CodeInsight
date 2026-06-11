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
    int n; cin>>n;
    string s,t; cin>>s>>t;
    int ans=n*2;
    int cnt=0;
    rep(i,n){
        if(s.substr(i,n-i)==t.substr(0,n-i)){
            cnt=n-i;
            break;
        }
    }
    cout<<ans-cnt<<endl;
}






