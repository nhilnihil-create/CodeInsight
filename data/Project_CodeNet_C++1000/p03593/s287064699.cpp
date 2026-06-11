#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
	int h,w;
	cin >> h >> w;

	map<char,int> mp;
	for(int i = 0;i < h * w;i++){
		char c;
		cin >> c;
		mp[c]++;
	}

	int cnt1 = 0;
	int cnt2 = 0;
	for(auto p:mp){
		int now = p.second % 4;
		if(now == 3){
			cnt1++;
			cnt2++;
		}
		else if(now == 2){
			cnt2++;
		}
		else if(now == 1){
			cnt1++;
		}
	}

	if(h % 2 == 0 && w % 2 == 0){
		if(cnt1 == 0 && cnt2 == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	else if(h % 2 == 0){
		if(cnt2 * 2 <= h && (h - cnt2 * 2) % 4 == 0 && cnt1 == 0){
			cout << "Yes" << endl;	
			return 0;
		}
	}
	else if(w % 2 == 0){
		if(cnt2 * 2 <= w && (w - cnt2 * 2) % 4 == 0 && cnt1 == 0){
			cout << "Yes" << endl; 
			return 0;
		}
	}
	else{
		if(cnt1 == 1 && cnt2 * 2 <= h + w - 2 && (h + w - 2 - cnt2 * 2) % 4 == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
}
