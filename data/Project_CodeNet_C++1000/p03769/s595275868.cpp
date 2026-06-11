#include<bits/stdc++.h>
#define I push_back(k)
std::deque<int>A,B;
long long n;
int m,k=1;
int main(){
	for(std::cin>>n,++n;n>>++m;);
	for(m--;~--m;++k){
		B.I,A.I;
		if(n>>m&1)B.push_front(++k),A.I;
	}
	for(int k:B)A.I;
	printf("%d\n",A.size());
	for(int w:A)printf("%d ",w);
	return 0;
}