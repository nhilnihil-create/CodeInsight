#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 




int main(void){
    string s;
    ll k;
    cin>>s>>k;
    ll n = s.length();
    map<char,ll>m;
    map<ll,char>inv;
    for(char x ='a';x<='z';x++){
        int y = x-'a';
        inv[y] = x;
        m[x]=26-y;
    }
    for(ll i=0;i<n;i++){
        if(k<=0)break;
        if(s[i]=='a')continue;
        if(m[s[i]]<=k){
            k-=m[s[i]];
            s[i]='a';
        }
    }
    if(k==0){
        cout<<s<<endl;
    }
    else{
        if(k>=26)k = k%26;
        ll x = s[n-1]-'a';
        s[n-1]=inv[x+k];
        cout<<s<<endl;
    }
    return 0;
}

