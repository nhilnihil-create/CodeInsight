#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
     ll w , a , b;
     cin >> w >> a >> b;
     ll ar = a+w ;
     ll br = b+w ;
     if(ar<=b)
     {
         cout << b - ar << endl;
     }
     else if(ar>=b && ar<=br || a>=b && a<=br)
     {
         cout << 0 << endl;
     }
     else if(a>=br)
     {
         cout << a-br << endl;
     }
}
