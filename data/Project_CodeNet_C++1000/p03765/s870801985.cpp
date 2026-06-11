#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORE(it,v) for(__typeof((v).begin() it=(v).begin();it!=(v).end();i++)
#define IN(v) cerr<<v<<endl
#define SET(a,x) memset((a),(x),sizeof(a))
#define mod 1000000000

#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;

typedef pair<int,int> ii;

typedef pair<ll,int> lii;


const int N=1000005;

string st[3];
int q;
int u,v,x,y;
int sa[3][N],sb[3][N];

int tinha(int bit,int u,int v)
{
    return sa[bit][v]-sa[bit][u-1];
}
int tinhb(int bit,int u,int v)
{
    return sb[bit][v]-sb[bit][u-1];
}

int main()
{


   if (fopen("text.inp","r"))
   {
      freopen("text.inp","r",stdin);
      freopen("text.out","w",stdout);
   }
   else
   {
    //freopen("FENCE1.INP","r",stdin);
    //freopen("FENCE1.OUT","w",stdout);
   }

   getline(cin,st[1]);
   getline(cin,st[2]);
   int len[3];
   len[1]=st[1].length();
   len[2]=st[2].length();
   int len1=st[1].length(),len2=st[2].length();
   st[1]=" "+st[1];
   st[2]=" "+st[2];
   FOR(h,1,2)
    FOR(i,1,len[h])
    {
       sa[h][i]=sa[h][i-1]+(st[h][i]=='A');
       sb[h][i]=sb[h][i-1]+(st[h][i]=='B');

    }
   cin>>q;

   FOR(i,1,q)
   {
       cin>>u>>v>>x>>y;
       int dema=tinha(1,u,v)+tinhb(1,u,v)*2-tinhb(2,x,y)*2;
       dema-=tinha(2,x,y);
       dema=dema+30000000;
      // cerr<<tinha(1,u,v)<<" "<<tinhb(1,u,v)<<" "<<tinhb(2,x,y)<<endl;
       if(dema>=0 && dema%3==0)  cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
   }


}













