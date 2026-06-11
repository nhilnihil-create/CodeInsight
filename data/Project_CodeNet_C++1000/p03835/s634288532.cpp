#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll K, S, Ans = 0;cin >> K >> S;
vector<ll> A;

rep(i, 0, K + 1)A.push_back(i);

rep(x, 0, K + 1){
rep(y, 0, K + 1){

auto Iter1 = A.end() - upper_bound(ALL(A), S - x - y);
auto Iter2 = lower_bound(ALL(A), S - x - y) - A.begin();
ll N = K + 1 - Iter1 - Iter2;
Ans+=N;

}
}
cout << Ans;
}