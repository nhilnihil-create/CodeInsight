#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;



int main(){
    int n;
    cin >> n;
    int a[n];
    int col[9];
    rep(i, 9) col[i] = 0;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        if (1 <= tmp && tmp < 400){
            col[0] = 1;
        }
        else if (400 <= tmp && tmp < 800){
            col[1] = 1;
        }
        else if (800 <= tmp && tmp < 1200){
            col[2] = 1;
        }else if(1200<= tmp && tmp < 1600){
            col[3] = 1;
        }else if(1600<= tmp && tmp < 2000){
            col[4] = 1;
        }else if(2000<= tmp && tmp < 2400){
            col[5] = 1;
        }else if(2400<= tmp && tmp < 2800){
            col[6] = 1;
        }else if(2800<= tmp && tmp < 3200){
            col[7] = 1;
        }else{
            col[8]++;
        }
    }
    int cnt = 0;
    rep(i, 8)
    {
        if(col[i]==1)
            cnt++;
    }
    if(cnt == 0)
        cout << 1 << " ";
    else cout << cnt << " ";
    cnt += col[8];
    cout << cnt << endl;
    return 0;
}