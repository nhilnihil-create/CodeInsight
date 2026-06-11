#include <bits/stdc++.h>

using namespace std;


int main() {
    int n , k; 
    cin>>n>>k;
    int ans = 1;
    ans *= k;
    ans *= pow(k - 1 , n - 1);
    cout<<ans<<"\n";
}