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

    int N,A,o=0,e=0;
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>A;
        if(A%2==0){
            e++;
        }else{
            o++;
        }
    }

    while(o>=2){
        o-=2;
        e++;
    }

    if(o==1){
        cout<<"NO"<<endl;
        return 0;
    }

    while(e>=2){
        e-=2;
        e++;
    }

    if(e==1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}