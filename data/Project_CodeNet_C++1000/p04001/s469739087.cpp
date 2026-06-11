// ARC61-C
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    string s;
    cin>>s;
    int l=SZ(s);
    ll ans=0;
    int num=pow(2,l-1);
    for(int i=0;i<num;i++){
        ll now=0;
        for(int j=0;j<l;j++){
            now=now*10+(s[j]-'0');
            if((i>>j)&1){
                ans+=now;
                now=0;
            }
        }
        ans+=now;
    }
    cout<<ans<<endl;
    return 0;
}