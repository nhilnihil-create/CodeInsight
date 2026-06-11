#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,a,b;
	string s;
	int t1=0,t2=0;
	cin >> n >> a >> b >> s;
	for(int i=0;i<n;i++){
		if((s[i]=='a')&&((t1+t2)<(a+b))){
			cout << "Yes" << endl;
			t1++;
		}
		else if((s[i]=='b')&&(t2<b)&&((t1+t2)<(a+b))){
			cout << "Yes" << endl;
			t2++;
		}
		 else cout << "No" << endl;
	}
	
	return 0;
}