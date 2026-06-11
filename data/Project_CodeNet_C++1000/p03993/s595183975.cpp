#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ll se=0;
ll sume(vector<int> a,int n){

}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[a[i]]==i) ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}