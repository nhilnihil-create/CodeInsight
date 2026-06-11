#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, i = 0, Ans = 1, p = 1000000007;cin >> N;
bool C = 0;
string A, B;cin >> A >> B;
vector<string> S;
S.push_back(A);S.push_back(B);

while(i < N){

  if(i == 0){

    if(S[0][i] == S[1][i]){Ans *= 3;i++;C = 1;continue;}

    else{Ans *= 6;i += 2;C = 0;continue;}

  }

  if(S[0][i] == S[1][i]){

    if(C){Ans *= 2;i++;Ans %= p;C = 1;continue;}

    else{i++;Ans %= p;C = 1;continue;}

  }

  else{

    if(C){Ans *= 2;Ans %= p;i += 2;C = 0;continue;}
    else{Ans *= 3;Ans %= p;i += 2;C = 0;continue;}

  }

}

cout << Ans;

}