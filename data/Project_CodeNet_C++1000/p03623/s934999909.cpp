#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	int x,a,b;
	cin >> x >> a >> b;
	if((x-a)*(x-a) < (x-b)*(x-b)){
		cout << "A" << endl;
	}else{
		cout << "B" << endl;
	}
	return 0;
}
