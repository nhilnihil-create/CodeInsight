#include <iostream>
#include <climits>
using namespace std;
long long arr[1000005];

long long gcd(long long a, long long b){
  return (b == 0) ? a : gcd(b, a%b);
}

bool multiples(long long n, long long target){
  long long gcdNum = 0;
  for(long long i = 0; i < n; i++){
    gcdNum = gcd(gcdNum, arr[i]);
  }
  return (target%gcdNum == 0);
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	long long n, target, largest = INT_MIN;
	cin >> n >> target; 
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
		largest = max(largest, arr[i]);
	}

	if(largest >= target && multiples(n, target)) {
    cout << "POSSIBLE" << endl;
  }
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}