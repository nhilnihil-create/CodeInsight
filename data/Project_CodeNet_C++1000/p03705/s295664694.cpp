#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int64_t N,A,B;
   cin>>N>>A>>B;
   if(N==1&&A!=B){cout<<0<<endl;return 0;}
   else if(A>B){cout<<0<<endl;return 0;}
   cout<<(N-1)*B+A-((N-1)*A+B)+1<<endl;
return 0;}