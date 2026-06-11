/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

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
    ll i,j,a=-1,b=-1,c,x,y,z,n,m,t;
    cin>>n;
    set<ll>st;
    map<ll,ll>freq;
    for(i=0;i<n;i++)
    {
        cin>>m;
        st.insert(m);
        freq[m]++;
    }
    ll area=0;
    vector<ll>vec;
    for(auto p=st.rbegin();p!=st.rend();p++)
    {
        if(freq[*p]>=2)
        {
            vec.pb(*p);
        }
        if(vec.size()==2)
        {
            break;
        }
    }
    if(vec.size()==1)
    {
        a=vec[0];
        x=freq[a];
        if(x>=4)
        {
            area=a*a;
        }
        else
        {
            area=0;
        }
    }
    else if(vec.size()==2)
    {
        a=vec[0];
        b=vec[1];
        x=freq[a];
        y=freq[b];

        if(x>=4)
        {
            area=max(area,(a*a));
        }
        else
        {
            if(x>=2&&y>=2)
            {
                area=max(area,(a*b));
            }
            else
            {
                area=0;
            }
        }
    }
    else
    {
        area=0;
    }
    cout<<area<<endl;
    return 0;



//...........................................  ٱلْحَمْدُ لِلَّٰهِ‎  ...........................................................
}

