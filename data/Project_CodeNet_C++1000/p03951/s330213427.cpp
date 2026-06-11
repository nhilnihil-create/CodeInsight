#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	while(scanf("%d",&n)==1){
		getchar();
		string s,t;
		cin>>s>>t;
		//cout<<s<<" "<<t<<endl;
		
		int i=0, common = 0; 
		for(int i=n-1;i>=0;i--){
			string sub = s.substr(i);
			if(t.find(sub)!=-1) {
				common = n-i;
				//printf("%s %d\n", sub.c_str(), common);
			}
		}
		printf("%d\n", 2*n-common);
	}
	return 0;
}