#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[3*N];
    for(int i = 0; i < 3*N; i++) {
        cin >> a[i];
    }

    sort(a, a+3*N, greater<int>());

    long int sum = 0;
    int cnt = 0;

    for(int i = 0; i < 3*N; i++){
        if(i%2 == 1) {
            sum+= a[i];
            cnt++;
        }
        if(cnt==N) break;
    }

    cout << sum << endl;
}