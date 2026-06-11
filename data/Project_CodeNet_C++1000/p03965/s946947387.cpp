#include "bits/stdc++.h"

using namespace std;

int main() {
	string s;
	cin >> s;
	int paper = 0, rock = 0, win = 0, lose = 0;
	for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'p'){
            if(paper < rock){
                paper++;
            }else{
                rock++;
                lose++;
            }
        }else{
            if(paper < rock){
                paper++;
                win++;
            }else{
                rock++;
            }
        }
	}
	cout << win - lose;
	return 0;

}
