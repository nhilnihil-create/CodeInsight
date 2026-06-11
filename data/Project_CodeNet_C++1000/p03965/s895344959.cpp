#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    fast();
    string s;cin>>s;
    int g=0,p=0;
    int ans=0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]=='g'){
            if(p+1>g)g++;
            else ans++,p++;
        }else {
            if(p+1>g)ans--,g++;
            else p++;
        }
    }
    cout<<max(ans,0);
}