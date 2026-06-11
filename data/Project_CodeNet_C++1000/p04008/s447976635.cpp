#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int MAX = 2001;
const int MOD = 1000000007;
 
 
vector<int> ko[100001];



 
signed main(){
    int n,k;
    cin>>n>>k;
    int oya[n],used[n]={},a;
    for(int i=0;i<n;i++){
        cin>>a;
        oya[i]=a-1;
        if(i!=0) ko[a-1].push_back(i);
       
    }
    int  t=0;
    queue<int> que,que2;
    priority_queue<pair<int,int>> pq;
    que.push(0);
    while(!que.empty()){
        a=que.front();
       
        que.pop();
        for(int i=0;i<ko[a].size();i++){
            if(ko[a][i]!=0)que2.push(ko[a][i]);
        }
       
        if(ko[a].size()==0){
            pq.push(make_pair(t,a));
             ;}
        while(!que.empty()){
             a=que.front();
          
        que.pop();
        for(int i=0;i<ko[a].size();i++){
            if(ko[a][i]!=0)que2.push(ko[a][i]);
        }
        
        if(ko[a].size()==0){
            pq.push(make_pair(t,a));
            
        }
        }
        swap(que,que2);
        t++;

    }
  
    int ans=0;
    pair<int,int> p;
    used[0]=1;
    while(!pq.empty()){
        p=pq.top();
        pq.pop();
        a=p.second;
        //cerr<<p.first<<' '<<p.second<<endl;
        t=0;
        if(used[a]!=1){
        used[a]=1;
        while(a!=0&&used[oya[a]]!=1&&t!=k-1){
            a=oya[a];
            t++;
            used[a]=1;

        }
        
           //cerr<<oya[a]<<endl;
        if(a!=0&&used[oya[a]]!=1&&t==k-1){
            pq.push(make_pair(p.first - k,oya[a]));
         
           
        }
        if(a!=0&&oya[a]!=0&&t==k-1){
         
            ans++;
        }
        }

    }
    if(oya[0]!=0)ans++;
    cout<<ans;

    return 0;
}