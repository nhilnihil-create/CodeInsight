#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, L, Q;
const int maxn = 1e5 + 5;
int x[maxn];
int st[maxn][20];

void init(){
    for(int i = 1;i <= n;i++){
        int l = i, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(x[mid] - x[i] <= L){
                l = mid;
            }else{
                r = mid - 1;
            } 
        }
        st[i][0] = l;
    }
    for(int len = 1;len < 20;len++){
        int j = (1 << len);
        for(int i = 1;i <= n;i++){
            st[i][len] = st[st[i][len - 1]][len - 1];
        }
    }
}

int query(int a, int b){
    int ans = 0;
    for(int i = 19;i >= 0;i--){
        if(st[a][i] < b){
            ans += (1 << i);
            a = st[a][i];
        }
    }
    return ans + 1;
}

int main(){
    //freopen("in/subtask1_01.txt", "r", stdin);
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &x[i]);
    }
    cin >> L;
    x[n + 1] = x[n] + 1;
    init();
    cin >> Q;
    for(int i = 1;i <= Q;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)
            swap(a, b);
        printf("%d\n", query(a, b));
    } 
    return 0;
}
