#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    string s;cin>>s;
    int l=0,r=0;
    rep(i,n){
        if(s[i]=='('){
            r++;
        }else{
            if(r>0)r--;
            else l++;
        }
    }
    rep(i,r)s+=')';
    reverse(s.begin(),s.end());
    rep(i,l)s+='(';
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}