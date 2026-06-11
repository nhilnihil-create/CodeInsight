#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int sdkys(int a,int b){
    if(b==0) return a;
    return sdkys(b,a%b);
}
int sskbs(int a,int b){
    return a*b/sdkys(a,b);
}
int n,m,cnt=0,aa[330000],ans=0,ab[220000];
pair<int,int> pp[220000];
string s,sa[220000];
char ca[220000];
queue<int> que;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>aa[i];
    }
    rep(i,n){
        if(aa[aa[i]-1]==i+1){
            cnt++;
        }
    }
    cout<<cnt/2<<endl;
}