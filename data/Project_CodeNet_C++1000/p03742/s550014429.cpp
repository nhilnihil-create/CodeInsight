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


i64 a,b;

int main(){
	cin >> a >> b;
	
	if(abs(a-b) < 2) cout << "Brown" << endl;
	else cout << "Alice" << endl;
	
	return 0;
}