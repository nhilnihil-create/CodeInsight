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
    cin>>s;
    string t="CODEFESTIVAL2016";
    int ans=0;
    for(int i=0;i<16;i++){
    	if(s[i]!=t[i])ans++;
    }
    cout <<ans <<endl;
    return 0;
}
