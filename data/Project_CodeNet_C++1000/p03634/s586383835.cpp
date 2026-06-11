#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n-1],b[n-1],c[n-1];
    vector<vector<pair<int,int>>>pas(n);
    for(int i=0;i<n-1;i++){
        cin>>a[i]>>b[i]>>c[i];
        pas[a[i]-1].push_back({b[i]-1,c[i]});
        pas[b[i]-1].push_back({a[i]-1,c[i]});
    }
    int q,k;
    cin>>q>>k;
    k--;
    long long dist[n];
    int check[n]={};
    dist[k]=0;
    check[k]=1;
    queue<int>que;
    que.push(k);
    while(que.size()){
        int f=que.front();
        que.pop();
        for(int i=0;i<pas[f].size();i++){
            if(check[pas[f][i].first]==0){
                check[pas[f][i].first]=1;
                que.push(pas[f][i].first);
                dist[pas[f][i].first]=dist[f]+pas[f][i].second;
            }
        }
    }
    int x[q],y[q];
    for(int i=0;i<q;i++)cin>>x[i]>>y[i];
    for(int i=0;i<q;i++)cout<<dist[x[i]-1]+dist[y[i]-1]<<endl;
    return 0;
}