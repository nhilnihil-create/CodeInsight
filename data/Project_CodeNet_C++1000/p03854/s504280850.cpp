#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin>>S;
    vector<string> c = {"dream","dreamer","erase","eraser"};
    reverse(S.begin(),S.end());
    rep(i,4) reverse(c[i].begin(),c[i].end());
    bool can = true;
    int p = 0;
    while(p<(int)S.size()&&can){
        string t;
        rep(i,3) t+=S[p+i];
        bool ok = true;
        if(t=="res"){
            rep(i,6){
                if(S[p+i]!=c[3][i]) {
                    can = false;
                    ok = false;
                }
            }
            if(ok) p+=6;
        }
        else if(t=="esa"){
            rep(i,5){
                if(S[p+i]!=c[2][i]) {
                    can = false;
                    ok = false;
                }
            }
            if(ok) p+=5;
        }
        else if(t=="rem"){
            rep(i,7){
                if(S[p+i]!=c[1][i]) {
                    can = false;
                    ok = false;
                }
            }
            if(ok) p+=7;
        }
        else if(t=="mae"){
            rep(i,5){
                if(S[p+i]!=c[0][i]) {
                    can = false;
                    ok = false;
                }
            }
            if(ok) p+=5;
        }
        else {
            can = false;
            ok=false;
        }
    }
    if(can&&p==(int)S.size()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}