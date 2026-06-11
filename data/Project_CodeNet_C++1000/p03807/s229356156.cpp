#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N;
    cin >> N;
    int A[100001];
    int odd = 0;
    int even = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] % 2 == 1) odd++;
        else even++; 
    }
    if(odd%2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}