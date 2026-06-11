#include<bits/stdc++.h>
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{

long long a,b,c,d,e,f,x,y,n,h=0,k;
    cin >> n >> k >> x >> y;

    if(n<k)
    {
        f=n*x;
        cout << f << endl;
    }
    else{

       d=k*x+max((n-k)*y,h);
    cout << d << endl;

    }






}