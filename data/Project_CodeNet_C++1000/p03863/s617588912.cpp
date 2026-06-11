#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	if (s[0]==s[s.size()-1]&&s.size()%2==1||s[0]!=s[s.size()-1]&&s.size()%2==0){
		printf("Second\n");
	}else{
		printf("First\n");
	}
    return 0;
}