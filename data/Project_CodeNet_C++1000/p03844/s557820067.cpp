#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define txt freopen("ip.txt", "r", stdin); freopen("op.txt", "w", stdout)
#define a3 INT_MAX
#define i3 INT_MIN
#define a6 INT64_MAX
#define i6 INT64_MIN
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define div2(a) (!(a&1))
#define deb(x) cout<<(#x)<<" "<<(x)<<"\n";
#define newl cout<<"\n" 
#define pi 3.14159265358979323846
#define mod 1000000007
#define all(s) s.begin(),s.end()
#define fp(x) fixed<<setprecision(x)<<
#define split(x) while ((cout<<s[i],i+=1) && (i<n-1) && (cout<<x));
int digit(ll a)
{
    vector<long long> dig = {
        0,
        9,
        99,
        999,
        9999,
        99999,
        999999,
        9999999,
        99999999,
        999999999,
        9999999999,
        99999999999,
        999999999999,
        9999999999999,
        99999999999999,
        999999999999999,
        9999999999999999,
        99999999999999999,
        999999999999999999,
        INT64_MAX};
    auto it = lower_bound(dig.begin(), dig.end(), a);
    int idx = (it - dig.begin());
    return idx;
}
int main(){
    quickie;
    //txt;
    int a,b; cin>>a;
    char c; cin>>c>>b;
    if(c == '+')
        cout<<a+b;
    else
    {
        cout<<a-b;
    }
    
    
    return 0;
}