#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "

int main(){
    ll a,b,n;cin>>n>>a>>b;
    if(n==0||(n==1&&a!=b)){co(0);return 0;}
    if(n==1&&a==b){co(1);return 0;}
    co(max((ll)0, (n-2)*(b-a)+1));
}