#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
char s[maxn];
int main(){
	gets(s);
	cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<endl;
	return 0;
}