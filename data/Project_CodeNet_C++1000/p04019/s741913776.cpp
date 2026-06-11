#include <bits/stdc++.h>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){

    int N=0,W=0,S=0,E=0;
    string str;

    cin>>str;

    for(int i=0;i<str.length();i++){
        if(str[i]=='N')N=1;
        if(str[i]=='W')W=1;
        if(str[i]=='S')S=1;
        if(str[i]=='E')E=1;
    }

    if(N!=S||W!=E){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    return 0;
}