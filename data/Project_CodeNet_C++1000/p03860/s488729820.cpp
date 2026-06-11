#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>
//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	vs A(3);
	for(auto &x:A)cin>>x;
	string s=A[0], s1=A[1], s2=A[2];
	cout<<s[0] <<s1[0] <<s2[0] <<"\n";
}
