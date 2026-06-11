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
int main(){
	fast;
	int x,a,b;
	cin>>x>>a>>b;
	if(b<=a)
		cout<<"delicious";
	else if(b-a<=x)
		cout<<"safe";
	else
		cout<<"dangerous";
	return 0;
}

