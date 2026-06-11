///Bismillahir Rahamanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}


 main()

{
    fast
    string a;
    cin>>a;
    int sz=a.size();
    set<pi>s;
    set<int>ase;
    set<int>::iterator hi,lo;
    f(i,0,sz-1)ase.insert(i);
    f(i,0,sz-2)
   {
       if(a[i]=='S' && a[i+1]=='T')
       {
           s.insert(mp(i,i+1));
       }
   }
   int ses=0;
   while(!s.empty())
   {

        pi yo=*s.begin();
        s.erase(s.begin());
        int bam,dan;
        int idx=yo.fi;
        ase.erase(idx);
        ase.erase(yo.si);
        ses+=2;
        hi=ase.upper_bound(idx);
        if(hi==ase.end() || hi==ase.begin())continue;
        lo=hi;
        lo--;
        bam=*lo;
        dan=*hi;
        if(a[bam]=='S' && a[dan]=='T')
        {
            s.insert(mp(bam,dan));
        }
   }

   ses=sz-ses;
   cout<<ses<<endl;
    return 0;

}











