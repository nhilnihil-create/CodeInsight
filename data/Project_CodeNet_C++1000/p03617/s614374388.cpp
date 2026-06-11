#include <bits/stdc++.h> 
using namespace std;
bool comp(long long a, long long b) 
{ 
    return (a < b); 
} 
int main()
{
    long long q,h,s,d,n,m;
    cin>>q>>h>>s>>d>>n;
    if(n==1)
    {
        cout<<std::min({s,2*h,4*q}, comp)<<endl;
    }
 else
    {
        m=std::min({d/2,s,2*h,4*q}, comp);
        if(m==d/2)
        {
            if(n%2==1)
            {long long t=((n-1)*d)/2 +(std::min({s,2*h,4*q}, comp));
            cout<<t<<endl;}
            else
           { long long t=(n*d)/2;
            cout<<t<<endl;}
        }
        else if(m==s)
        {long long t=n*m;
        cout<<t<<endl;}
        else if(m==2*h)
        {long long t=n*m;
        cout<<t<<endl;}
        else
        {long long t=n*m;
        cout<<t<<endl;}
    }
	return 0;
}