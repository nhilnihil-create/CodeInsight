#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int n;
vector <int> numbers;

ll cost(int to){
	ll ans = 0;
	
	for (auto& i:numbers){
		ans += (i - to)*(i - to);
	}
	
	return ans;
}

int main ()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define int ll
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);

	cin >> n;
	numbers.resize(n);
	
	for (auto& i:numbers) cin >> i;
	int minimum = *min_element(numbers.begin(), numbers.end());
	int maximum = *max_element(numbers.begin(), numbers.end());
	
	int ans = INT_MAX;
	
	for (int i=minimum; i<=maximum; i++){
		ans = min(ans, cost(i));
	}
	
	cout << ans << endl;
	
    return 0;

}