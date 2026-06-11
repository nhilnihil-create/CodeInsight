#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int v[9][2]={{-2,-2},{-1,-2},{0,-2},{-2,-1},{-1,-1},{0,-1},{-2,0},{-1,0},{0,0}};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long h,w,n;
    cin>>h>>w>>n;
    set<pair<int,int>> st;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin>>vp[i].first>>vp[i].second;
        st.insert(vp[i]);
    }
    long long ans[10]={};
    ans[0]=(h-2)*(w-2);
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            int cnt=0;
            int y=vp[i].first+v[j][0],x=vp[i].second+v[j][1];
            pair<int,int> pp={y,x};
            if(y<=0 || x<=0 || y+2>h || x+2>w || s.count(pp))continue;
            //cout<<y<<" "<<x<<endl;
            s.insert(pp);
            for(int k=y;k<y+3;k++){
                for(int l=x;l<x+3;l++){
                    pair<int,int> p={k,l};
                    if(st.count(p))cnt++;
                }
            }
            ans[cnt]++;
        }
    }
    for(int i=1;i<10;i++)ans[0]-=ans[i];
    for(int i=0;i<10;i++)cout<<ans[i]<<endl;

}