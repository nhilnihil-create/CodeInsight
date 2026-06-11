#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
int main() {
    ll s;
    cin >> s;
  	int l=0;
    ll si;
    ll ans = 0;
  	for(ll k=s; k>0; k/=10){
      l++;
    }
    for(int i=0; i<(1<<l-1);i++){
        si = s;
        int jp = 0;
        for(int j=0; j<l-1;j++){
            if(i&(1<<j)){
                ans += (si % (ll)pow(10,j+1-jp));
                si = (si / (ll)pow(10,j+1-jp));
                jp = j+1;
            }
        }
      	ans += si;
      
    }
  	cout<<ans<<endl;

} 