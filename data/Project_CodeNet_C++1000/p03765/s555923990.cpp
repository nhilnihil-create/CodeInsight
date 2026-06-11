/** Hien Jeony **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) (n^(1<<(i-1)))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))
const int mod=1e9+7;
using namespace std;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
string s,t;
int q;
int cntas[100001];
int cntbs[100001];
int cntat[100001];
int cntbt[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("in.inp","r",stdin);
    //freopen("ou.out","w",stdout);
    cin>>s>>t;
    int lenS=s.size();
    int lenT=t.size();
    s=' '+s;
    t=' '+t;
    for(int i=1;i<=lenS;i++)
    {
        cntas[i]=cntas[i-1];
        cntbs[i]=cntbs[i-1];
        if(s[i]=='A') cntas[i]++;
        else cntbs[i]++;
    }
    for(int i=1;i<=lenT;i++)
    {
        cntat[i]=cntat[i-1];
        cntbt[i]=cntbt[i-1];
        if(t[i]=='A') cntat[i]++;
        else cntbt[i]++;
    }
    cin>>q;
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int As=cntas[b]-cntas[a-1];
        int Bs=cntbs[b]-cntbs[a-1];
        int At=cntat[d]-cntat[c-1];
        int Bt=cntbt[d]-cntbt[c-1];
        if(((2*As+Bs)%3)==((2*At+Bt)%3))
        {
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    return 0;
}
