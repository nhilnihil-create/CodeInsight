#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int pile=0;
    rep(i,n){
        if(s.substr(i)==t.substr(0,n-i)){
            pile=n-i;
            break;
        }
    }
    cout<<2*n-pile<<endl;
}
