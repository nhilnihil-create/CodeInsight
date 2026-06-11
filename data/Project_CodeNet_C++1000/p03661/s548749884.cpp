#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    long long sum=0;
    int n;
    long long a[200100];
    cin>>n;
    REP(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    long long s1=0;
    long long ans=1e18;
    for(int i=0;i<n-1;i++){
        s1+=a[i];
        long long s2=sum-s1;
        long long sa=s1-s2;
        if(sa<0)sa*=-1;
        ans=min(ans,sa);
    }
    cout<<ans<<endl;
}