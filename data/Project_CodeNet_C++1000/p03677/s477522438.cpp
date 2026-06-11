#include <iostream>

using namespace std;

int main(){
    int n, m;
    int a[100000];
    long score[10000] = {0};
    long cnt[100001] = {0};
    long deq[100001] = {0};
    long inc = 0;
    long ans;
    cin >> n >> m;
    cin >> a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(a[i] > a[i-1]){
            cnt[a[i]]--;
            cnt[a[i-1]+1]++;
            deq[a[i]+1] += (a[i]-a[i-1]+m)%m - 1;
        }
        if(a[i] < a[i-1]){
            cnt[a[i]]--;
            cnt[a[i-1]+1]++;
            inc++;
            deq[a[i]+1] += (a[i]-a[i-1]+m)%m - 1;
        }
    }
    for(int i = 1; i < n; i++){
        score[1] += min((a[i]-a[i-1]+m)%m, a[i]);
    }
    ans = score[1];
    inc += cnt[1];
    for(int i = 2; i <= m; i++){
        score[i] = score[i-1]-inc + deq[i];
        inc+= cnt[i];
        ans = min(ans, score[i]);
    }
    for(int i = 1; i <= m; i++){
        //cout << score[i] << endl;
    }
    cout << ans << endl;
}