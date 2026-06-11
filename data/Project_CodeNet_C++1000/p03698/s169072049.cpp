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
	ll l = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++){
		bool ch = true;
		for (int j = i + 1; j < str.length(); j++){
			if (str[i] == str[j]){
				ch = false;
				break;
			}
		}
		if (ch)
			l++;
	}
	if (l == str.length())
		cout << "yes";
	else
		cout << "no";
	//cout << endl;
	return 0;
}
