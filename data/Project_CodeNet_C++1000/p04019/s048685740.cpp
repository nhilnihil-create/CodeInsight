#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int N,W,S,E;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string str;cin>>str;
    for(auto a : str){
        if(a=='N') N++;
        if(a=='S') S++;
        if(a=='W') W++;
        if(a=='E') E++;
    }
    if(((N>0&&S>0) && (W>0&&E>0)) || ((N>0&&S>0) && (W==0&&E==0)) || ((N==0&&S==0) && (W>0&&E>0))) {
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}