#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int p[110],q[110];
int main() {
    ll n;
    int l=0,r=0,t=0;
    cin>>n;
    while(n) {
	++t;
	if(n&1) p[++l]=t,n>>=1;
	else q[++r]=t,--n;
    }
    cout<<t+t<<endl;
    for(int i=1;i<=r;i++) cout<<q[i]<<' ';
    while(l)  cout<<p[l--]<<' ';
    while(t) cout<<t--<<' ';
    return 0;
}