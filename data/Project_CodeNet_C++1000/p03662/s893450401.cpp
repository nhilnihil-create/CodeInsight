#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    int n,a,b;
    cin>>n;
    int d1[100100];//1からの距離
    int d2[100100];//Nからの距離
    REP(i,100100)d1[i]=d2[i]=-1;
    vector<int> r[100100];
    REP(i,n-1){
        cin>>a>>b;
        a--;b--;
        r[a].PB(b);
        r[b].PB(a);
    }
    queue<int>q;
    d1[0]=0;
    REP(i,r[0].size()){
        q.push(r[0][i]);
        d1[r[0][i]]=1;
    }
    while(q.size()){
        int p=q.front();q.pop();
        REP(i,r[p].size()){
            if(d1[r[p][i]]!=-1)continue;
            q.push(r[p][i]);
            d1[r[p][i]]=d1[p]+1;
        }
    }
    d2[n-1]=0;
    REP(i,r[n-1].size()){
        q.push(r[n-1][i]);
        d2[r[n-1][i]]=1;
    }
    while(q.size()){
        int p=q.front();q.pop();
        REP(i,r[p].size()){
            if(d2[r[p][i]]!=-1)continue;
            q.push(r[p][i]);
            d2[r[p][i]]=d2[p]+1;
        }
    }
    int cnt1=0;
    REP(i,n){
        if(d1[i]<=d2[i])cnt1++;
    }
    if(cnt1>(n-cnt1))cout<<"Fennec"<<endl;
    else cout<<"Snuke"<<endl;
}