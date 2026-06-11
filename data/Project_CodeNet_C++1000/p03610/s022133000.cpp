#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
cin>>s;
for(int i=1;i<s.length();i++) {
	s.erase(i,1);
}
cout<<s<<endl;
}
