#include<iostream>
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define line cout<<"here - "<<__LINE__<<"\n";
#define dbg(a) cout<<#a<<" --> "<<(a)<<"\n";
#define infi INT_MAX
#define rinfi INT_MIN
#define inf LLONG_MAX
#define rinf LLONG_MIN
#define ff first
#define ss second
using namespace std;
main()
{
    //fast
    int tc=1,i,j,k;
//    cin>>tc;
    while(tc--)
    {
      int a,b,x,y;
      cin>>a>>b>>x>>y;
     int ans=min(a,b)*x;
     if(a<=b)
        cout<<ans<<endl;
     else ans+=(a-b)*y, cout<<ans<<endl;

    }
}


