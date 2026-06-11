#include <iostream>
#include <string>

using namespace std;

int main(){
	int H,W,cou[26]={};
	cin >> H >> W;
	string s;
	for(int i=0;i<H;i++){
		cin >> s;
		for(int j=0;j<s.size();j++){
			cou[s[j]-'a']++;
		}
	}
	int cnt1=0,cnt2=0,cnt4=0;
	for(int i=0;i<26;i++){
		if(cou[i]%2!=0)cnt1++;
		if(cou[i]%4>1)cnt2++;
	}
    if(cnt1 > 1 || cnt1 == 1 && H * W == 0) {
        cout << "No" << endl;
    }else {
		int area =0;
		if(H%2!=0){
			area+=W/2;
		}
		if(W%2!=0){
			area+=H/2;
		}
		if(area<cnt2){
			cout << "No" << endl;
		}else{
			cout << "Yes" << endl;
		}
	}
	return 0;
}
