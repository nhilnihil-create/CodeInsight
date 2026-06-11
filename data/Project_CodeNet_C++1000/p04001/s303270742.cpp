#include <bits/stdc++.h>
#define mod 1000000007
using ll = long long;
using namespace std; 
const double pi = acos(-1);

int main() {
    string s; cin >> s;
    int d=s.size();
    vector<string> a(d);
    vector<int> aa;
    ll ans=0;
    int ss=d;
    for (int i=0;i<d;i++){
        a[i]=s[i];
    } 
    for (int i=0;i<(1<<d-1);i++){
        for (int j=0;j<d-1;j++){           
            if (i&(1<<j)){
                string f;
                for (int k=d-1-j;k<ss;k++){
                    f+=a[k];
                }
                ll ff=stoll(f);
                ans+=ff;
                ss=d-1-j;
            }
        }
        string g;
        for (int k=0;k<ss;k++){
            g+=a[k];
        }
        ll ff=stoll(g);
        ans+=ff;
        ss=d;
    }
    cout << ans << "\n";
}
