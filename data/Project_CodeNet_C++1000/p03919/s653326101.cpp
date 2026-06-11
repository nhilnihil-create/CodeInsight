#include <iostream>
#include <string>
using namespace std;

int main() {
	int H, W; cin >> H >> W;
	int n=1, l=0;
	string S;
	while(S!="snuke"){
	    cin >> S;
	    if(l<W) ++l;
	    else{
	        l=1;
	        ++n;
	    }
	}
	char p='A'+l-1;
	cout << p << n << endl;
	return 0;
}
