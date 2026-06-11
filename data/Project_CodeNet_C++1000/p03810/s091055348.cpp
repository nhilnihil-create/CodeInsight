#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

void solve(int first) {
    int cnt = 0, v;
    for(int i = 0; i < N; i++) {
        if(arr[i] & 1) {
            cnt++;
            v = arr[i];
            arr[i]--;
        }
    }
    if(cnt == 1 && v != 1) {
        int g = arr[0];
        for(int i = 1; i < N; i++) {
            g = gcd(g, arr[i]);
        }
        int p = 0;
        for(int i = 0; i < N; i++) {
            arr[i] /= g;
            p ^= ((arr[i] - 1) & 1);
        }
        if(p) {
            if(first) printf("First");
            else printf("Second");
        }
        else solve(first ^ 1);
    }
    else {
        if(first) printf("First");
        else printf("Second");
    }
}

int main() {
    scanf("%d", &N);
    arr.resize(N);
    int p = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        p ^= ((arr[i] - 1) & 1);
    }
    if(p) printf("First");
    else solve(0);
}
