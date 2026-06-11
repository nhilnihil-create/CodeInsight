////////////////////////// Author
////////////////////////// Nasim Hossain Rabbi
////////////////////////// JU-CSE28
////////////////////////// CF - imnasim3.1415
////////////////////////// UVA - imnasim3.1415
////////////////////////// Mail - imnasim3.1415@gmail.com

#include<bits/stdc++.h>
using namespace std;
#define sz size()
#define mk make_pair
#define clr clear()
#define B begin()
#define E end()
#define EM empty()
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,n) for(i=1;i<=n;i++)
#define all(cont) cont.begin(),cont.end()
#define pb push_back
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi 3.1415926535897932384626433832795
#define vi vector<int>
#define vs vector<string>
#define vp(vi,x) cin>>x; vi.pb(x);
typedef long long int LL;
typedef unsigned long long int ULL;
int main()
{
//    fast;
    int i,j,k,n,m,l,s=0,x,y,tc=1;
    while(cin>>n)
    {
        vi a;
        int f=0,t=0,tn=0,o=0, c=0;
        rep(i,n)
        {
            cin>>x;
            a.pb(x);
            c++;
            if(x%4==0)
                f++;
            else if(x%2==0)
                t++;
        }
        if(f>=(n/2)) cout<<"Yes"<<endl;
        else if((t/2)+f>=(n/2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

