///Bismillahir Rahmanir Rahim
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

string s;
int sz;
int yo(char ch)
{
    int tmp=sz-1;
    string magic=s;
   // cout<<ch<<" # # # "<<endl;
   int ret=0;
    while(tmp--)
    {
         string past=magic;
         //cout<<magic<<"#"<<endl;
         magic="";
         int len=past.size()-1;
         f(i,0,len-1)
         {
             if(past[i]==ch || past[i+1]==ch)
             {
                 magic+=ch;
             }
             else magic+=past[i];
         }
         ret++;
         int flag=0;
         f(i,0,len-1)
         {
            if(magic[i]!=ch)flag=1;
         }
         if(flag==0)return ret;
    }
    if(magic[0]!=ch)return inf;
    return ret;
}
 main()

{
    fast
    cin>>s;
    sz=s.size();
    set<char>chk;
    for(auto ch:s)chk.insert(ch);
    if(chk.size()==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int ses=sz-1;
    for(char ch='a';ch<='z';ch++)
    {
         ses=min(ses,yo(ch));
    }
    cout<<ses<<endl;
    return 0;

}












