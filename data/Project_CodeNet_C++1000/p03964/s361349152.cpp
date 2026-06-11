#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    
    int T[N], A[N];
    for(int i=0; i<N; i++){
        cin >> T[i] >> A[i];
    }

    ll t, a;
    t = T[0];
    a = A[0];

    for(int i=1; i<N; i++){
        ll m1, m2;
        if(a % A[i] == 0) m1 = a/A[i];
        else m1 = a/A[i] + 1;

        if(t % T[i] == 0) m2 = t/T[i];
        else m2 = t/T[i] + 1;

        ll m = max(m1, m2);
        t = T[i] * m;
        a = A[i] * m;
    }

    cout << a+t << endl;

    return 0;
}
