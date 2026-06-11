#include <iostream>
#include <climits>
#include <bitset>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    long long min = LLONG_MAX;
    int bit = 1 << N;
    for(int i = 0; i < bit; i++) {
        long long sum = 0;
        int base = 0;
        int count = 0;
        int flag = 0;
        for(int j = 0; j < N; j++) {
            if((i & (1<<j)) != 0) {
                if(base == 0) {
                    base = a[j];
                } else if(base < a[j]) {
                    base += a[j];
                } else {
                    sum += (base+1)-a[j];
                    base += 1;
                }
                count += 1;
            } else {
                if(base < a[j]) {
                    base = a[j];
                    count += 1;
                }
            }
            if(count == K) {
                flag = 1;
                break;
            }
        }
        if(flag == 1 && sum < min) {
            min = sum;
            //cout << bitset<8>(i) << endl;
        }
    }
    cout << min << endl;
    return 0;
}