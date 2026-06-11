#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c; cin >> a >> b >>c;
  long long large = max(a,max(b,c));
  if(large % 2 == 0)
	cout << 0 << endl;
  else
   	cout << min(a * b,min(b * c,c*a)) << endl;
}