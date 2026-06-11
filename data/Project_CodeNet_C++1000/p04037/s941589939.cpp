#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;

const int MX = 1<<17;
const int MM = 1000000007;

int D[MX];
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	sort(D+1, D+N+1);
	reverse(D+1, D+N+1);
	for(int i = 1; i <= N; i++){
		if( i+1 > D[i+1]){
			int ok = 1;
			for(int j = i; D[j] >= i; j++) ok ^= 1;
			ok |= (D[i] - i)&1;
			return !printf("%s\n", ok? "First" : "Second");
		}
	}
}
