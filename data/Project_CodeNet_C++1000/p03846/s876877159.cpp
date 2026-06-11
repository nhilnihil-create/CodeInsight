/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
lli power(int x)
{
    lli ans=1ll,p=2ll;
    while(x)
    {
        if(x&1)
            ans=ans*p%MOD;
        p=p*p%MOD;
        x>>=1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,x=0;bool flag=false;lli res=0ll;
    cin>>n;
    map<int, int> m;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        ++m[x];
    }
    if(n&1)
    {
        if(m[0]>1)
            flag=true;
        else
        {
            for(int i=1;i<n;++i)
            {
                if(m[i]>2||m[i]==1)
                    flag=true;
                if(flag)
                    break;
            }
        }
        if(!flag)
            res=power(n/2);
    }
    else
    {
        if(m[0]>0)
            flag=true;
        else
        {
            for(int i=1;i<n;++i)
            {
                if(m[i]>2||m[i]==1)
                    flag=true;
                if(flag)
                    break;
            }
        }
        if(!flag)
            res=power(n/2);
    }
    if(flag)
        cout<<"0";
    else
        cout<<res;
    cout<<endl;
}