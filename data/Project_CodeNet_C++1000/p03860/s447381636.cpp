#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i;
 	string s[3],s1;
 	s1.erase();
 	for(i=0;i<3;i++)
 		cin>>s[i];
 	s1+=s[0][0];
 	s1+=s[1][0];
 	s1+=s[2][0];
 	
 	cout<<s1<<endl;
 }