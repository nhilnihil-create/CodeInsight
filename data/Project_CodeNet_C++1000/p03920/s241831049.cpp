#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	int sum=0;
	int cp=0;
	for(int i=1;;i++){
		sum+=i;
		cp=i;
		if(sum>=n)break;
	}
	for(int i=1;i<=cp;i++){
		if(n!=sum-i)cout << i << endl;
	}
}