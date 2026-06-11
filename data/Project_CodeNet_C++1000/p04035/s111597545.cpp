#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t n, l;
    cin >> n >> l;
    vector<int64_t> A(n);
    copy_n(istream_iterator<int64_t>(cin), n, A.begin());

    int f = -1;
    
    for (int i = 0; i < n - 1; i++){
        if (A[i] + A[i + 1] >= l){
            f = i + 1;
        }
    }

    if (f == -1){
        puts("Impossible");
        return 0;
    }

    puts("Possible");
    for (int i = 1; i < f; i++)
        cout << i << endl;
    for (int i = n - 1; i >= f; i--)
        cout << i << endl;
}