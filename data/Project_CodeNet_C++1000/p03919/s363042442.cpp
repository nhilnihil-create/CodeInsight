#include<iostream>
#include<string>

using namespace std;

int main(){
	int h, w, cnt;
	string s, str = "snuke";
	cin >> h >> w;
	for(cnt = 0; cnt < h * w; cnt++){
		cin >> s;
		if(s == str){
			break;
		}
	}
	cout << (char)('A' + (cnt % w)) << cnt / w + 1 << endl;
	return 0;
}