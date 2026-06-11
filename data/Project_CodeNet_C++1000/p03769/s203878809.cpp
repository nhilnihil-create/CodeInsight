#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn=5e5+1;
typedef long long ll;
string to_bin(ll n){
    string res="";
    while (n){
        if (n&1)
            res+='1';
        else
            res+='0';
        n>>=1ll;
    }
    reverse(res.begin(),res.end());
    return res;
}
int col=0;
string dfs(ll n,int cur){
    if (n==1)
        return "";
    col++;
    if (n&1)
        return to_string(cur)+" "+dfs(n-1,cur-1);
    return dfs(n>>1,cur-1)+" "+to_string(cur);
}
int main(){
  //  ios_base::sync_with_stdio(0);
  //  cin.tie(0);
  //  cout.tie(0);
 //   freopen("output.txt","w",stdout);

    ll n;
    cin>>n;
    string cur=dfs(n+1,100);
    string ans="";
    for(int i=0; i<col; ++i)
        ans=to_string(100-i)+" "+ans;
    ans=cur+" "+ans;
    cout<<2*col<<"\n";
    cout<<ans;
}
