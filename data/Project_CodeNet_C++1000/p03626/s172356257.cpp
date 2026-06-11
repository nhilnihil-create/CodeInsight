
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n;
    string s,ss;
    cin>>s>>ss;
    f=1;g=0;
    for(i=0; i<n; i++)
    {
        if(s[i]==ss[i]){
            if(i==0){
                f*=3;
            }
            else if(!g){
                f*=2;
            }
            g=0;
            f%=pi;
        }
        else{
            if(i==0){
                f*=2*3;
            }
            else if(!g){
                f*=2;
            }
            else f*=3;
            i++;
            g=1;
            f%=pi;
        }
    }
    cout<<f<<'\n';
    return 0;
}
