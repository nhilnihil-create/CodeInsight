#include<bits/stdc++.h>
using namespace std;

vector<int> cnt(100005,0);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a-1]++, cnt[b-1]++;
    }
    bool flag = true;
    for(int i=0; i<N; i++) {
        if(cnt[i]%2) flag = false; 
    }
    cout << (flag ? "YES" : "NO") << "\n";
}