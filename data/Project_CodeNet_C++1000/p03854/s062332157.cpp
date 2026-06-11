#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
   string s;
   cin >> s;
   bool solve = 0;
   bool c = 1;
   while(c)
   {
       if(s.size() == 0)
       {
           solve = 1;
           break;
       }
       c = 0;
       if(s.size() >= 11 && s.substr(0, 11) == "dreameraser")
       {
           s.erase(0, 11);
           c = 1;
       }
       else if(s.size() >= 10 && s.substr(0, 10) == "dreamerase")
       {
           s.erase(0, 10);
           c = 1;
       }
       else if(s.size() >= 7 && s.substr(0, 7) == "dreamer")
       {
           s.erase(0, 7);
           c = 1;
       }
       else if(s.size() >= 5 && s.substr(0, 5) == "dream")
       {
           s.erase(0, 5);
           c = 1;
       }
       else if(s.size() >= 6 && s.substr(0, 6) == "eraser")
       {
           s.erase(0, 6);
           c = 1;
       }
       else if(s.size() >= 5 && s.substr(0, 5) == "erase")
       {
           s.erase(0, 5);
           c = 1;
       }
   }

   if(solve)
   {
       cout << "YES" << endl;
   }
   else
   {
       cout << "NO" << endl;
   }
}
