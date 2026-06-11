#include <bits/stdc++.h>
#define rep(a,b) for(int a=0; a<b; ++a)
#define ran(a,b) for(auto &a:b)
#define all(v) v.begin(),v.end()
using namespace std;

template<typename T>
using pq = priority_queue<T>;
template<typename T>
using rpq = priority_queue<T,vector<T>,greater<T>>;
template<typename T>
using vec = vector<T>;

using ll = long long;
using pi = pair<int,int>;
using ti = tuple<int,int,int>;
using tup = tuple<string,int,int>;

ll MOD=1000000007;

int main(){
	int X; cin>>X;
	int t=-1; int sum=0;
	while(sum<X){
		++t;
		sum=t*(t+1)/2;
	}
	cout<<t<<endl;
}