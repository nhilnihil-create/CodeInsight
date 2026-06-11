#include<cstdio>
#include<vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;
const static int MAX_N = 1000;
bool is_prime[MAX_N+1];

int main(){
	int N;
	scanf("%d", &N);
	vector<ull> prime;
	is_prime[2] = true;
	for (ull i = 3; i <= N; i += 2) is_prime[i] = true;
	for (ull i = 3; i*i <= N; i += 2){
		if(is_prime[i]){
			for (ull j = i*i; j <= N; j += i << 1) is_prime[j] = false;
		}
	}
	for (int i = 2; i <= N; ++i){
		if(is_prime[i]) prime.push_back(i);
	}
	ull answer = 1;
	for (int i = 0; i < prime.size(); ++i){
		int _N = N, count = 1;
		while(_N /= prime[i]){
			count += _N;
		}
		answer = answer*count %MOD;
	}
	printf("%llu\n", answer);
	return 0;
}