#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  int x[N];
  for (int i = 0; i < N; i++)
    cin >> x[i];
  int num = 0;
  
  for (int i = 0; i < N; i++){
  	if(x[i] >= K - x[i]){
    	num += K - x[i];
    }else{
    	num += x[i];
    }
  }
    cout << num *2 << endl;
 
}