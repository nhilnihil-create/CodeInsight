#include <bits/stdc++.h>
using namespace std;
bool cmp(string s1 , string s2)
{
    string temp1 = s1 + s2;
    string temp2 = s2 + s1;
    return temp1 < temp2;
}

int main()
{
   int n , l;
   cin>>n>>l;
   
   std::vector<string> v;
   for(int i = 0;i<n;i++)
   {
       string s;
       cin>>s;
       v.push_back(s);
   }
   sort(v.begin() , v.end() ,cmp);
   
   string res = "";
   for(auto it : v)
   res += it;
   
   cout<<res<<"\n";
        
    return  0;
}