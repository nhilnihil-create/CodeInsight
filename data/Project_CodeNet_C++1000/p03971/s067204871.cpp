#include "bits/stdc++.h" 
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
    ll n,a,b,cnt=0,b_rank=0;
    string s;
    cin>>n>>a>>b;
    cin>>s;
    cout<<endl;
    REP(i,0,s.length()-1)
    {
        if(s[i]=='a')
        {   
            if(cnt<(a+b))
            {
                cout<<"Yes"<<endl;
                cnt++;
            }
            else
                cout<<"No"<<endl;                  
        }
        else if(s[i]=='b')
        {   
            if(b_rank<b && cnt<(a+b))
            {
                cout<<"Yes"<<endl;
                cnt++;
                b_rank++;
            }
            else
                cout<<"No"<<endl;                    
        }
        else if(s[i]=='c')
            cout<<"No"<<endl;        
    }     
}