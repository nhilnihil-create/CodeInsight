#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
vector<int> a(100005);

int main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    int b=a[0];
    int cnt=1;
    bool flag=false;
    rep(i,n){
        if(b==2){
            flag=true;
            break;
        }
        b=a[b-1];
        cnt++;
   }
    if(flag) cout<<cnt<<"\n";
    else cout<<-1<<"\n";
    return 0;
}