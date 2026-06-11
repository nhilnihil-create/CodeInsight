#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n=s.size();
    vector<ll> count(n);
    for(ll i=0;i<n;i++){
        if(s[i]=='a'){
            count[i]=0;
            continue;
        }
        count[i]=26-(s[i]-'a');
    }
    for(ll i=0;i<n-1;i++){
        if(count[i]<=k){
            s[i]='a';
            k-=count[i];
        }
    }
    k%=26;
    if(k>=count[n-1]) s[n-1]='a'+(k-count[n-1]);
    else s[n-1]=s[n-1]+k;
    cout << s << endl;
    return 0;
}  
