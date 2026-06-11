#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N;
	cin>>N;
	vector<int>a(N);
	rep(i,N){
		cin>>a.at(i);
	}
	int ans=0;
	rep(i,N){
		if(a.at(a.at(i)-1)==i+1){
			ans++;
		}
	}
	cout<<ans/2;
return 0;}

/*compile
g++ code.cpp
./a.out
run*/