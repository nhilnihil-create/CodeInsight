#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 int main() {
	int a,b,c;
   cin>>a>>b>>c;
   int max =a;
   if(b> max ) max =b;
   if(c> max ) max =c;

   cout<<a+b+c-max<<endl;
	}
