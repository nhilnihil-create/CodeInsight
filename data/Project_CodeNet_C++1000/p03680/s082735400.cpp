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
    vector<int> a(n+1);
    repi(i,1,n+1) cin>>a[i];
    int cnt=0,now=1;
    repi(i,1,n+1){
        cnt++;
        if(a[now]==2){
            cout<<cnt;
            return 0;
        }
        else now=a[now];
    }
    cout<<-1;
}