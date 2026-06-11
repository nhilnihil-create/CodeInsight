#include<bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i],a[i]--;
    if(k==1){
        cout<<n-count(a.begin(),a.end(),0)<<endl;
    }
    else{
        int res=0;
        if(a[0]!=0) a[0]=0,res++;
        vector<int> d(n,0);
        for(int i=0;i<n;i++) d[a[i]]++;
        queue<int> que;
        for(int i=0;i<n;i++) if(d[i]==0) que.push(i); 
        vector<int> b(n);
        while(!que.empty()){
            int v=que.front(); que.pop();
            if(b[v]==k-1){
                if(a[v]!=0) res++;
                d[a[v]]--;
                if(d[a[v]]==0) que.push(a[v]);
                continue;
            }
            
            d[a[v]]--;
            b[a[v]]=max(b[a[v]],b[v]+1);
            if(d[a[v]]==0) que.push(a[v]);
        }
        cout<<res<<endl;
    }
    
    return 0;
}