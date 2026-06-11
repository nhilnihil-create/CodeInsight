        #include<bits/stdc++.h>
     
         
        using namespace std;
         
        #define N  1000000000;
    #define ll         long long
        vector<ll>adj[100005];
        std::vector<ll> vis;
        ll dfs(ll node)
        {
           
           ll ans=0;
           for(auto j:adj[node])
           {
            if(vis[j]==0)
            {
                vis[j]=1;
                ans^=(1+dfs(j));
            }
           }
           return ans;
         }
         int main()
        
       
        {
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            int TESTS=1;
           // cin>>TESTS;
             while(TESTS--)
            {
              ll n;
              cin>>n;
              for(ll i=0;i<n-1;i++)
              {
                ll a,b;
                cin>>a>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
              }
              vis=vector<ll>(n+2,0);
              vis[1]=1;
              if(dfs(1))
                cout<<"Alice"<<endl;
            else
                cout<<"Bob"<<endl;
            }
            return 0;
        }