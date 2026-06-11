#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

 
int main() {
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i+1]!=s[i])ans++;
    }
    cout<<ans<<endl;
}