#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define fo(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    ll n,i,j,k,t;

    ll c=10;i=0;
    string s;
    cout<<"? "<<c<<endl;
    fflush(stdout);
    cin>>s;

    while(s=="Y")
    {
        c*=10;
        if(c>1000000000)
            break;
        i++;
        cout<<"? "<<c<<endl;
        fflush(stdout);
        cin>>s;
    }

    if(c>1000000000)
    {
        c=1;i=9;
        while(true)
        {
            cout<<"? "<<i<<endl;
            fflush(stdout);
            cin>>s;
            if(s=="Y")
                break;
            else
            {
                c*=10;
                i=i*10+9;
            }
            if(c>1000000000)
            {
                c=1;
                break;
            }
        }
        cout<<"! "<<c<<endl;
        fflush(stdout);
        return 0;
    }

    c=0;ll l,r,mid;
    fo(j,i)
    {
        l=0;r=10;
        while(l<r-1)
        {
            mid=(l+r)>>1;
            if(j==i)
                cout<<"? "<<c*100+mid*10<<endl;
            else
                cout<<"? "<<c*10+mid<<endl;
            fflush(stdout);
            cin>>s;
            if(s=="Y")
                l=mid;
            else
                r=mid;
        }
        c=c*10+l;
    }

    l=0;r=10;
    while(l<r-1)
    {
        mid=(l+r)>>1;
        cout<<"? "<<c*100+mid*10<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="N")
            l=mid;
        else
            r=mid;
    }

    c=c*10+l+1;

    cout<<"! "<<c;
    fflush(stdout);
    return 0;
}
