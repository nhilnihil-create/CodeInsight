#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		if((i+1)*i/2>=n){
			for(int j=1;j<=i;j++){
				if((i+1)*i/2-n==j);
				else cout<<j<<endl;
			}
			return 0;
		}
	}
	return 0;
}
