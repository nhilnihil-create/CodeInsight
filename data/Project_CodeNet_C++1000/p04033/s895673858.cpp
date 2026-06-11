#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int a,b;
    cin>>a>>b;
    if(a<=0&&b>=0) cout<<"Zero";
    if(a>0) cout<<"Positive";
    if(b<0){
        if((b-a)%2==0) cout<<"Negative";
        else cout<<"Positive";
    }
}