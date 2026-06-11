#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    string s;cin >>s;
    char ans='1';
    int n=s.size();
    for (char i ='a'; i <='z'; ++i) {
        bool flg=false;
        for (int j = 0; j < n; ++j) {
            if(i==s[j]){
                flg=true;
            }
        }
        if(!flg){
            ans=i;
            break;
        }
    }
    if(ans=='1')puts("None");
    else cout <<ans <<endl;
}
