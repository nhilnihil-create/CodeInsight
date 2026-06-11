#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n ;
	int a[n] , cnt[2] = {0 , 0};
  	for(int i = 0 ; i < n ; ++i){
    	cin >> a[i];
      	cnt[a[i] % 2]++;
    }
  	cnt[0] += cnt[1]/2;	
  	cnt[1] %= 2; 
  	cout << (!cnt[1] ? "YES" : "NO") << '\n' ;
}