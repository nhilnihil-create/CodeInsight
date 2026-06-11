#include <iostream>
using namespace std;
int n,banyak[100010],total,maks=0,a;
int main() {
cin>>n;
for(int i=1;i<=n;i++) {
	cin>>a;
	banyak[a]++;
}
for(int i=1;i<=100000;i++) {
	total=banyak[i]+banyak[i+1]+banyak[i-1];
	if(maks<total) {
		maks=total;
	}
}
cout<<maks<<endl;

}
