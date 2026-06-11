#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){

    int n,m;cin>>n>>m;
    vector<int> x(m),y(m);
    vector<int> ball(n+1);//個数
    vector<bool>red(n+1,false);//赤がある可能性

    for(int i =1;i<=n;i++){
        ball[i]=1;
        red[i]=0;
    }
    red[1]=true;
    rep(i,m){
        cin>>x[i]>>y[i];
    }
    rep(i,m){
        if(ball[x[i]]==0)break;
        ball[x[i]]-=1;
        ball[y[i]]+=1;
        if(red[x[i]])red[y[i]]=true;
        if(ball[x[i]]==0){
            red[x[i]]=false;
        }


    }
    int count =0;
    for(int i=1;i<=n;i++){
        if(red[i])count++;
    }
    cout<<count<<endl;
}