#include<cstdio>
using namespace std;
struct node{
	int str[310];
	int l,r;
	void csh(){
		l=150,r=149;
	}
	void push_back(int x){
		str[++r]=x;
	}
	void push_front(int x){
		str[--l]=x;
	}
	void print(){
		for(int i=l;i<=r;i++)
			printf("%d ",str[i]);
	}
}s1,s2;
int stk[100100],top;
int main(){
//	freopen("C.in","r",stdin);
	long long n;
	scanf("%lld",&n);
	n++;
	s1.csh(),s2.csh();
	while(n){
		stk[++top]=n%2;
		n/=2;
	}
	int num=0;
	for(int i=top-1;i>=1;i--){
		s1.push_back(++num);
		s2.push_back(num);
		if(stk[i]){
			s1.push_back(++num);
			s2.push_front(num);
		}
	}
	printf("%d\n",num*2);
	s1.print(),s2.print();
	printf("\n");
	return 0;
}
