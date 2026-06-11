#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 int main() {
	int A,B;
   cin>>A>>B;
   int sum=A+B;
   if(sum%3==0){cout<<"Possible";}
   else if(A%3==0){cout<<"Possible";}
   else if(B%3==0){cout<<"Possible";}
   else{cout<<"Impossible";}
	}