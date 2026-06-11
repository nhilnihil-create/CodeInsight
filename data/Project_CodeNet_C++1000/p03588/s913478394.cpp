#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<28;


void solve(int a) { cout << (a ? "You can win" : "You will lose") << endl; }
int main(){
	int n;
	cin >>n;
	map<int,int>data;//at,point
	long long ans=0;
	int bef1;
	int bef2;
	auto itr=data.begin();
	for(int i=0;i<n;i++){
		cin >>bef1>>bef2;
		data[bef2]+=0;
		data[bef2]+=bef1;
	}
	itr=data.begin();
	//itr--;
	//for(auto itr=data.begin();itr!=data.end();itr++){
	//	cout <<(itr->first)<<"    "<<(itr->second)<<endl; 
	//}
	ans+=(long long)(itr->second);
	//cout<<ans<<endl;
	ans +=(long long)(itr->first);
	
	cout<<ans<<endl;
}