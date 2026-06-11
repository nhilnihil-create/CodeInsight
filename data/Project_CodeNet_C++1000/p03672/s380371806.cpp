#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;

int main(){
    cin>>s;
    //int l=s.size();
    int ans=0;
    for(int i=2;s.size()-i>=2;i+=2){
        bool flag=true;
        rep(j,(s.size()-i)/2){
            if(s[j]!=s[(s.size()-i)/2+j]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=s.size()-i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}