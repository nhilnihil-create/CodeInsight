#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int MOD=1000000007;
signed main(){
    int n;cin>>n;
    vector<int> a(n);rep(i,n)cin>>a[i];
    int res=0;
    vector<int> inc(a);
    sort(inc.begin(),inc.end());
    vector<int> odd;vector<int> even;
    rep(i,n){
        if(i%2==1)odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int odd_sum=0;int even_sum=0;
    rep(i,n){
        if(i%2==1){
            if(!binary_search(odd.begin(),odd.end(),inc[i])){
                odd_sum++;
            }
        }
        else{
            if(!binary_search(even.begin(),even.end(),inc[i])){
                even_sum++;
            }
        }
    }
    res=min(odd_sum,even_sum);
    cout<<res<<endl;
    return 0;
}