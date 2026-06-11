#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr first
#define sc second
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=3e5+10;
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    string s,t;
    cin>>s>>t;
    int i=0;
    ll ans=1;
    bool b=false;
    if (s[0]==t[0]){
        ans=3;
        i=1;
    }
    else{
        ans=6;
        i=2;
        b=true;
    }
    while (i<x){
        if (s[i]==t[i]){
            if (!b){
                ans*=2;
                ans%=mod;
            }
            b=false;
            i++;
        }
        else{
            if (b)
            {
                ans*=3;
                ans%=mod;
            }
            else{
                ans*=2;
                ans%=mod;
            }
            i+=2;
            b=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}
