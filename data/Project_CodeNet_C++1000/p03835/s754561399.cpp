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
//cout << fixed << setprecision(12);
//stoi("123");convert string to int
//to_string(123);convert int to string 

using namespace std;
void Lancer() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

//ll  pfx[100007][32];

int main(){
	Lancer();
	ll  n, sum, s, res = 0;
	cin >> n >> sum;
	for (int i = 0; i <= n; i++){
		s =sum- i;
		for (int j = 0; j <= n; j++){
			if (s - j <= n && i + j + (s - j) == sum && s-j>=0)
				res++;
		}
	}
	cout << res;
	cout << endl;
	return 0;
}