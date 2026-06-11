#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int x[N];
    for(int i = 0; i < N; i++) cin >> x[i];
    sort(x, x + N);

    int cnt[M]; //x mod M がiのカードの数
    int p[M]; //x mod M がiのカードでできるペアの数
    fill(cnt, cnt + M, 0);
    fill(p, p + M, 0);

    int tmp = 1;
    for(int i = 0; i < N; i++){
        if(i == N - 1){
            cnt[x[i] % M] += tmp;
            p[x[i] % M] += tmp / 2;
        }

        else {
            if(x[i] == x[i + 1]) tmp++;
            else {
                cnt[x[i] % M] += tmp;
                p[x[i] % M] += tmp / 2;
                tmp = 1;
            }
        }
    }

    // debug
    /*
    for(int i = 0; i < M; i++){
        cout << setw(2) << i;
    }
    cout << endl;
    for(int i = 0; i < M; i++){
        cout << setw(2) << cnt[i];
    }
    cout << endl;
    for(int i = 0; i < M; i++){
        cout << setw(2) << p[i];
    }
    cout << endl;
    */

    ll ans = 0;
    ans += cnt[0] / 2;
    for(int i = 1; i < (M + 1) / 2; i++){
        int j = M - i;

        while(cnt[i] > 0 && cnt[j] > 0){
            //cout << i << " " << j << endl;
            //cout << ans << endl;
            ans++;
            if(cnt[i] == p[i] * 2){
                cnt[i]--;
                p[i]--;
            } else {
                cnt[i]--;
            }

            if(cnt[j] == p[j] * 2){
                cnt[j]--;
                p[j]--;
            } else {
                cnt[j]--;
            }
        }

        //cout << i << endl;
        //cout << ans << endl;
        if(p[i] > 0 || p[j] > 0){
            //cout << "hoge" << endl;
            //cout << i << " " << j << endl;
            ans += p[i] + p[j];
        }
        //cout << ans << endl;
    }

    if(M % 2 == 0){
        ans += cnt[M / 2] / 2;
    }

    cout << ans << endl;
    return 0;
}