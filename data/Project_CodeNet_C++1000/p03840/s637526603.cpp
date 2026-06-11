#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=998244353;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");


main(){
    ll int a[7];
    rep(i,7){
        cin>>a[i];
    }
    ll int sum1=0,sum2=0;
    if(a[0]&&a[3]&&a[4]){
        sum1=3;
        a[0]--; a[3]--; a[4]--;
        sum1+=(a[0]/2)*2;
        sum1+=(a[3]/2)*2;
        sum1+=(a[4]/2)*2;
        sum1+=a[1];
    
    a[0]++; a[3]++; a[4]++;}
    sum2+=(a[0]/2)*2;
    sum2+=(a[3]/2)*2;
    sum2+=(a[4]/2)*2;
    sum2+=a[1];
    cout<<max(sum1,sum2);
    return 0;

}
