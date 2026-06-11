#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
#define mod 1000000007
int main(){
	fast;
	int n,m,l;
	cin>>n>>m>>l;
	cout<<n+m+l-max({n,m,l});
	return 0;
}

