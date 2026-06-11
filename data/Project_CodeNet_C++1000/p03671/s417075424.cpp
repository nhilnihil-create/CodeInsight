#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main(){
	vector<int> v(3);
	rep(i,3) cin>>v[i];
	sort(all(v));
	cout<<v[0]+v[1]<<endl;
}