#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> s,t;
	rep(i,n){
		ll a, b;
		cin >> a >> b;
		s.push_back(pair<ll, ll>(a, b));
	}
	rep(i,m){
		ll a, b;
		cin >> a >> b;
		t.push_back(pair<ll, ll>(a, b));
	}
	rep(i,n){
		ll c = -1,d = Inf;
		rep(j,m){
			
			if (abs(s[i].first - t[j].first) + abs(s[i].second - t[j].second) < d){
				c = j;
				d = abs(s[i].first - t[j].first) + abs(s[i].second - t[j].second);
			}
			
		}
		cout << c + 1 << endl;
	}

	return 0;
}


