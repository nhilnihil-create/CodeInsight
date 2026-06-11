#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define MAX 200002

int n;

vector<long long int> v;
vector<long long int> vv;


int can[MAX];

#define MOD 1000000007LL

long long int k[MAX];

vector<int> ng;

int main(){
	k[0] = 1;
	for (int i = 1; i < MAX; i++){
		k[i] = k[i - 1];
		k[i] *= (long long int)(i);
		k[i] %= MOD;
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	long long int way = 1;
	long long int rest = 0;
	int cer = -1;
	for (int i = 0; i < n; i++){
		cer += 2;
		rest++;
		if (cer>v[i]){
			ng.push_back(i);
			cer -= 2;
			way *= rest;
			way %= MOD;
			rest--;
		}
	}
	way *= k[rest];
	way %= MOD;
	printf("%lld\n", way);
	return 0;
}