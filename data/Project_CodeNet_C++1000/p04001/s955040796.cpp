#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 

int main(){
    string s;
    cin>>s;
    int n=s.size();
    ll ans=0;
    for(int bit=0; bit<(1<<n-1);bit++){
        ll count=s[0]-'0';
        rep(i,n-1){
            if(bit&(1<<i)) {
                ans+=count;
                count=s[i+1]-'0';
            }
            else{
                count*=10;
                count+=s[i+1]-'0';
            }
        }
        ans+=count;
    }
    cout<<ans<<endl;

}