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
    int n,b;
    cin>>n;
    vector<int> a(100010);
    rep(i,n){
        cin>>b;
        if(b!=0) a[b-1]++;
        a[b]++;
        a[b+1]++;
    }
    sort(all(a));
    reverse(all(a));
    cout<<a[0];
}