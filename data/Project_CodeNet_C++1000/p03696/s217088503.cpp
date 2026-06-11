#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int left=0;
    int right=0;
    int now = 0;
    rep(i,s.size()){
        if(s[i]=='('){
            now++;
        }else{
            if(now==0) left++;
            else now--;
        }

    }
    right = now;
    string ans ="";
    for(int i=0;i<left;i++) ans+="(";
    ans+=s;
    for(int i=0;i<right;i++) ans+=")";
    cout<<ans<<endl;
    return 0;
}