#include <bits/stdc++.h>
using namespace std;

signed main(){
	string  s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if(s1[s1.size() - 1] == s2[0] && s2[s2.size() - 1] == s3[0]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}