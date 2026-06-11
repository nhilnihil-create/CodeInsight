#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int h,w;cin>>h>>w;
	vector<vector<char>> a(h,vector<char>(w));
	vector<int> cnt(26,0);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin>>a[i][j];
			cnt[a[i][j] - 'a'] ++;
		}
	}
	if (w % 2 == 0 && h % 2 == 0){
		for(int i = 0; i < 26; i++) {
			if (cnt[i] % 4 != 0){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	else if (w % 2 == 1 && h % 2 == 1){
		int check = 0;
		bool check2 = false;
		for(int i = 0; i < 26; i++) {
			if (cnt[i] % 4 == 0)continue;
			if (cnt[i] % 4 == 2){
				if (check == (h / 2) + (w / 2)){
					cout << "No" << endl;
					return 0;
				}
				else{
					check++;
				}	
			}
			else{
				if (check2){
					 cout << "No" << endl;
					 return 0;
				}
				check2 = true;
			}
		}
	}
	else {
		int check = 0;
		for(int i = 0; i < 26; i++) {
			if (cnt[i] % 2 == 1){
					cout << "No" << endl;
					return 0;
			}
			if (cnt[i] % 4 == 2){
				if ( w % 2 == 1){
					if (check == h / 2){
						cout << "No" << endl;
						return 0;
					}
					else{
						check++;
					}
				}
				else{
					if (check == w / 2){
						cout << "No" << endl;
						return 0;
					}
					else{
						check++;
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
