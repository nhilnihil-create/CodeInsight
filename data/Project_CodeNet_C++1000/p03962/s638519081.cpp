#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int a,b,c;
   cin>>a>>b>>c;
   set<int>K;
   K.insert(a);
   K.insert(b);
   K.insert(c);
   cout<<K.size()<<endl;
return 0;}