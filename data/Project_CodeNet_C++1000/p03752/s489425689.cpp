#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main() {
    long long Height[15];
    long long copyHeight[15];

    long long ans = 1000000000000;

    cin >> N >> K;
    for ( int i = 0; i < N; ++i ) {
        cin >> Height[i];
    }


    for ( int bit = 0; bit < (1 << N); ++bit ) {
        int count = 0;

        for ( int p = 0; p < N; ++p ) {
            if ( bit & (1 << p)) count++;
        }
        if ( count < K ) continue;

        else {

            for ( int i = 0; i < N; ++i ) copyHeight[i] = Height[i];
            int flag_num = 0;
            long long cost = 0;
            for ( int i = 0; i < N; ++i ) {
                if ( bit & (1 << i) ) {
                    long long max_h = 0;
                    for ( int j = flag_num; j < i; ++j ) {
                        max_h = (copyHeight[j] > max_h) ? copyHeight[j] : max_h;
                    }
                    if ( max_h >= copyHeight[i] ) {
                        cost += max_h - copyHeight[i] + 1;
                        copyHeight[i] = max_h + 1;
                    }
                    flag_num = i;
                } 
            }
            ans = (cost < ans) ? cost : ans;
        }

    }

    cout << ans << endl;

    return 0;
}