#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;


int main(){
	int w,a,b;
	cin>>w>>a>>b;
	cout<<max(0,max(a,b)-min(a,b)-w);
}



