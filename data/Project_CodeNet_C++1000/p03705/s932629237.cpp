#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
int main() {
    long long N, A, B;
    cin >> N >> A >> B;
    if (N == 1 && A==B){
        cout << "1" << endl;
        return 0;
    }else if( A>B || B-A > N){
        cout << "0" << endl;
        return 0;
    }
   
    long long ans = (N-2)*(B-A)+1;
    
    cout << ans << endl;
    return 0;
}