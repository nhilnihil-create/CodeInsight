#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 10;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int N;
    scanf("%d", &N);
    int A[MAX];
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A + 1, A + N + 1, cmp);
    int pos = 1;
    for(int i = 1; i <= N; i++)
        if(A[i] >= i) pos = i;
    int dist1 = A[pos] - pos;
    int dist2 = 0;
    for(int i = pos + 1; i <= N; i++) {
        if(A[i] >= pos) dist2++;
    }
    //cout << pos << endl;
    //cout << dist1 << dist2 << endl;
    if((dist1 % 2) || (dist2 % 2)) printf("First\n");
    else  printf("Second\n");
}
