#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
int main() {
    string s;
    ll k;
    cin>>s>>k;
    for(int i=0; i<s.size(); i++){
        int t=(26-(s[i]-'a'))%26;
        if(t<=k){
            k-=t;
            s[i]='a';
        }
    }
    s[s.size()-1]=(char) ( (k+s[s.size()-1]-'a')%26 + 'a' ) ;
    cout<<s<<endl;
}
