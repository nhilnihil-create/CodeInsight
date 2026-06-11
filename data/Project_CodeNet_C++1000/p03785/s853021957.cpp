#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, c, k; cin >> n >> c >> k;
    vector<int> t;
    for(int i=0; i<n; i++){
        int tmp; cin >> tmp;
        t.push_back(tmp);
    }
    sort(t.begin(), t.end());
    int ans = 0;
    int stock=0;
    int time=0;
    for(int i=0; i<n; i++){
        if(stock==0){
            time = t[i]; // 残っている一番古い人の到着時間
        }
        stock++; // たまってる人数
        if(stock==c){ // 満タンになったら送り出す
            ans++;
            stock=0;
        }else if(t[i+1]-time >k && i!=n-1){ // 切れだす前に送り出す
            ans++;
            stock = 0;
        }
    }
    if(stock!=0) ans++;
    cout << ans << endl;
    return 0;
}