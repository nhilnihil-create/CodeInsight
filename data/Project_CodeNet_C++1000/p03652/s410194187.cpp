#include <bits/stdc++.h>
using namespace std;
//#define int long long

 //bool dp[2][4000001];

signed main(){
   int n,m;
   cin >> n>>m;
   
   int a[n][m+1],u;
   for(int i=0;i<n;i++)for(int j=0;j<m;j++){
       cin >>u;
       a[i][j]=u-1;
   }
   for(int i=0;i<n;i++)a[i][m]=m;
   vector<int> sanka[m];
   int jun[n]={};
   int s[m+1]={},maxs,t=1;
   //cerr<<'u';
   for(int i=0;i<n;i++)sanka[a[i][0]].push_back(i);
  // cerr<<'u';
   while(t!=-1){
    maxs=0;
    for(int i=0;i<m;i++)maxs=max(maxs,int(sanka[i].size()));
    t=1;
    while(t==1){
        t=0;
        for(int i=0;i<m;i++){
            if(sanka[i].size()>=maxs){
                t=1;
                s[i]=1;
                while(!sanka[i].empty()){
                    int t=sanka[i].back();
                    sanka[i].pop_back();
                    while(s[a[t][jun[t]]]==1)jun[t]++;
                   if(jun[t]!=m) sanka[a[t][jun[t]]].push_back(t);
                }
            }
        }
        if(jun[0]==m)t=-1;
    }
   }
   cout <<maxs;


    return 0;
}
