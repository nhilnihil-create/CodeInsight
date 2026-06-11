#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62);

typedef long long i64;
typedef pair<i64,i64> P;


i64 n, m;
i64 x[101010], y[101010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < m; i++){
		cin >> y[i];
	}
	
	i64 X = 0, Y = 0;
	for(int i = 1; i < n; i++){
		X += (x[i] - x[i-1]) * i * (n-i);
		X %= INF;
	}
	for(int i = 1; i < m; i++){
		Y += (y[i] - y[i-1]) * i * (m-i);
		Y %= INF;
	}
	
	cout << X * Y % INF << endl;
	
	return 0;
}