#include<iostream>
using namespace std;
long long n,m,pair_num(0);
void using_s(){
	n--;
	m -= 2;
	pair_num++;
}
void using_c(){
	m -= 4;
	pair_num++;
}
int main(void){
	cin>>n>>m;
	while(n>=1 && m>=2)using_s();
	while(m>=4)using_c();
	cout<<pair_num<<endl;
	return 0;
}