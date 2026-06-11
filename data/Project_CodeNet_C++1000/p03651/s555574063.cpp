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

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    int m=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m=max(m,a[i]);
    }
  int g=a[0];
    for(int i=0;i<n;i++){
        g=gcd(g,a[i]);
    }
    if(k>m||k%g!=0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<"POSSIBLE"<<endl;
    return 0;
}