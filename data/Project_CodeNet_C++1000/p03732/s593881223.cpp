#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,mx=0;
    scanf("%d%d",&n,&m);
    map<int,int>mp;
    priority_queue<int>q;
    mp[0]=0;
    for(int i=0;i<n;i++){
        int w,v;
        scanf("%d%d",&w,&v);
        if(w>m||v==0) continue;
        for(map<int,int>::iterator it = mp.begin(); it!=mp.end();++it){
            int d = it->first;
            if(1ll*d+1ll*w<=m)  q.push(d+w);
        }
        while(!q.empty()){
            int d = q.top();q.pop();
            mp[d] = max(mp[d],mp[d-w]+v);
            mx = max(mx,mp[d]);
        }
    }
    mp.clear();
    cout<<mx<<endl;
    return 0;
}
