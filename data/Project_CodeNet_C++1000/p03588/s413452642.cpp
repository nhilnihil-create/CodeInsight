#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
	int N;
	cin>>N;
	vector<int>A(N);
	vector<int>B(N);
	rep(i,N){
		cin>>A.at(i)>>B.at(i);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	/*rep(i,N){
		cout<<A.at(i)<<" "<<B.at(i)<<endl;
	}*/
	cout<<(A.at(0)-1)+(A.at(N-1)-A.at(0)+1)+B.at(0);
return 0;}

/*compile
g++ code.cpp
./a.out
run*/