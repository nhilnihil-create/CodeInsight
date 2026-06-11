#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
#include<queue>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int64_t n,a,b;
    cin>>n>>a>>b;
    if(a>b) cout<<0<<endl;
    else if(n==1&&a!=b) cout<<0<<endl;
    else if(n==1&&a==b) cout<<1<<endl;
    else{
        cout<<(n-2)*b-(n-2)*a+1<<endl;
    }
}
