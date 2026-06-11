#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,gray=0,brown=0,red=0,orange=0,light=0,blue=0,green=0,yellow=0,any=0,min=0,max=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x>=1&&x<=399)
            gray++;
        if(x>=400&&x<=799)
            brown++;
        if(x>=800&&x<=1199)
            green++;
        if(x>=1200&&x<=1599)
            light++;
        if(x>=1600&&x<=1999)
            blue++;
        if(x>=2000&&x<=2399)
            yellow++;
        if(x>=2400&&x<=2799)
            orange++;
        if(x>=2800&&x<=3199)
            red++;
        if(x>3199)
            any++;
    }
    if(gray!=0)min+=1;
    if(brown!=0)min+=1;
    if(green!=0)min+=1;
    if(light!=0)min+=1;
    if(blue!=0)min+=1;
    if(yellow!=0)min+=1;
    if(red!=0)min+=1;
    if(orange!=0)min+=1;
    max=min+any;
    if(min==0)min=1;
    cout<<min<<" "<<max<<endl;
	return 0;
}