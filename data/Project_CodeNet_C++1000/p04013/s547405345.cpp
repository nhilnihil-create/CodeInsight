#include <bits/stdc++.h> 
using namespace std; 

#define MAX_INDEX 51 
#define MAX_SUM 2505 
#define ll long long

// This dp array is used to store our values 
// so that we don't have to calculate same 
// values again and again 
ll dp[MAX_INDEX][MAX_SUM][MAX_INDEX]; 

ll waysutil(ll index, ll sum, ll count, 
			vector<ll>& arr, ll K) 
{ 
	// Base cases 
	// Index can't be less than 0 
	if (index < 0) 
		return 0; 

	if (index == 0) { 

		// No element is picked hence 
		// average cannot be calculated 
		if (count == 0) 
			return 0; 
		ll remainder = sum % count; 

		// If remainder is non zero, we cannot 
		// divide the sum by count i.e. the average 
		// will not be an integer 
		if (remainder != 0) 
			return 0; 
		ll average = sum / count; 

		// If we find an average return 1 
		if (average == K) 
			return 1; 
	} 

	// If we have already calculated this function 
	// simply return it instead of calculating it again 
	if (dp[index][sum][count] != -1) 
		return dp[index][sum][count]; 

	// If we don't pick the current element 
	// simple recur for index -1 
	ll dontpick = waysutil(index - 1, 
							sum, count, arr, K); 

	// If we pick the current element add it to 
	// our current sum and increment count by 1 
	ll pick = waysutil(index - 1, 
						sum + arr[index], 
						count + 1, arr, K); 
	ll total = pick + dontpick; 

	// Store the value for the current function 
	dp[index][sum][count] = total; 
	return total; 
} 

// Function to return the number of ways 
ll ways(ll N, ll K, ll* arr) 
{ 
	vector<ll> Arr; 

	// Push -1 at the beginning to 
	// make it 1-based indexing 
	Arr.push_back(-1); 
	for (ll i = 0; i < N; ++i) { 
		Arr.push_back(arr[i]); 
	} 

	// Initialize dp array by -1 
	memset(dp, -1, sizeof dp); 

	// Call recursive function 
	// waysutil to calculate total ways 
	ll answer = waysutil(N, 0, 0, Arr, K); 
	return answer; 
} 

// Driver code 
int main() 
{ 
  ll K,N,arr[100];
  cin>>N>>K;
    for(ll i=0;i<N;i++)
      cin>>arr[i]; 
	cout << ways(N, K, arr); 

	return 0; 
} 
