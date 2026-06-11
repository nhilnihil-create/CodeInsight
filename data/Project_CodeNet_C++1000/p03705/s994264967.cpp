#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 	 int64_t N,A,B;
   cin>>N>>A>>B;
   if(B<A){cout<<0<<endl;}
   else if(N==1){if(A!=B){cout<<0<<endl;}
                 else{cout<<1<<endl;}}
   else{
   cout<<(B-A)*(N-2)+1<<endl;
   }
	return 0;
}