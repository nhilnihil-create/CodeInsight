#include <iostream>
using namespace std;

int main()
{
   int n, t[110], m, p, tt, sum=0, temp=0;
   cin >> n;
   for(int i = 0; i < n; i++)
   {
       cin >> t[i];
       sum+=t[i];
   }
   cin >> m;
   while(m--)
   {
       cin >> p >> tt;
       temp=sum;
       temp-=t[p-1];
       temp+=tt;
       cout << temp << endl;
   }
}
