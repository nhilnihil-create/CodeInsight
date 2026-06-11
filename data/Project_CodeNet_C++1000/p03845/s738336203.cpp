#include <iostream>
using namespace std;
int main(void){
	int n;
	cin >>n;
	int soma=0;
	int drinks[n];
	for(int i=0;i<n;i++){
		cin>>drinks[i];
		soma+=drinks[i];
	}
	int m;
	cin >> m;
	while(m--){
		int x,y;
		cin >> x >>y;
		cout << soma - drinks[x-1]+y<<endl;
	}
}