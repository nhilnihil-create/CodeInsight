#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    char now = 'a';
    char ans;
    bool ok = true;
    while(ok){
        if(now == 'a'){
            if(a.size() == 0){
                ok = false;
                ans = 'A';
            }
            else{
                now = a[0];
                a = a.substr(1);
            }
        }
        if(now == 'b'){
            if(b.size() == 0){
                ok = false;
                ans = 'B';
            }
            else{
                now = b[0];
                b = b.substr(1);
            }
        }
        if(now == 'c'){
            if(c.size() == 0){
                ok = false;
                ans = 'C';
            }
            else{
                now = c[0];
                c = c.substr(1);
            }
        }
    }
    cout << ans << endl;
}