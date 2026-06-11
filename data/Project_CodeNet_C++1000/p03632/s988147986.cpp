#include <bits/stdc++.h>

using namespace std;

#define ll long long

string rev(string s) {
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	int A,B,C,D;
	scanf("%d%d%d%d",&A,&B,&C,&D);
	if(D<=A || B<=C) puts("0");
	else printf("%d",min(B,D)-max(A,C));
	return 0;
}


