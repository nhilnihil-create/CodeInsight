#include <bits/stdc++.h>
#define ll  long long int
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    fast;
   
  
    ll a,b,c,x=0,y=0;
    cin>>a>>b>>c;

    if(a==5)
        x++;
    else if(a==7)
        y++;
    if(b==5)
        x++;
    else if(b==7)
        y++;
    if(c==5)
        x++;
    else if(c==7)
        y++;
    if(x==2&&y==1)
        cout<<"YES\n";
    else cout<<"NO\n";




}

