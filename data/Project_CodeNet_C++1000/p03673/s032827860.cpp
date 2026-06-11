#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, A;cin >> N;
vector<ll> B;

rep(i, 0, N){

cin >> A;

if(i%2 == 0)B.push_back(A);

else B.insert(B.begin(), A);
}

if(N%2 != 0)reverse(ALL(B));

rep(i, 0, B.size())cout << B[i] << " ";
}
