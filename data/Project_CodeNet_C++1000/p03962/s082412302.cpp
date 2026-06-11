#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   set <int, greater <int> > s;
   s.insert(a);
   s.insert(b);
   s.insert(c);
   int ans;
   ans = s.size();
   cout<<ans<<endl;
}
