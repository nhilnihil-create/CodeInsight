#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)

vector<bool> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t,m,y,z;
    string s;
    cin>>n>>s;
    for(ll prev1=0;prev1<2;prev1++){
        for(ll curr1=0;curr1<2;curr1++){
            ll curr=curr1;
            ll prev=prev1;
            ans.assign(n,false);
            bool x = prev;
            ans[n-1] = prev;
            ans[0] = curr;
            for(int i=0;i<(n-1);i++){
                if(!curr){
                    if(s[i]=='o'){
                        ans[i+1] = ans[(i-1+n)%n];
                    }
                    else{
                        ans[i+1] = !ans[(i-1+n)%n];
                    }
                }
                else{
                    if(s[i]=='o'){
                        ans[i+1] = !ans[(i-1+n)%n];
                    }
                    else{
                        ans[i+1] = ans[(i-1+n)%n];
                    }
                }
                prev = curr;
                curr = ans[i+1];
            }
            if(curr!=x)continue;
            if(!curr){
                if(s[n-1]=='o'){
                    if(ans[n-2]!=ans[0])continue;
                }
                else{
                    if(ans[n-2]==ans[0])continue;
                }
            }
            else{
                if(s[n-1]=='o'){
                    if(ans[n-2]==ans[0])continue;
                }
                else{
                    if(ans[n-2]!=ans[0])continue;
                }
            }
            for(int i=0;i<n;i++){
                cout<<(ans[i]?'W':'S');
            }
            return 0;
        }
    }
    cout<<-1;


    return 0;
}