#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    ll k;
    cin>>s>>k;
    ll n=s.length();
    for(int i=0;i<n;i++){
        if(i==n-1){
            s[i]=('a'+((s[i]-'a')+k)%26);
        }
        else if(s[i]!='a'){
            if((s[i]-'a')+k>=26){
                k-=(26-(s[i]-'a'));
                s[i]='a';
            }
        }
    }
    cout << s<<endl;
    return 0;
}

