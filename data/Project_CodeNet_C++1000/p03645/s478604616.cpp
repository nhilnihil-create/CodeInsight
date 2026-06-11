//-- In The Name of God --
#include<bits/stdc++.h>
using namespace std;


#define      mod     1e9+7
#define      pai     acos(-1)
#define      ff      first
#define      ss      second
#define      ll      long long
#define      pb      push_back
#define      mp      make_pair
#define      endl    "\n"
#define      fii     freopen("input.txt","r",stdin);
#define      foo     freopen("output.txt","w",stdout);
#define      fast    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const   ll   mx=1e6+10;
bool visited[mx];
int main()
{
    fast;
    ll i,j,a,b,c,d,n,m,t;
    cin>>n>>m;
    vector<ll>vec1,vec2;

    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(a==1||b==1)
        {
            if(a==1)
            {
                vec1.pb(b);
            }
            else
            {
                vec1.pb(a);
            }
        }
        if(a==n||b==n)
        {
            if(a==n)
            {
                vec2.pb(b);
                visited[b]=true;
            }
            else
            {
                vec2.pb(a);
                visited[a]=true;
            }
        }
    }
    if(vec1.size()==0||vec2.size()==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(auto it:vec1)
        {
            if(visited[it])
            {
                cout<<"POSSIBLE"<<endl;
                return 0;
            }
        }
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    return 0;
}

