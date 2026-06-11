#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    string s;cin>>s;
    map<char,int>mp;
    rep(i,s.size()){
        mp[s[i]]++;
    }
    if((mp['N']>0)&&(mp['S']==0)){co("No");return 0;}
    if((mp['S']>0)&&(mp['N']==0)){co("No");return 0;}
    if((mp['W']>0)&&(mp['E']==0)){co("No");return 0;}
    if((mp['E']>0)&&(mp['W']==0)){co("No");return 0;}
    co("Yes");
}