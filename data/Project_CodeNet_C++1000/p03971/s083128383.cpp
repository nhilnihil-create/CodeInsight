#include<bits/stdc++.h>
 
#define lli long long int
#define endl "\n"
 
using namespace std;
 
typedef long long int LLI;
typedef double DB;
 
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
 
bool comparator(pair<lli,lli> a,pair<lli,lli> b)
{
    if(a.first>b.first)
        return true;
    else if (a.first==b.second)
    {
        if(a.second>=b.second)
            return false;
        return true;
    }
    return false;
}
 
int mods(int x)
{
    if(x>0)
        return x;
    return -x;
}
 
lli gcd(lli a,lli b)
{
    return __gcd(a,b);
}
 
lli lcm(lli x,lli y,lli z)
{
    lli j=gcd(x,y);
    lli k=gcd(y*x/j,z);
    return (((x*y)/j)*z)/k;
} 
 
int main()
{
    fastio();
    int n,a,b; cin>>n>>a>>b; int arr[n]={0};
    int k=0,countb=0; string s; cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a' && k<a+b) {++k; arr[i]=1;}
        if(s[i]=='b' && k<a+b && countb<b) {++k; ++countb; arr[i]=1;}
    }
    for(int i=0;i<n;i++)
    {
        string sd=(arr[i]==1)?"Yes":"No"; cout<<sd<<endl;
    }
    return 0;
}