#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
//#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    ll n,a,b;
    cin>>n>>a>>b;
    ll mx=a+(n-1)*b;
    ll mi=a*(n-1)+b;
    cout<<max(mx-mi+1,0LL);
}