#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define loop(i,n) for(int i=0 ; i<n ; i++)
#define rep(i,x,n) for(int i=x ; i<=n ; i++)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N=5e3 + 5,M=5e5+5, MOD=1e9 + 7;
int memo[N][N];
int n,arr[N],k;
map<int,int> ind;
vector<int> vec;
bool valid(int j){
    int x=vec[j];
    int bad=ind[x];
    for(int i=n-1 ; ~i ; --i){
        for(int sum=k-1 ; ~sum ; --sum){
            if(i==bad || sum+arr[i]>=k){
                memo[i][sum]=memo[i+1][sum];
            }else{
                memo[i][sum]=max(memo[i+1][sum+arr[i]],memo[i+1][sum]);
            }
        }
    }
    return memo[0][0]>=k-x;
}
int main() {
#ifndef ONLINE_JUDGE
  //  freopen("in.txt", "rt", stdin);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    set<int> nums;
    loop(i,n){
        cin>>arr[i];
        nums.insert(arr[i]);
        ind[arr[i]]=i;
    }
    for(int x:nums){
        vec.push_back(x);
    }
    loop(j,k+3){
        memo[n][j]=j;
    }
    int st=0,en=vec.size()-1;
    while(st<=en){
        int mid=(st+en)/2;
        if(valid(mid)){
            en=mid-1;
        }else{
            st=mid+1;
        }
    }
    vec.push_back(1e9 + 5);
    int ans=0;
    loop(i,n){
        if(arr[i]<vec[en+1])ans++;
    }
    cout<<ans<<endl;
}