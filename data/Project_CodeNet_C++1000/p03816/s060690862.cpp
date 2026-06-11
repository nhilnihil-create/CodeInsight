#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
   int n;
   cin >> n;
   set<int> s;
   while(n--)
   {
       int a;
       cin >> a;
       s.insert(a);
   }

   if(s.size() % 2 == 0)
   {
       cout << s.size() - 1 << endl;
   }
   else
   {
       cout << s.size() << endl;
   }


}
