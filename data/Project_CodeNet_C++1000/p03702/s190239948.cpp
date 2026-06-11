#include <bits/stdc++.h>
using namespace std;
int N;
long long A,B;
long long h[100000];

bool C(long long T) {
    long long cnt = 0;
    for(int i=0; i<N; ++i) {
        if(h[i] - B*T >= 0) {
            cnt += (h[i] - B * T) / (A - B);
            if((h[i] - B * T) % (A - B)) ++cnt;
        }
    }
    return cnt <= T;
}

int main() {
    cin >> N >> A >> B;
    long long hmax = 0;
    for(int i=0; i<N; ++i) {
        cin >> h[i];
        hmax = max(hmax, h[i]);
    }

    long long l = 0;
    long long r = hmax / B + 1;
    while(r - l > 1) {
        long long mid = (l+r)/2;
        if(C(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}