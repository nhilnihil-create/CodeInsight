#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,m,a,b;
    cin>>n>>m;
    vector<long long> ans(n,0);
    f(i,0,m){
        cin>>a>>b;
        ans[a-1]++;
        ans[b-1]++;
    }
    f(i,0,n){
        cout<<ans[i]<<endl;
    }
    return 0;
}
