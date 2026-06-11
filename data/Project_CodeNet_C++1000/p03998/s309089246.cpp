#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string a, b, c;
    cin >> a >> b >> c;
    char tmp='a';
    a = a.substr(1);
    while(true){
        if(tmp=='a'){
            tmp = a[0];
            if(a==""){
                cout<<'A'<<endl;
                return 0;
            }else a = a.substr(1);
        }else if(tmp=='b'){
            tmp = b[0];
            if(b==""){
                cout<<'B'<<endl;
                return 0;
            }else b = b.substr(1);
        }else if(tmp=='c'){
            tmp = c[0];
            if(c==""){
                cout<<'C'<<endl;
                return 0;
            }else c = c.substr(1);
        }
    }
    return 0;
}