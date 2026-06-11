#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, A, B, Ans = 0;cin >> N >> A >> B;

if(A > B){cout << 0;exit(0);}

if(N == 1){
    
    if(A != B){cout << 0;exit(0);}

    else {cout << 1;exit(0);}
    
    }

cout << (B - A)*(N - 2) + 1;


}
