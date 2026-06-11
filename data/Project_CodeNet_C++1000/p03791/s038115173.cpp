#include <bits/stdc++.h>

#define PAUSE system("pause")
#define LLI long long int
#define LD long double
#define PB push_back
#define PF push_front
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)

using namespace std;

const int MOD = 1e9+7;

int main() {	
//	ifstream fin("in.txt");
//	ofstream fout("out.txt");
	
	int n;
	cin >> n;
	vector<int> x(n);
	FORi(i,0,n){
		cin >> x[i];
	}
	
	LLI ans = 1, place = 1;
	FORi(i,1,n){
		place += x[i-1] <= 2*(i-place);
//		cout << place << ' ';
		ans *= (i + 2 - place);
		ans %= MOD;
	}
//	cout << endl;
	
	cout << ans;
//	PAUSE;
//	fin.close();
//	fout.close();
    return 0;
}