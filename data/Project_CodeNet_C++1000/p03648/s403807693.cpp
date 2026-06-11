#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    long long k;
    cin>>k;
    cout<<50<<endl;
    long long a=k/50;
    long long ans[50];
    REP(i,50)ans[i]=49+a;
    long long b=k%50;
    REP(i,b){
        REP(j,50){
            if(ans[j]+50<=10000000000001000){
                ans[j]+=50;
                REP(k,50)if(j!=k)ans[k]--;
                break;
            }
        }
    }
    REP(i,50)cout<<ans[i]<<" ";cout<<endl;
}