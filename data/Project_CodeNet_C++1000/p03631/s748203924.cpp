#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    string s=to_string(n);
    string k=s;
    reverse(s.begin(),s.end());
    k==s?cout<<"Yes":cout<<"No";
	return 0;
}