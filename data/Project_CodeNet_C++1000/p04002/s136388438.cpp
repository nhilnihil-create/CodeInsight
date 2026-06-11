#include<bits/stdc++.h>

using namespace std;

struct duy{
    long long x, y;
} den[100005];
long long h, w, n, res[12];
long long c[] = {0, 0, 1, 1, 1, -1, -1, -1, 0};
long long d[] = {1, -1, 0, -1, 1, 0, -1, 1, 0};
map <long long, long long> m;

int main(){
    cin >> h >> w >> n;
    for(long long i = 1; i <= n; i++){
        cin >> den[i].x >> den[i].y;
        for(long long j = 0; j < 9; j++){
            long long t1 = den[i].x + c[j];
            long long t2 = den[i].y + d[j];
            if(t1 > 1 && t1 < h && t2 > 1 && t2 < w){
                long long tmp = (t1 - 1) * w + t2;
                if(m[tmp] == 0){
                    res[1]++;
                    m[tmp] = 1;
                }
                else{
                    res[m[tmp]]--;
                    m[tmp]++;
                    res[m[tmp]]++;
                }
            }
        }
    }
    long long t = (h - 2) * (w - 2);
    for(long long i = 1; i <= 9; i++) t -= res[i];
    cout << t << endl;
    for(long long i = 1; i <= 9; i++) cout << res[i] << endl;
}
