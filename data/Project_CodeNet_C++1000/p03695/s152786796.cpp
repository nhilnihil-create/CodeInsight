#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)
 
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n) cin>>a[i];
    vector<int>rate(9,0);
    rep(i,n){
     if(a[i]<=3199)rate[a[i]/400]++;
     else rate[8]++;
    }
    int minc=0;
    rep(i,8){
        if(rate[i]!=0)
          minc+=1;
    }
    int maxc=minc+rate[8];
    minc=max(1,minc);
    cout<<minc<<" "<<maxc<<endl;
}