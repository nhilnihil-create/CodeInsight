#include<bits/stdc++.h>
using namespace std;

int IM(){
    cout << "Impossible" << endl;
    return 0;
}

int PO(){
    cout << "Possible" << endl;
    return 0;
}

int main(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int dis = a[n - 1];
    
    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
    }

    int num = (dis + 1) / 2;
    for(int i = 0; i < num; i++){
        if(cnt[dis - i] < 2) return IM();
        cnt[dis - i] -= 2;
    }
    if(dis % 2 == 0){
        if(cnt[dis - num] < 1) return IM();
        cnt[dis - num]--;
    }

    int able = (dis % 2 == 0) ? dis - num : dis - (num - 1);

    bool flag = true;
    for(int i = able; i >= 0; i--){
        if(cnt[i] > 0) return IM();
    }

    return PO();
}