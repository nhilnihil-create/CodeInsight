#include<cstdio>
const static int MAX_A = 100000;
unsigned Bucket[MAX_A];

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		unsigned tmp;
		scanf("%u", &tmp);
		Bucket[tmp-1]++;
	}
	unsigned answer = 0;
	bool even = false;
	for (int i = 0; i < MAX_A; ++i){
		if(Bucket[i]){
			answer++;
			if(!(Bucket[i] & 1)) even ^= true;
		}
	}
	if(even) answer--;
	printf("%u\n", answer);
	return 0;
}