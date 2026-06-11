#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int A[26] = {0};
	string s;
	cin>>s;
	for(size_t i=0;i<s.length();i++){
		A[s[i]-97]++;
	}
	for(size_t i=0;i<26;i++){
		if(A[i]%2!=0){ 
		printf("No"); 
		return 0;
		}
	}
	printf("Yes");
    return 0;
}