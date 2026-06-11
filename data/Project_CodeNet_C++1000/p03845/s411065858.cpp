/*
ID: Aditya Srivastava[yashsri2]
LANG: C++
TASK: test
*/
#include <bits/stdc++.h>
const double PI=acos(-1);
using namespace std;
#define ll long long
#define ull unsigned long long
#define ul unsigned long
#define FD(N,M) (cout<<fixed<<setprecision(M)<<(N))
#define pb push_back
#define pf push_front
#define MOD 1000000007
#define rep(i,n) for(ll i=0;i<(n);i++)
#define templ template<typename T>
ll findmin(ll a,ll b) {
    return a<b?a:b;
}
ll findmax(ll a,ll b) {
    return a>b?a:b;
}
int log2_fl(ll num) {
	int count=0;
	while(num>>=1) {
		count++;
	}
	return count;
}
// debugging
void printArr(ll *arr, ll n) {
	for(ll i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
templ void printVect(vector<T>& arr) {
	for(T i:arr) {
		cout<<i<<" ";
	}
	cout<<"\n";
}
templ void printVect2d(vector<vector<T>>& arr) {
	for(auto i:arr) {
		for(T j:i) {
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>n;
    long t[n];
    ll tt=0;
    for(int i=0;i<n;i++) {
		cin>>t[i];
		tt+=t[i];
	}
	cin>>m;
	int p;long x;
	while(m--) {
		cin>>p>>x;
		cout<<(tt-t[p-1]+x)<<"\n";
	}
    cout.flush();
	return 0;
}
