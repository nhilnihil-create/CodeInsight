    #include <bits/stdc++.h>

    #define int long long
    #define ci(m)     for(int i=0;i<m;i++)
    #define cj(m)     for(int j=0;j<m;j++)
    #define ck(m)     for(int k=0;k<m;k++)
    #define gcd            __gcd
    #define endl           "\n"
    #define pb             emplace_back
    #define setbits(x)     __builtin_popcountll(x)
    #define zrobits(x)     __builtin_ctzll(x)
    #define mod            1000000007
    #define mod2           998244353
    #define maxe           *max_element
    #define mine           *min_element
    #define inf            1e18
    #define deci(x, y)      fixed<<setprecision(y)<<x
    #define w(t)           int t; cin>>t; while(t--)
    #define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
    #define PI             3.141592653589793238
    using namespace std;
    vector<int>v[100000];
    int col[100000];
    int dp[100000][11];
    int n,m;
    int32_t main() {
        nitin;
        cin>>n>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            --a;
            --b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int t;
        cin>>t;
        vector<vector<int>>queries;
        for(int i=0;i<t;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            queries.push_back({a,b,c});
        }
        while(t--)
        {
            int node,dist,color;
            node=queries[t][0];
            dist=queries[t][1];
            color=queries[t][2];
            node--;
            queue<int>q;
            q.push(node);
            unordered_map<int,bool>m;
            m[node]=true;
            if(col[node]==0)
            col[node]=color;
            dp[node][dist]=1;
            while(dist--)
            {
                queue<int>nq;
                while(!q.empty())
                {
                    int vert=q.front();
                    q.pop();
                    for(auto c:v[vert])
                    {
                        if(!m[c] && !dp[c][dist])
                        {
                            nq.push(c);
                            if(col[c]==0)
                            col[c]=color;
                            dp[c][dist]=1;
                            m[c]=true;
                        }
                    }
                }
                q=nq;
                if(q.empty())
                    break;
            }

        }
        for(int i=0;i<n;i++)
            cout<<col[i]<<" ";
        cout<<endl;
        return 0;
    }