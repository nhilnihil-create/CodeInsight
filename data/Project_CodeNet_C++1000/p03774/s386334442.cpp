#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>//for queue and priority_queue
#include <fstream>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#define endl "\n"
typedef long long ll;
using namespace std;
void Lancer() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
bool isPrime(ll n){
	if (n == 2 || n == 3 || n == 5)
		return true;
	else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1)
		return false;
	else {
		for (int i = 5; i <= sqrt(n); i += 2){
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

int frq[57];
int main(){
	Lancer();
	ll n, m, res , dis,indx=0,x,y;
	cin >> n >> m;
	vector<pair<int, int > > stud(n + 2), pnt(n + 2);
	for (int i = 0; i < n; i++)
		cin >> stud[i].first >> stud[i].second;
	for (int i = 0; i < m; i++)
		cin >> pnt[i].first >> pnt[i].second;

	for (int i = 0; i < n; i++){
		res = 1000000000000000000;
		for (int j = 0; j < m; j++){
			x = abs(stud[i].first - pnt[j].first);
			y = abs(stud[i].second - pnt[j].second);
			dis = x + y;
			if (dis < res){
				indx = j + 1;
				res = dis;
			}
		}
		cout << indx << endl;
	}
	//cout << endl;
	return 0;
}
