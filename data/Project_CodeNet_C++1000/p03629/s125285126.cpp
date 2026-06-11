#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    string s;
    cin>>s;

    s+="abcdefghijklmnopqrstuvwxyz";
    
    vector<int> bounds;
    bounds.pb(s.size());
    vector<bool> hist(26,0);
    for(int i=s.size()-1;i>=0;i--){
        hist[s[i]-'a'] = true;
        if(hist==vector<bool>(26,true)){
            bounds.pb(i);
            hist = vector<bool>(26,0);
        }
    }
    reverse(all(bounds));
    
    vector<int> pos[26];
    rep(i,s.size()){
        pos[s[i]-'a'].pb(i);
    }
    
    
    int p = -1;
    string ans = "";
    while(1){
        if((int)s.size()-26<=p)break;
        for(char ch = 'a';ch<='z';ch++){
            if(upper_bound(all(bounds),p)==bounds.end())goto end;
            int b = *upper_bound(all(bounds),p);
            int t = *upper_bound(all(pos[ch-'a']),p);
            if(b<=t){
                ans+=ch;
                p = t;
                break;
            }
        }
    }
end:;
    cout<<ans<<endl;
}
