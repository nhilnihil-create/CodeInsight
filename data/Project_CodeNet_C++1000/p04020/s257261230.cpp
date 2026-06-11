#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=1e9;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i>0){
          int t=min(a[i-1],a[i]);
            ans+=t;
            a[i-1]-=t;
            a[i]-=t;
        }
        ans+=a[i]/2;
        a[i]-=(a[i]/2)*2;
    }
    cout<<ans<<endl;
    return 0;
}