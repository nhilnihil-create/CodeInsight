#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[305][305];
int top[305];
int event[305];
int event_closed[305];

bool check(int K) {
    memset(event, 0, sizeof(event));
    memset(event_closed, 0, sizeof(event_closed));
    memset(top, 0, sizeof(top));
    for (int i = 0; i < N; i++) {
        int ev = A[i][top[i]];
        event[ev]++;
    }
    
    int flag = 1;
    while (flag) {
        flag = 0;
        
        for (int i = 0; i < M; i++) {
            if (event[i] <= K) continue;
            flag = 1;
            event[i] = 0;
            event_closed[i] = 1;
            for (int j = 0; j < N; j++) {
                if (event_closed[A[j][top[j]]] == 0) continue; 
                while (top[j] != M && event_closed[A[j][top[j]]]) {
                    top[j]++;
                }
                if (top[j] == M) return false;
                event[A[j][top[j]]]++;
            }
        }
    }
    return true;
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    
    int ng = 0;
    int ok = N;
    while (abs(ok - ng) > 1) {
        int mid = (ng + ok) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
