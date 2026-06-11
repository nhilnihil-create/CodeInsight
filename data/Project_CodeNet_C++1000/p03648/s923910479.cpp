#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAX=200050;
ll n=50,k,a[MAX];
vector<int> conn[MAX];
queue<int> ret;
int main(){
    scanf("%lld",&k);
    for(int i=0;i<n;i++) a[i]=k/n+(n-1)-k%n;
    for(int i=0;i<k%n;i++) a[i]+=n+1;
    printf("%lld\n",n);
    for(int i=0;i<n;i++) printf("%lld ",a[i]);
    printf("\n");
}
