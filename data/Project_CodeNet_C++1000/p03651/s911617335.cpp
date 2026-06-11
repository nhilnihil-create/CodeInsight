#include <iostream>
#include <climits>
using namespace std;
long long arr[1000005];

long long gcd(long long a, long long b){
	if(b == 0){
		return a; 
	}
	else{
		return gcd(b, (a%b));
	}
}

bool multiples(long long n, long long min, long long max, long long target){
  long long gcdNum = 0;
	/*
  1. Check for GCD in array
  2. Check if target is divisble by GCD
  */
  for(long long i = 0; i < n; i++){
    gcdNum = gcd(gcdNum, arr[i]);
  }

  bool flag = false; 
  if(target%gcdNum != 0){
    flag = true;
  }
  return flag;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	long long n, target, min = INT_MAX, max = INT_MIN;
	cin >> n >> target; 
	for(long long i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] == target){
			cout << "POSSIBLE" << endl;
			exit(0);
		}
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}
	if(max < target){
		cout << "IMPOSSIBLE" << endl; 
		exit(0);
	}
	if(multiples(n , min, max,target) == true){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << "POSSIBLE" << endl; 
	}
}