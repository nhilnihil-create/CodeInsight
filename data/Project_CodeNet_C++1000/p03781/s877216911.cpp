#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int x;
	cin>>x;
	for(int i=1;i<1000000000;i++){
		if((1+i)*i/2>=x){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
