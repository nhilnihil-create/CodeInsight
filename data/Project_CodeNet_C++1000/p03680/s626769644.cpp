#include <bits/stdc++.h>
using namespace std;
int main() {
    //入力
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];// i+1番目が消えて、a[i]が点く。1-indexed
    int x = 0;//今点いているボタンの番号。0-indexed
    int count = -1;//操作を何回行ったか。はじめに-1にしておくと便利
    for(int i = 0; i < n; i++) {//n回操作を行って2が出なかったら、もう2にはならない
        x = a[x]-1;//-1
        if(x == 1) {//0-indexedなので、2じゃない
            count = i+1;//操作はi+1回
            break;//これが最初回の操作なのでbreak;
        }
    }
    cout << count << endl;
}