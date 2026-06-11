#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll COM[100][100];


void COMinit(){
  for(ll i = 0; i < 100; i++){for(ll j = 0; j < 100; j++){ COM[i][j] = 0;}}
  
  for(ll i = 0; i < 100; i++){  COM[i][0] = 1; COM[i][i] = 1;}
  
  for(ll i = 1; i < 99; i++){
    for(ll k = 1; k <= i; k++){
      COM[i+1][k] += COM[i][k-1] + COM[i][k];}
  }
}
        
int main(){
 int N,A,B; COMinit();
  
  cin >> N >> A >> B; vector<ll> v(N);
 
   for(ll i = 0; i < N; i++){ cin >> v[i];}
  
  sort(v.rbegin(),v.rend());
  long double sum = 0.0;
  for(ll i = 0; i < A; i++){ sum += v[i];} //平均の最大値自体は簡単に求まる
  ll cnt = 0; 
  
  for(ll i = A; i <= B; i++){
    vector<ll> vec; long double res = 0.0;
    
    for(ll j = 0; j < i; j++){ vec.push_back(v[j]); res += v[j];}

    if( abs(res/i - sum/A) > 1e-7){continue;}
    ll test = vec.back(); ll count = 0; ll n = 0;
    
    for(ll j = 0; j < i; j++){ if(vec[j] == test){ count++;}}
    for(ll k = 0; k < N; k++){ if(v[k] == test){ n++;}}
    
    cnt += COM[n][count];
  }

  
  cout <<fixed << setprecision(10) << sum/A << endl;
  cout << cnt << endl; return 0;}