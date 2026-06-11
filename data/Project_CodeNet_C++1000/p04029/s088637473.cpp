#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std ;

int main(){
    std::ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
    long long  n ;
    cin >> n ;
    cout << n * (n + 1 ) / 2 ;
    return 0 ;
}