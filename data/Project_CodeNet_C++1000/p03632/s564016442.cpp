#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
   cin>>a>>b>>c>>d;
   int k=max(a,c);
  int t=min(b,d);
   if(t-k>0)cout<<t-k;
   else cout<<0;
	return 0;
}