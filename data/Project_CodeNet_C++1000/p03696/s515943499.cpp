#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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
    string s;
    int n;cin>>n>>s;
    int a=0,b=0;
    rep(i,n){
        if(s[i]=='('){
            a++;
        }
        else{
            if(a==0)b++;
            else a--;
        }
    }
    rep(i,b){
        s='('+s;
    }
    rep(i,a){
        s=s+')';
    }
    cout<<s<<endl;
    }