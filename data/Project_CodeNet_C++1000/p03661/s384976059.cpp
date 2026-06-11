#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define DL double
#define MLL map<LL,LL>::iterator
#define MSL map<string,L>::iterator
#define MLS map<LL,string>::iterator
#define MSS map<string,string>::iterator
#define MCL map<char,LL>::iterator
#define SL set<LL>::iterator
#define SS set<string>::iterator sl
#define G getline
#define SZ size()
#define IN insert
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
V<LL>u,v,w;
int main()
{
    FAST;
    LL n,m,i,j,k,p,q,o,l,s,t,z;
    cin>>n;
    k=0;
    for(i=0; i<n; i++)
    {
        cin>>o;
        k+=o;
        v.PSB(k);
    }
    s=v[n-1];
    k=999999999999999999999999;
     for(i=0; i<n-1; i++)
    {
        l=s-v[i];
        k=min(k,abs(v[i]-l));
    }
    cout<<k<<endl;



    return 0;

}
