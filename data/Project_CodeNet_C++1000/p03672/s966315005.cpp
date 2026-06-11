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
	string s;
	int len=0;
	cin>>s;
	while(1){
		s=s.substr(0,s.length()-2);
		if(s.substr(0,s.length()/2)==s.substr(s.length()/2,s.length())){
			cout<<s.length();
			return 0;
		}
	}
}

