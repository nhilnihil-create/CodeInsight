#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int a,b,c;cin>>a>>b>>c;
	int goal=c%b;
	for(int i=0;i<=b;i++){
		if((a*i)%b==goal){
			cout<<"YES";return 0;
		}
	}
	cout<<"NO";
	return 0;
}