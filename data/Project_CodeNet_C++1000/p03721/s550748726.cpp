#include <iostream>
using namespace std;

int main() {
    int n;
    long long k;//
    cin >> n >> k;
    long long arr[100001] = {};
    for (int i = 0 ; i < n ; i++){
        int num , qty;
        cin >> num >> qty;
        arr[num] += qty;
    }
    long long count = 0;
    for (int i = 1 ; i < 100001 ; i++ ){
       count += arr[i];
       if( count >= k ){
         cout << i;
         return 0;
       }
    }
}

