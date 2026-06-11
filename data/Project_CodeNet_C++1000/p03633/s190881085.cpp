// C++ program to find LCM of two numbers  
#include <iostream>
#include <vector>
#include <numeric>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPONE(i, n) for(int i = 1; i < n; i++)
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
        ans = ans / gcd(ans, time[i]) * time[i];
    }

    cout << ans << endl;

    return 0;  
}  