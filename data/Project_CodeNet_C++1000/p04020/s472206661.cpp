#include<cstdio>
using ull = unsigned long long;

int main(){
    unsigned N;
    scanf("%u", &N);
    ull answer = 0, cards = 0;
    for (size_t i = 0; i < N; i++)
    {
        ull a;
        scanf("%llu", &a);
        if(a) cards += a;
        else{
            answer += cards >> 1;
            cards = 0;
        }
    }
    answer += cards >> 1;
    printf("%llu\n", answer);
	return 0;
}