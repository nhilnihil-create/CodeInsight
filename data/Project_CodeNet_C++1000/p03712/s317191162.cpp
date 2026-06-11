#include <bits/stdc++.h>
using namespace std;
string s[10010];
int h,w;
int main() {
cin>>h>>w;
for(int i=0;i<h;i++) {
	cin>>s[i];
}
for(int i=0;i<w+2;i++) {
	cout<<"#";
}
for(int i=0;i<h;i++) {
	cout<<endl<<"#"<<s[i]<<"#";
}
cout<<endl;
for(int i=0;i<w+2;i++) {
	cout<<"#";
}
}
