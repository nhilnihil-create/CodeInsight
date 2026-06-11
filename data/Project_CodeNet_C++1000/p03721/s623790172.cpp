
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli n,k;
    cin>>n>>k;
    vector<pii> rec;
    rep(i,n){
        lli a,b;
        cin>>a>>b;
        rec.push_back(pii(a,b));
    }
    sort(all(rec));
    lli ans,cnt=0;
    rep(i,rec.size()){
        cnt+=rec[i].second;
        if(cnt>=k){
            ans=rec[i].first;
            break;
        }
    }
    out(ans);
}