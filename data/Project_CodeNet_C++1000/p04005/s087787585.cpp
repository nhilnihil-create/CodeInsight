#include <bits/stdc++.h>
using namespace std;
std::vector<long long int> v;
int main() {
     long long int a=0;
	for(long long int i=0;i<3;i+=1){
	     long long int x;
	     cin >> x;
	     if(x%2==0){
	          a=1;
	     }
	     v.push_back(x);
	}
	if(a==1){
	     cout << 0;
	}
	else{
	     sort(v.begin(),v.end());
	     cout << v[0]*v[1];
	}
	return 0;
}
