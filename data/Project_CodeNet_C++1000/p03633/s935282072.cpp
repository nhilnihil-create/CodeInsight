// C++ program to find LCM of two numbers  
#include <iostream>
#include <vector>
#include <numeric>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPONE(i, n) for(int i = 1; i < n; i++)
#define ld long double
#define ll long long

using namespace std; 

// Driver program to test above function  
int main()  
{  
    int n; cin >> n;
    vector<ll> time;
    ll t;
    REP(i, n) {
        cin >> t;
        time.push_back(t);
    }

    ll ans = time[0];

    REPONE(i, n) {
        // ans = ((ld)ans * (ld)time[i]) / gcd((ll)ans, (ll)time[i]);
        ans = lcm(ans, time[i]);
    }

    cout << (ll)ans << endl;

    return 0;  
}  