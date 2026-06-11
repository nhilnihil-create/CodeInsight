#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll n,k;
   cin>>n>>k;
   map<ll , ll > m;
   for(int i=0;i<n;i++)
   {
       ll temp , count;
       cin>>temp >> count;
       m [temp  ] += count;
   }
   map<ll , ll> ::iterator  it = m.begin();

   ll index = 0;

   for( it = m.begin() ; it!= m.end() ;it++)
   {
//       cout<<it->first<<" "<<it->second<<endl;
//       cout<<"index is "<<index<<endl;
       if( index < k && (index + it->second ) >= k   ) {
           cout << it->first;

       }
       index += it->second;
   }

}