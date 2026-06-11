#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    string s;cin>>s;
    int n =s.length();
    int ans =1;
    char a = s[0];
    rep(i,n){
        if(i==0)continue;
        if(s[i]!=a){
            ans++;
            a=s[i];
        }
    }
    cout<<ans-1<<endl;
}