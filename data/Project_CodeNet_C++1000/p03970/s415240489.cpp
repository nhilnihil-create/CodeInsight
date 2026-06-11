#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
string c,x="CODEFESTIVAL2016";
int ans=0;
int main(){
	cin>>c;
	int i;
	for(i=0;i<c.size();i++){
		if(c[i]!=x[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}