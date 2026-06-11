#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
vector<int> a(110);
set<string> rate;

int main(){
    int free=0;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        if(a[i]<400) rate.insert("gray");
        else if(a[i]<800) rate.insert("brown");
        else if(a[i]<1200) rate.insert("green");
        else if(a[i]<1600) rate.insert("lblue");
        else if(a[i]<2000) rate.insert("blue");
        else if(a[i]<2400) rate.insert("yellow");
        else if(a[i]<2800) rate.insert("orange");
        else if(a[i]<3200) rate.insert("red");
        else free++;
    }

    int minv=rate.size();
    int maxv=minv+free;
    if(minv==0) minv=1;
    cout<<minv<<" "<<maxv<<"\n";
    return 0;
}