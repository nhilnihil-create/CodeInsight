// 解き直し.
// AGC 008 Editorial
// https://img.atcoder.jp/agc008/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
const int MAX = 555;
int IX[MAX], OX[MAX * MAX + 1], ANS[MAX * MAX + 1];
deque<int> lDq, rDq;

int main(){
    // 1. 入力情報取得.
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &IX[i]);
        OX[IX[i]] = i;
        ANS[IX[i]] = i;
    }
    
    // 2. 解説通り.
    // 2-1. 左側から配置していく.
    for(int i = 0; i <= MAX * MAX; i++){
        int index = OX[i];
        // index - 1 個 を 配置.
        if(index > 0) for(int j = 1; j < index; j++) lDq.pb(index);
    }
    
    // 2-2. 右側から配置していく.
    for(int i = MAX * MAX; i >= 0; i--){
        int index = OX[i];
        // N - index 個 を 配置.
        if(index > 0) for(int j = 1; j <= N - index; j++) rDq.pf(index);
    }
    
    // 3. 数列作成.
    int index = 1;
    while(!lDq.empty()){
        int d = lDq.front();
        while(ANS[index] > 0) index++;
        lDq.pop_front();
        ANS[index] = d;
        index++;
    }
    while(!rDq.empty()){
        int d = rDq.front();
        while(ANS[index] > 0) index++;
        rDq.pop_front();
        ANS[index] = d;
        index++;
    }
    
    // 4. 整合性チェック.
    bool ok = true;
    for(int i = 1; i <= N; i++){
        int count = 0;
        for(int j = 1; j <= N * N; j++){
            if(ANS[j] == i) count++;
            if(count == i){
                if(j != IX[i]) ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    
    // 5. 出力.
    if(!ok){
        printf("%s\n", "No");
        return 0;
    }
    printf("%s\n", "Yes");
    for(int i = 1; i <= MAX * MAX; i++) if(ANS[i] != 0) printf("%d ", ANS[i]);
    return 0;
}