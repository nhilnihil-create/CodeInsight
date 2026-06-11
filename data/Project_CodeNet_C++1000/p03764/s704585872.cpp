#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int prime = 1000000007;
int n, m;
long long x[100000], y[100000];



int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%lld", x+i);
    }
    for(int j = 0; j < m; j++){
        scanf("%lld", y+j);
    }
    //sort(x, x+n);
    //sort(y, y+m);

    long long width = 0, height = 0;
    for(long long i = 0; i < n - 1; i++){
        width += (x[i+1]-x[i]) % prime * (i+1) % prime * ((n-1) - (i+1) + 1) % prime;
        width %= prime;
    }
    //printf("width: %lld\n", width);
    for(long long j = 0; j < m - 1; j++){
        height += (y[j+1]-y[j]) % prime * (j+1) % prime * ((m-1)-(j+1)+1) % prime;
        height %= prime;
    }
    //printf("height: %lld\n", height);

    long long res = width * height % prime;
    cout << res << endl;
    return 0;

    
}