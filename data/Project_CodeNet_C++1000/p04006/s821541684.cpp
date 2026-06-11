#include <iostream>
#include <vector>
using namespace std;
long long MAX = 1e18;
struct segRMQ{
    long long n;
    vector<long long> dat;
    segRMQ(long long n_){
        n = 1;
        while(n < n_) n *= 2;
        dat.resize(2 * n - 1);
        for(int i = 0; i < 2 * n - 1; i++) dat[i] = MAX;
    }
    void update(long long k, long long a){
        k += n - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    long long query(long long a, long long b, long long k, long long l, long long r){
        if(r <= a || b <= l) return MAX;
        if(a <= l && r <= b) return dat[k];
        else{
            long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};
int main(){
    long long N, x;
    cin >> N >> x;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    segRMQ segK(N);
    long long n = segK.n;
    for(int i = 0; i < N; i++) segK.update(i, a[i]);
    long long ans = MAX;
    for(long long i = 0; i < N; i++){
        long long temp = 0;
        temp += x * i;
        for(long long j = 0; j < N; j++){
            if(j < i){
                temp += min(segK.query(0, j + 1, 0, 0, n), segK.query(N - i + j, N, 0, 0, n));
            }
            else temp += segK.query(j - i, j + 1, 0, 0, n);
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}