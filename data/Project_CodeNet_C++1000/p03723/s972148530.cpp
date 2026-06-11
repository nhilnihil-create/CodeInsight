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
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c&&a%2==0){
        cout<<-1<<endl;
        return 0;
    }
    ll ans=0;
    while(a%2==0&&b%2==0&&c%2==0){
        ll aa=a,bb=b,cc=c;
        a=bb/2+cc/2;
        b=aa/2+cc/2;
        c=aa/2+bb/2;
        ans++;
    }
    cout<<ans<<endl;
}