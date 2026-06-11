#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    string t[4]={"dream","dreamer","erase","eraser"};
    reverse(s.begin(),s.end());
    rep(i,4)reverse(t[i].begin(),t[i].end());
    while(true){
        if(s.size()==0){
            cout<<"YES"<<endl;
            return 0;
        }
        bool ok=false;
        rep(i,4){
            int sz=t[i].size();
            if(s.substr(0,sz)==t[i]){
                s=s.substr(sz,(s.size()-sz));
                ok=true;
            }
        }
        if(!ok){
            cout<<"NO"<<endl;
            return 0;
        }
    }
}