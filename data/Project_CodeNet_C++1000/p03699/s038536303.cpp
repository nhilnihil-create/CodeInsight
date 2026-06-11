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
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sort(all(a));
    int i=0;
    while(sum%10==0&&i<n){
        if(a[i]%10!=0) sum-=a[i];
        i++;
    }
    if(sum%10==0) sum=0;
    cout<<sum;
}