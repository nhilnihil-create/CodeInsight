#include <iostream>
using namespace std;

#define TIMES(cnt,s,e) for(int cnt=s; cnt<e; ++cnt)



int main(void){

	int h,w;
	string s;

	cin >> h >> w;
	TIMES(i,0,h) {
		TIMES(j,0,w) {
			cin >> s;
			if(s == "snuke") {
				cout << (char)(65+j) << i+1 << endl;				
			}		
		}
	}

}