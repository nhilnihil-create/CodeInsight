#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, Ans1 = 0, Ans2 = 0, Ans = 0;cin >> N;
map<ll, ll> M;

rep(i, 0, N){
    ll a;cin >> a;
    M[a]++;
}

for(auto x : M ){

    if(x.second >= 4)Ans = x.first*x.first;
  
    if(x.second >= 2 && Ans2 <= Ans1){Ans2 = x.first;continue;}

    if(x.second >= 2 && Ans2 > Ans1){Ans1 = x.first;continue;}


}

cout << max(Ans, Ans1*Ans2);

}
