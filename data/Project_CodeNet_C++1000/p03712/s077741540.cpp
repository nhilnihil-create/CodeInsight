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

char arr[107][107];
int main(){
	Lancer();
	ll h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> arr[i][j];
	for (int i = 0; i < h+2; i++){
		arr[i][0] = '#';
		arr[i][w+1] = '#';
	}
	for (int i = 0; i < w + 2; i++){
		arr[0][i] = '#';
		arr[h+1][i] = '#';
	}
	for (int i = 0; i < h + 2; i++){
		for (int j = 0; j < w + 2; j++)
			cout << arr[i][j];
		cout << endl;
	}

	//cout << endl;
	return 0;
}
