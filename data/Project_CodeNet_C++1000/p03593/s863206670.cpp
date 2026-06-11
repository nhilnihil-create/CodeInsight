#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int h,w;
	cin >> h >> w;
	char m[105][105];
	int count = 0;
	map<int,int> mp;
	rep(i,h)rep(j,w) {
		cin >> m[i][j];
		mp[m[i][j] - 'a']++;
	}
	rep(i,26){
		if(mp[i] % 2 == 1) count++;
	}
	if(h % 2 == 0 && w % 2 == 0){
		bool ok = true;
		if(count >= 1) ok = false;
		rep(i,26){
			if(mp[i] != 0 && mp[i] % 4 != 0) ok = false;
		}
		if(ok){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}else if(h % 2 == 0 && w % 2 == 1){
		bool ok = true;
		if(count >= 1) ok = false;
		int ni = 0;
		rep(i,26){
			if(mp[i] % 4 != 0 && mp[i] % 2 == 0) ni++;
		}
		if(ni > h/2) ok = false;
		if(ok){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	} else if (h % 2 == 1 && w % 2 == 0){
		bool ok = true;
		if(count >= 1) ok = false;
		int ni = 0;
		rep(i,26){
			if(mp[i] % 4 != 0 && mp[i] % 2 == 0) ni++;
		}
		if(ni > w/2) ok = false;
		if(ok){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}else{
		bool ok = true;
		if(count >= 2) ok = false;
		int ni = 0;
		rep(i,26){
			if(mp[i] % 4 != 0 && mp[i] % 2 == 0) ni++;
		}
		if(ni > h/2 + w/2) ok = false;
		if(ok){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	
    return 0;
}

