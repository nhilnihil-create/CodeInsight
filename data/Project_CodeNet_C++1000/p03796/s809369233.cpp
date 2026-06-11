#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
#define NUM 1000000007
int main() {
    int n;
    cin>>n;
    ll power=1;
    repi(i,1,n+1){
        power=(power*i)%NUM;
    }
    cout<<power;
}