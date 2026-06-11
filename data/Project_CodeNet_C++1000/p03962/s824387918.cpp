#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int a, b, c;
  cin >> a >> b >> c;
  if (a==b && a!= c && b!=c )
    {
    cout<<"2"<<endl;
    }
    else if (a==c && a!= b && c!=b )
    {
    cout<<"2"<<endl;
    }   
 else if (b==c && b!= a && c!=a )
    {
    cout<<"2"<<endl;
    }
     else if (a!=b && b!= c && a!=c )
     {
    cout<<"3"<<endl;
    }
     else if (a == b && b == c )
     {
    cout<<"1"<<endl;
    }
}
