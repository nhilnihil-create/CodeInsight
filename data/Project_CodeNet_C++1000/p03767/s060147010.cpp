#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
ll N;
cin >> N;
vector<ll> hito(3*N);
  for(long long i=0;i<3*N;i++) cin>>hito[i];

sort(hito.begin(),hito.end());
reverse(hito.begin(),hito.end());
ll su = 0;
for(ll i = 1, j = 0; j < N; i = i+2, ++j){
su += hito[i];
}
cout << su << endl;

}


