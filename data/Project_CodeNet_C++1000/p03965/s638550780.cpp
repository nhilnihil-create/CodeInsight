#include <iostream>
using namespace std;

int main() {
	string ss;
    cin >> ss;
    int len = ss.length();
    int p = len/2;
    int g = len-len/2;
    int score = 0;
    for (int i=0; i<p; i++){
    	if (ss[i]=='g'){
    		score ++;
    	}
    }
    for (int i=p; i<len; i++){
    	if (ss[i]=='p'){
    		score --;
    	}
    }
    cout << score << endl;
}