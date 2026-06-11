#include<bits/stdc++.h>
using namespace std;
int len;
string a,b,c;
int main() {
    cin>>a;
	len=a.length();
    for(int i=len-1;i>=0;i--)
		b=b+a[i];
    for(int i=0;i<len;i++){
        if(b[i]=='b')
			c=c+'d';
        if(b[i]=='d')
			c=c+'b';
        if(b[i]=='p')
			c=c+'q';
        if(b[i]=='q')
			c=c+'p';
    }
    if(a==c)
		printf("Yes\n");
    else 
		printf("No\n");
    return 0;
}