#include<bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int Dy[8] = {-1,-1,0,1,1,1,0,-1};
int Dx[8] = {0,1,1,1,0,-1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a="CODEFESTIVAL2016";
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<16;i++){
        if(s[i]!=a[i])res++;
    }
    cout<<res<<endl;
}