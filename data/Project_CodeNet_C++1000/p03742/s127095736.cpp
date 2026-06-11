#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    long long a,b;
    while(cin>>a>>b)
    if(abs(a-b)<=1)cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
	return 0;
}
