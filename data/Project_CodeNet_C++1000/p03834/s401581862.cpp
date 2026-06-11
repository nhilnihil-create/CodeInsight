#include <bits/stdc++.h>
#include <string>
using namespace std;

string a,b=" ";

int main(){
	cin>>a;
	a.erase(5,1);
	a.insert(5,b);
	a.erase(13,1);
	a.insert(13,b);
	cout<<a<<endl;
}