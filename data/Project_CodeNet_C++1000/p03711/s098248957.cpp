#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,x,y,a[]= {1,3,5,7,8,10,12},b[]= {4,6,9,11};
    cin>>x>>y;
    bool fx=0,fy=0;
    for(i=0; i<7; i++)
    {
        if(a[i]==x)
            fx=1;
        else if(a[i]==y)
            fy=1;
    }
    if(fx==0||fy==0){
        fx=0;fy=0;
    }
    for(i=0; i<4; i++){
        if(b[i]==x) fx=1;
        if(b[i]==y) fy=1;
    }
    if(fx&&fy)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}



