#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a='a';
    string s;
    cin>>s;
    vec A;
    reverse(all(s));
    int b=0;
    int alp[26]={0};
    rep(i,s.size()){
        alp[s[i]-'a']++;
        int z=1;
        rep(j,26) if(alp[j]==0) z=0;
        if(z){
            b++;
            fill(alp,alp+26,0);
        }
        A.push_back(b);
    }
    fill(alp,alp+26,0);
    reverse(all(s));
    reverse(all(A));
    string ans;
    char now='z';
    int z=1;
    rep(i,s.size()){
        if(ans.size()&&ans[ans.size()-1]==s[i]){
            if(z==0) alp[s[i]-'a']--;
            z=1;
        }
        if(i==s.size()-1||A[i]!=A[i+1]){
            if(i==s.size()-1) alp[s[i]-'a']++;
            rep(j,26){
                if(alp[j]==0){
                    ans+=a+j;
                    break;
                }
            }
            fill(alp,alp+26,0);
            z=0;
            if(ans[ans.size()-1]==s[i]) z=1;
            continue;
        }
        if(z==0) continue;
        alp[s[i]-'a']++;
    }
    cout<<ans<<"\n";
}