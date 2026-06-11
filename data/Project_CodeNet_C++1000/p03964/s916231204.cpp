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
#define SS set<string>::iterator
#define VL V<LL>::iterator
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
#define MAX 1e18
#define MIN -1e18
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
V<LL>v;
map<LL,LL>u;
int main()
{
    LL n,m,i,j,k,p,q,o,l,s,t,z=0,r;
    cin>>t;
    p=0;
    q=0;
    k=0;
    while(t--)
    {
        cin>>n>>m;
        if(p==0 && q==0)
        {
            p=n;
            q=m;

        }
        else
        {
            DL x,y;
            x=(DL)n/(DL)p;
            y=(DL)m/(DL)q;
            if(x>=y)
            {
                l=q/m;
                if(q%m!=0)
                {
                    l++;
                }
                q=l*m;
                p=l*n;
            }
            else
            {
                l=p/n;
                if(p%n!=0)
                {
                    l++;
                }
                p=l*n;
                q=l*m;
            }
        }
//        cout<<p<<" "<<q<<endl;
    }
    cout<<p+q<<endl;
    return 0;
}
