//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    int k,n=s.size(); cin>>k;
    rep(i,n){
        if(('z'-s[i]+1)%26<=k){
            k-=('z'-s[i]+1)%26;
            s[i]='a';
        }
    }
    s.back()=(s.back()-'a'+k)%26+'a';
    cout<<s<<endl;
}