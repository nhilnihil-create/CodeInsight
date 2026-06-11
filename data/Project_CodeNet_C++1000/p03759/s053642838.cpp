#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	string out = (b-a == c - b) ? "YES" : "NO";
	cout << out;
	return 0;
}

