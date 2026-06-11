#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
using namespace std;

int main() {
    nl // Lofi songs		

    int n, k, x, y;
    cin >> n >> k >> x >> y;
    
    cout << (n < k ? x*n : (x*k) + (n-k)*y);
    
}	
