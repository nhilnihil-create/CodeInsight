#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll max(ll a,ll b){
	return a>b? a:b;
}
ll T;
ll a,b,c;
int main(){
    cin>>a>>b;
    if(a%3==0||b%3==0||(a+b)%3==0){
    	cout<<"Possible\n";
	}
	else cout<<"Impossible\n";
    return 0;
}