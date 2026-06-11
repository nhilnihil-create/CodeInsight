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
    int n,cnt=0,i=1;
    cin>>n;
    vector<int> a(n+1),on(n+1);
    repi(i,1,n+1) cin>>a[i];
    while(on[2]==0){
        if(cnt>n){
            cout<<-1;
            return 0;
        }
        on[a[i]]++;
        cnt++;
        i=a[i];
    }
    cout<<cnt;
}