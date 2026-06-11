#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
string k;
int main(){
	cin>>k;
	set<ll>kl;
	for(char c:k) kl.insert(c);
	for(ll ia = 'a';ia<=ll('z');ia++) if(!kl.count(char(ia))){cout<<char(ia)<<'\n';return 0;}
	cout<<"None\n";
}