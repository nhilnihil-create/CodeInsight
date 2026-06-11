#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    string a,b,c;
    cin>>a>>b>>c;
    char t = 'a';
    char w;
    while(true){
        if(t == 'a'){
            if(a.size() == 0){
                w = 'A';
                break;
            }
            t = a[0];
            a.erase(0, 1);
        }else if(t == 'b'){
            if(b.size() == 0){
                w = 'B';
                break;
            }
            t = b[0];
            b.erase(0, 1);
        }else if(t == 'c'){
            if(c.size() == 0){
                w = 'C';
                break;
            }
            t = c[0];
            c.erase(0, 1);
        }
    }

    cout << w << endl;
}