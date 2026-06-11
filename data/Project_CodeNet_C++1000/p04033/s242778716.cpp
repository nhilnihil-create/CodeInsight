#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<deque>
using namespace std;
 
int main(){
	long long a,b;
	cin >> a >> b;
	long long cnt=0;
	for(long long i=a;i<=b;i++){
		if(i==0){
			cout << "Zero" << endl;
			return 0;
		}
		if(i<0)cnt++;
	}
	if(cnt%2==0)cout << "Positive" << endl;
	else cout << "Negative" << endl;
	return 0;
}
