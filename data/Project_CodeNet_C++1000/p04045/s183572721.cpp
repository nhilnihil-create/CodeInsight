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
vector<ll>vt;
ll sz;
string ques;
vector<ll>ans;
bool chq(string a,string b)
{
//    cout<<a<<" "<<b;endl;
    ll num1,num2;
    stringstream ss;
    ss<<a;
    ss>>num1;
    ss.clear();
    ss<<b;
    ss>>num2;
//    cout<<num1<<" "<<num2;endl;
    return (num1>=num2?true:false);
}
void rec(ll idx,string s)
{
    if(idx==sz)
    {
        if(chq(s,ques))
        {
            stringstream ss;
            ss<<s;
            ll num;
            ss>>num;
            ans.pb(num);
        }
        return ;
    }
    if(idx==sz-1&&chq(s,ques))
    {
        stringstream ss;
        ss<<s;
        ll num;
        ss>>num;
        ans.pb(num);
        return ;
    }
    for(ll i=0;i<vt.size();i++)
    {
        s.pb(vt[i]+'0');
        rec(idx+1,s);
        s.pop_back();
    }
}
int main()
{
    ll i,j,k,l,n,m,r;
    cin>>ques>>k;
    ll arr[10];
    ms(arr,0);
    for(i=0;i<k;i++)
    {
        in(m);
        arr[m]=1;
    }
    for(i=0;i<10;i++)if(!arr[i])vt.pb(i);
    sz=ques.size()+1;
    rec(0,"");
    sort(all(ans));
    cout<<ans[0];endl;
}
