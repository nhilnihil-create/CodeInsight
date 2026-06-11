#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define boost ios::sync_with_stdio(0); cin.tie(0);
#define int long long

const int N = 100 + 10;
const int MOD = 1e9 + 7;

int32_t main(){
    boost;

    //code
    
    string s;
    cin >> s;

    if( s[0] == s[s.length()-1] ^ (s.length()%2))
    	cout << "First";
    else
    	cout << "Second";
    return 0;
}