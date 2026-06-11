#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n;
    string s;
    cin>>n;
    ll x,y,maxInX=INT_MIN,YforX;
   for(i=0;i<n;i++)
    {
        cin>>x>>y;
        if(x>=maxInX){
            maxInX=x;
            YforX=y;
        }
    }
    cout<<maxInX+YforX<<endl;






    return 0;
}



