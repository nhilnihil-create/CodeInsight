#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#define mod 1000000007
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
	string a,b,c;
	cin >> a >> b >> c;
	string out = (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) ? "YES" : "NO";
	cout << out; 
	return 0;
}

