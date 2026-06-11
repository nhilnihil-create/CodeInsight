#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    if(a>b)swap(a,b);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    if(c%2==0)cout << 0 << endl;
    else cout << a*b << endl;
    return 0;
}
