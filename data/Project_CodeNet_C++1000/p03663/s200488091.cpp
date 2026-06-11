#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <strstream>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define ALL(x) (x).begin(), (x).end()
#define rt return
#define dll(x) scanf("%I64d",&x)
#define xll(x) printf("%I64d\n",x)
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define db(x) cout<<"== [ "<<x<<" ] =="<<endl;
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
inline void getInt(int* p);
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
string stdans="1000";
bool numcom(string a,string b)
{
    // <= >
    // 1 0
    if(a.length()<b.length())
    {
        return 1;
    }else if(a.length()>b.length())
    {
        return 0;
    }else
    {
        return a<=b;
    }
}
char judge(string ans)
{
    if(numcom(ans,stdans)==1&&(ans<=stdans))
    {
         return 'Y';
    }else if(numcom(ans,stdans)==0&&(ans>stdans))
    {
        return 'Y';
    }else
    {
        return 'N';
    }
}
int query(string ans)
{
    char x;
    cout<<"? "<<ans<<endl;
     cin>>x;
//    x=judge(ans);
    if(x=='Y')
    {
        return 1;
    }else
    {
        return 0;
    }
}
void solve()
{
    string temp="9";
    string ans="1";
    while(!query(temp))
    {
        temp+="9";
        ans+="0";
    }
    cout<<"! "<<ans<<endl;
}
int main()
{
    //freopen("D:\\common_text\\code_stream\\in.txt","r",stdin);
    //freopen("D:\\common_text\\code_stream\\out.txt","w",stdout);
    string ans="1";
    string res;
    while(1)
    {
        cout<<"? "<<ans<<endl;
         cin>>res;
//        res=judge(ans);
        if(res[0]=='Y')
        {
            ans+="0";
        }else
        {
            break;
        }
        if(ans.length()>11)
        {
            solve();
            // cout<<"! 1"<<endl;
            return 0;
        }
    }
    int len=ans.length();
    string temp;
    rep(i,0,len-1)
    {
        int mid;
        int l=0;
        int r=9;
        while(l<=r)
        {
            mid=(l+r)>>1;
            ans[i]='0'+mid;
            if(query(ans))
            {
                r=mid-1;
            }else
            {
                l=mid+1;
                temp=ans;
            }
        }
        ans=temp;
    }
    temp.pop_back();
    int num=temp.length();
////    if()
//    temp[num-1]++;
    stringstream ss;
    ss.clear();
    ss<<temp;
    ll fans;
    ss>>fans;
    fans++;
    cout<<"! "<<fans<<endl;

    return 0;
}

inline void getInt(int* p) {
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    }
    else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 + ch - '0';
        }
    }
}

