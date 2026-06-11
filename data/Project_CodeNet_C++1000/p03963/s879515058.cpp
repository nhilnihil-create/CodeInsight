#include <bits/stdc++.h>
#define ll long long
#define ch char
#define st string
using namespace std;
ll a,b,c,d,e,f,g,h;
void Urvatullo_Atoev()
{
    cin>>a>>b;
    c=pow(b-1,a-1);
    if(a!=1)
    {
    	cout<<c*b<<endl;
    }
    else
    {
    	cout<<b<<endl;
    }
}
int main()
{
    Urvatullo_Atoev();
}
