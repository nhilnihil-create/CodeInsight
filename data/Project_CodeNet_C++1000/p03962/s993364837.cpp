#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
int main() {
    int a,b,c;cin>>a>>b>>c;
    int ans=3;
    if (a==b)
    {
        /* code */
        ans--;
    }
    if (b==c)
    {
        /* code */
        ans--;
    }
    if (c==a)
    {
        /* code */
        ans--;
    }
    if (ans==0)
    {
        /* code */
        ans++;
    }
    cout<<ans<<endl;
    
    
    
}