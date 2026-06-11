#include<bits/stdc++.h>
using namespace std;
long long int n,a,b;

int main(){
    int max = 2000000000;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &a,&b);
		if(a+b < max) {
			max = a+b;
		}
    }
    printf("%lld", max);
    return 0;
}