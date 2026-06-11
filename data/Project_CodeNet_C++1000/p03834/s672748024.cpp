#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string ans;
	cin>>ans;
	for(int i=0;i<ans.size();i++){
		if(ans[i]==','){
			cout<<' ';
		}else{
      cout<<ans[i];
		}
	}
	cout<<endl;
}