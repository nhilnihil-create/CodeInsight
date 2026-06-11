                #include<bits/stdc++.h>
                #define ll long long
                #define f   first
                #define s   second
                #define pb          push_back
                #define mod        1000000007
                #define mod1       1000000009
                #define hell        998244353
                #define inf         1000000000000000000LL
                #define pi          3.14159265358979323
                //#define N           100005 
                const int N=200005;
                using namespace std;
                ll n,k,sum,q,res,m,val,ans;
                ll x,y;
                ll xx[]={1,0,-1,0};
                ll yy[]={0,1,0,-1};
                ll cnt[1000005];  
                void solve()    
                {   
                    string s;
                    cin>>s;
                    char a='Z';
                    n=s.size();
                    ll cnt[26]={0};
                    for(int i=0;i<n;i++)
                    {
                        cnt[s[i]-'a']++;
                    } 
                    for(int i=0;i<26;i++) if(cnt[i]==0) {a=char(i+'a');break;}
                    if(a=='Z') cout<<"None";
                else cout<<a;



                }   
                int main()
                {   ios_base::sync_with_stdio(false);
                    cin.tie(0);cout.tie(0);
                    ll t=1; 
                   //cin>>t;
                     for(ll i=1;i<=t;i++)
                        solve();
                }            