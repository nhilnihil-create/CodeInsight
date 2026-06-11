#include<bits/stdc++.h>
using namespace std;
const  long long     mx=1e5+100;

#define      mod     1e9+7
#define      pai     acos(-1)
#define      ff      first
#define      ss      second
#define      ll      long long
#define      pb      push_back
#define      mp      make_pair
#define      fi      freopen("input.txt","r",stdin);
#define      fo      freopen("output.txt","w",stdout);
#define      fast    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

//typedef pair<ll,ll> pi;
//typedef map<ll,ll> mi;


int main()
{
    fast;
    ll i,j,a,b,c,d,n,m,k,x,y,t;
    string s;
    cin>>s;
    n=s.size();
    map<char,ll>frq;
    set<char>st;
    for(i=0;i<n;i++)
    {
        char ch = s[i];
        st.insert(ch);
        frq[ch]++;
    }
    bool ok=false;
    for(auto p: st)
    {
        if(frq[p]&1)
        {
            ok=true;
            break;
        }
    }
    if(ok)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;

}

