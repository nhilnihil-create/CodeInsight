#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int k;
    string s;
    cin >> s >> k;
    int n=s.size();
    int x;

    for(int i=0; i<n; i++){
        if(s[i]=='a') continue;
        x=26-(s[i]-'a');
        if(x<=k){
            s[i]='a';
            k-=x;
        }
    }

    x=(s[n-1]-'a'+k)%26;
    s[n-1]='a'+x;

    cout << s << endl;
    
    return 0;
}