#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    string s;
    cin >> s;
    vector<string>d = {"maerd","remaerd","esare","resare"};
    reverse(s.begin(),s.end());
    bool ok = true;
    for(int i = 0;i < s.size();){
        bool can = false;
        rep(j,4){
            string e = d[j];
            string f = s.substr(i,e.size());
            if(e == f){
                can = true;
                i += e.size();
            }
        }
        if(can == false){
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}