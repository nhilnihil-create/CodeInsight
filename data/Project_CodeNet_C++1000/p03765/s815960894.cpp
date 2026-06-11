#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define modd 998244353
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define ar array
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld n,m;
lld arr[300000];
lld pref[300000];
ar<lld,2> cou1[300000],cou2[300000];
string st,tt;
int main()
{
     ios;
     lld TESTS,q,a,s,b,r,l,k,c,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
  // cin>>TESTS;
     while(TESTS--)
     {
         cin>>st>>tt;
         n=st.size();m=tt.size();
         cou1[0][0]=(0);
         cou1[0][1]=(0);
         cou2[0][0]=(0);
         cou2[0][1]=(0);
         rep(i,1,n){
            cou1[i]=cou1[i-1];
            cou1[i][st[i-1]-'A']++;
         }
         rep(i,1,m){
            cou2[i]=cou2[i-1];
            cou2[i][tt[i-1]-'A']++;
         }
         cin>>q;
         while(q--){
            cin>>a>>b>>c>>d;
            //a--;b--;c--;d--;
            x=(cou1[b][0]-cou1[a-1][0]-cou2[d][0]+cou2[c-1][0]);
            y=(cou1[b][1]-cou1[a-1][1]-cou2[d][1]+cou2[c-1][1]);
            //cout<<cou1[b][0]-cou1[a-1][0]-cou2[d][0]+cou2[c-1][0]<<" "<<cou1[b][1]-cou1[a-1][1]-cou2[d][1]+cou2[c-1][1]<<" ";
            a=abs(x);b=abs(y);
            if (x*y<0){((a%3+b%3)%3)?cout<<"NO\n":cout<<"YES\n";}
            else {(a%3==b%3)?cout<<"YES\n":cout<<"NO\n";}
         }
     }
    return 0;
}
