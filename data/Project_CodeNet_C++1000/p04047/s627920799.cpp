#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;

void PV(vector<int> pvv) {
	rep(i, (int)pvv.size()) cout << pvv[i] SP;
	cout << endl;
}

int main(){

	int n;
  	LLi ans=0;
  	vector<int> v;
	cin>> n;
  	n*=2;
  	
  	v.resize(n);
  	rep(i, n) cin>> v[i];
	sort(v.begin(), v.end(), greater<int>());
  //PV(v);
  	for(int i=0;i<2*n-1;i+=2) ans+=min(v[i], v[i+1]);
  
  	cout<< ans <<endl;

	return 0;
}
