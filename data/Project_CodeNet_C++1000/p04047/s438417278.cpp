#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
  	int N;
  	cin >> N;
  	int a[2*N];
  	int ans = 0;

  	for(int i=0;i<2*N;i++){
  		cin >> a[i];
  	}
  	sort(a, a+2*N);

  	for(int i=0;i<2*N;i+=2){
  		ans += a[i];
  	}
  	cout << ans <<endl;

    
  	return 0;
}


