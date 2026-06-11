#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<ll,ll> pii;
#define pb push_back
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%lld",&x)
#define out(x) printf("%lld",x)
#define X first
#define Y second
#define sps printf(" ")
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define all(v) v.begin(),v.end()
#define dis(it,it1) distance(it,it1)+1
#define MAX 100005
#define INF 9223372036854775807LL
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll a,ll b){return ((a*b)/__gcd(a,b));}
int main()
{
     ll test=1,cas=1;
     while(test--)
     {
		ll i,j,k,l,n,m,r;
		string s;
		cin>>s;
		if(s.size()==2)
        {
            if(s[0]==s[1])puts("1 2");
            else puts("-1 -1");
        }
        else
        {
            l=-1,r=-1;
            for(i=0;i<s.size()-2;i++)
            {
                if(s[i]==s[i+1]||s[i+1]==s[i+2]||s[i]==s[i+2])
                {
                    l=i+1;
                    r=i+3;
                }
            }
            cout<<l<<" "<<r;endl;
        }
     }
}
