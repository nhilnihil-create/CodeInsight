#include <bits/stdc++.h>
using namespace std;
#define int long long



int findx(int p[], vector<int> ko[], int oya, int co){
    if(ko[co].size()==1)return p[co];
    
    int sum=0,t,maxs=0;
    for(int i=0;i<ko[co].size();i++){
        if(ko[co][i]!=oya){
            t=findx(p,ko,co,ko[co][i]);
            if(t==-1)return -1;
            maxs=max(maxs,t);
            sum+=t;
        }
    }
    if(2*p[co]<sum)return -1;
    maxs=max(maxs,2*p[co]-sum);
    if(maxs>p[co])return -1;
    return 2*p[co]-sum;
}

signed main(){
    int n;

    cin >>n;
    int p[n];
    for(int i=0;i<n;i++)cin >>p[i];
    vector<int> ko[n];
    int a,b;
    for(int i=1;i<n;i++){
        cin >> a>>b;
        ko[a-1].push_back(b-1);
        ko[b-1].push_back(a-1);
    }
    if(n==2){
        if(p[0]==p[1])cout << " YES ";
        else cout << " NO ";

    }
    else{
        int k=0;
        while(ko[k].size()<=1)k++;
        if(findx(p,ko,-1,k)==0)cout <<" YES ";
        else cout <<" NO ";

    }
    


    return 0;
}