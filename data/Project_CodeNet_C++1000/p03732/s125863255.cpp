#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

ll W,w1;
mat x(5);
int S[4][110];
int ans=0;
void func(int s,ll w,int v){
    if(s==4){
        if(w<=W)ans=max(ans,v);
        return;
    }
    for(int i=0;i<=x[s].size();i++){
        ll p=w;int q=v;
        p+=(ll)i*(ll)(w1+s);
        q+=S[s][i];
        if(p>W)continue;
        func(s+1,p,q);
    }
}

int main(){
    int N;cin>>N>>W;
    int v1;cin>>w1>>v1;
    x[0].push_back(v1);
    ll w;int v;
    for(int i=2;i<=N;i++){
        cin>>w>>v;
        x[w-w1].push_back(v);
    }
    sort(x[0].begin(),x[0].end(),greater<int>());
    sort(x[1].begin(),x[1].end(),greater<int>());
    sort(x[2].begin(),x[2].end(),greater<int>());
    sort(x[3].begin(),x[3].end(),greater<int>());
    
    S[0][0]=S[1][0]=S[2][0]=S[3][0]=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=x[i].size();j++)
            S[i][j]=S[i][j-1]+x[i][j-1];
    }
    func(0,0,0);
    cout<<ans<<endl;
    return 0;
}