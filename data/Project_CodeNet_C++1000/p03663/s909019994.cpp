#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;


#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define INF 1<<30
#define mp make_pair
#define pb push_back



typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vp;

typedef long long ll;

int main(){
	int MAX = 64;
	//char buffer[sizeof(long) * 8 + 1];
	string n,buffer;
	char ans;
	ll mi = pow(10, 17);
	ll ma = pow(10, 18)-1;
	ll mid;
	string check,lcheck;
	rep(i, MAX){
		mid = (mi + ma) / 2;
		//_i64toa_s(mid, buffer, sizeof(long) * 8 + 1, 10);
		buffer = to_string(mid);
		string buff = buffer;
		check = buff.substr(0, 10);
		if (check == lcheck && check[9] == '0'){
			break;
		}
		lcheck = check;

		cout << "? " << buffer << endl;
		//cout << "@: " << i+1 << endl;
		cin >> ans;
		if (ans == 'Y'){
			ma = mid;
		} else if(ans=='N'){
			mi = mid;
		}
	}
	ll threshold = mid / pow(10, 8);
	//109 vs 1090 10901 : y y  1091 : y y 110 : y n
	//99 vs 990 9901:y y 991:y y 100: n : y
	//199 VS 1990 19901: y y 1991:y y 200: y n
	ll res = threshold;
	for (int i = 9; 0 < i; i--){
		threshold = 1 + threshold / 10;
		cout << "? " << threshold << endl;
		cin >> ans;
		//99999の時の処理
		if (threshold == pow(10, i)){
			if (ans == 'Y'){
				break;
			}
			if (ans == 'N'){
				res /= 10;
				break;
			}
		} else{
			if (ans == 'N'){
				break;
			}
		}
		res /= 10;
	}
	/*
	_i64toa_s(mid, buffer, sizeof(long) * 8 + 1, 10);
	stringstream s;
	s << buffer;
	string buff=s.str();
	string highest = "";
	string res;
	rep(i,buff.size()-8){
		highest += buff[i];
	}
	for (int i = highest.size() - 1;; i--){
		res = highest.substr(0, i);
		cout << "? " + res << endl;
		cin >> ans;
		if (ans == 'Y'){
			break;
		}
	}*/

	cout << "! ";
	cout << res << endl;

	return 0;
}
