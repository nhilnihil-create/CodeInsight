#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ll a,b,c;
cin >> a >> b >> c;
//a += b ;
//a += c;
if(a==b+c || b==a+c || c ==a+b)
    cout << "Yes" << endl;
else cout << "No" << endl;

  }
