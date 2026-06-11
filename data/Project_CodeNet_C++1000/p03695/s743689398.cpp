#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    set<int> se; //3200未満の色の種類
    int over_num = 0; //3200以上の人
    rep(i, n) {
        int a;
        scanf("%d", &a);
        if(a >= 3200) over_num++;
        else se.insert(a / 400); ///400で色の種類に変換
    }

    int max = se.size() + over_num; //色の種類に、自由に色を選べる人が全員違う色を選んだとする
    
    int min = 0;
    if (se.size() == 0) min = 1; //みんな3200以上だとみんな同じ色を選ぶ
    else min = se.size(); //自由に色を選べる人が既出の色を選ぶ

    printf("%d %d\n", min, max);
    return 0;
}