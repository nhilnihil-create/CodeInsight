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
	int x1=0, y1=0, x2, y2, n;
	cin >> x2 >> y2 >> n;
	rep(i,n){
		int x, y, a;
		cin >> x >> y >> a;
		if(a == 1){ 
			if (x1 < x)
				x1 = x;
		} else if (a == 2){ 
			if (x2 > x)
				x2 = x;
		} else if (a == 3){ 
			if (y1 < y)
				y1 = y;
		} else { 
			if (y2 > y)
				y2 = y;
		}
	}
	if(x1 > x2 || y1 > y2){ 
		puts("0");
		return 0;
	}
	cout << (x2 - x1) * (y2 - y1) << endl;


	return 0;
}