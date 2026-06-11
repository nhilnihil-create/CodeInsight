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
            #define N           1000050
            using namespace std;
            ll n,k,sum,q,res,m,val;
            ll x,y;
            void solve()    
            {   

                cin>>n>>m;
                vector<ll> v(n);
                for(int i=0;i<n;i++) cin>>v[i];
                for(int i=0;i<n-1;i++)
                {
                    if(v[i]+v[i+1]>=m)
                    {   cout<<"Possible\n";
                        for(int j=0;j<i;j++)
                            cout<<j+1<<"\n";
                        
                        for(int j=n-1;j>=(i+1);j--)
                            cout<<j<<"\n";
                        return;
                    }
                }
                cout<<"Impossible";









            }
            int main()
            {   ios_base::sync_with_stdio(false);
                cin.tie(0);cout.tie(0);
                ll t=1;
                //cin>>t;
                for(int i=1;i<=t;i++)
                    solve();
                

            }            