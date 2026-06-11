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
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    ll n;cin>>n;
    vector<int> ans;
    ll m=1;
    while(!((m-1)*m/2<n&&n<=m*(m+1)/2)) m++;
    while(n>0){
        if(n<=m){
            ans.push_back(n);
            break;
        }else{
            ans.push_back(m);
            n-=m;
            m--;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}