#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    
    int64_t l_1 = 0, l_2 = 0;
    for (int i = 0; i < N - 1; i++){
        if (A.at(i) == A.at(i + 1)){
            if (l_1 == 0) l_1 = A.at(i);
            else if (l_2 == 0) l_2 = A.at(i);
            i++;
            //cout << l_1 << " " << l_2 << endl;
        }
    }
    int64_t ans = l_1 * l_2;
    cout << ans << endl;
}