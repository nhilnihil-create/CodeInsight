#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <fstream>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define LLI long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
using namespace std;
//
const int INF=1e9+7;
const int MOD=1e9+7;
//
int main(){
    int n; cin>>n;
    int a[300001]={};
    FOR(i,0,3*n){
        cin>>a[i];
    }
    LLI b[100001]={};
    LLI c[100001]={};
    b[0]=0;
    priority_queue<int,vector<int>,greater<int>> q;
    FOR(i,0,n){
        q.push(a[i]);
        b[0]+=a[i];
    }
    FOR(i,0,n){
        q.push(a[n+i]);
        int t=q.top(); q.pop();
        b[i+1]=b[i]+a[n+i]-t;
    }
    priority_queue<int> q2;
    FOR(i,2*n,3*n){
        q2.push(a[i]);
        c[n]+=a[i];
    }
    ROF(i,0,n){
        q2.push(a[n+i]);
        int t=q2.top(); q2.pop();
        c[i]=c[i+1]+a[n+i]-t;
    }    
    LLI ans=-1e18;
    FOR(i,0,n+1){
        ans=max(ans,b[i]-c[i]);
    }
    co(ans);
}
