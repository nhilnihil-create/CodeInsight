#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N;string s;
    cin>>N>>s;
    string ans[4]={"SS","SW","WS","WW"};
    rep(i,1,N) REP(j,4){
        if(s[i]=='o'){
            if(ans[j][i]=='S') ans[j].push_back(ans[j][i-1]);
            else ans[j].push_back(ans[j][i-1]=='S'?'W':'S');
        }
        else{
            if(ans[j][i]=='S') ans[j].push_back(ans[j][i-1]=='S'?'W':'S');
            else ans[j].push_back(ans[j][i-1]);
        }
    }
    REP(i,4) if(ans[i][0]==ans[i][N]){
        if(ans[i][0]=='S'){
            if(s[0]=='o'&&ans[i][1]!=ans[i][N-1]) continue;
            if(s[0]=='x'&&ans[i][1]==ans[i][N-1]) continue; 
        }
        if(ans[i][0]=='W'){
            if(s[0]=='o'&&ans[i][1]==ans[i][N-1]) continue;
            if(s[0]=='x'&&ans[i][1]!=ans[i][N-1]) continue;
        }
        ans[i].pop_back();
        cout<<ans[i]<<endl;
        return 0;
    }
    cout<<-1<<endl;
}
