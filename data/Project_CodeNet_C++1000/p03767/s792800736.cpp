#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
//overflowに注意
int a[300030];
int main() {
    int N;
    cin >> N;
    long long max = 0;
    int n = 3*N;

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a, a + n, greater<int>());

    for(int i = 1; i <= N; i++){
        int k = 2*i - 1;
        max += a[k];
    }
    
    cout << max << endl;

    return 0;
}