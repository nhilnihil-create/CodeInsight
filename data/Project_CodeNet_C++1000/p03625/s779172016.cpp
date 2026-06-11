#include<bits/stdc++.h>
#define  ll  long long int
#define  sz  200010

using namespace std;


ll num[sz];
map<ll,ll>cnt;
set<ll>st;
set<ll>::iterator it;


int main()
{

    ll n,i,j,k,p,d,m,a,x,ar;
    ll c=0;

    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>num[i];
        st.insert(num[i]);
        cnt[num[i]]++;

    }

    priority_queue<ll>q;
    ar=1;
    i=1;
    n=st.size();

    for(it=st.begin(); it!=st.end(); it++)
    {
        a=*it;
     //   cout<<a<<endl;
        num[i]=a;
        i++;

    }



    for(i=n;i>=1;i--)
    {
        a=num[i];


        if(cnt[a]>=2)
        {
            c++;
            ar=ar*a;
            if(c==2){q.push(ar);
            break;}

        }
        if(cnt[a]>=4)
        {
            q.push(a*a);
        }
    }

    m=q.size();
    if(m==0)cout<<0<<endl;
    else
    {
        m=q.top();
        cout<<m<<endl;
    }

    return 0;
}
