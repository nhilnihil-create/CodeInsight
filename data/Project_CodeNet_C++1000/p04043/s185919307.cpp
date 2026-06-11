#include <iostream>
using namespace std;

int main(void){
	int in[3];
	cin >> in[0] >> in[1] >> in[2];
	int count[2]={0};
	for(int e : in){
		if(e==5)count[0]++;
		else if(e==7)count[1]++;
	}
	if(count[0]==2 && count[1]==1)cout << "YES" << endl;
	else cout << "NO" << endl;
}