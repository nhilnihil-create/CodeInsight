
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    vector<int> cnt(9,0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        temp /= 400;
        if(temp>8) temp=8; //3200以上の人は8にまとめる
        cnt[temp] ++;
    }

    //最小
    int cntmin=0;
    for(int i=0; i<8; i++){
        if(cnt[i]>0) cntmin ++;
    }
    if(cntmin==0 && cnt[8]!=0) cntmin ++;

    //最大
    int cntmax=0;
    for(int i=0;i<8;i++){
        if(cnt[i]>0) cntmax ++;
    }
    cntmax += cnt[8];
    
    cout << cntmin << ' ' << cntmax << endl;
}
