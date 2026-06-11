#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_N = 100005;

int A[MAX_N], n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + 1 + n);
    reverse(A + 1, A + 1 + n);
    
    int nr = 1;
    
    while(nr < n && A[nr + 1] >= nr + 1) {
        nr++;
    }
    
    if((A[nr] - nr) % 2 == 1) {
        cout << "First";
        return 0;
    }
    
    int end = nr;
    while(end < n && A[end + 1] == nr) {
        end++;
    }
    
    if((end - nr) % 2 == 1) {
        cout << "First";
        return 0;
    }
    
    cout << "Second";
    
    return 0;
}
