// 倍增 - AT2039 [ARC060C] 高橋君とホテル  Tak and Hotels.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;

int N, L, Q;
int x[100010];
int t[100010][18];
int p[20];

int main()
{
    //cin >> N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        //cin >> x[i];
        scanf("%d", &x[i]);
    }
    //cin >> L >> Q;
    scanf("%d%d", &L, &Q);
    int si=1, se=1;
    while (se < N) {
        if (x[se + 1] - x[si] <= L) {
            se++;
        }
        else {
            t[si][0] = se;
            si++;
        }
    }
    for (int i = si; i <= N; i++) {
        t[i][0] = N;
    }

    int k = int(log(N-1) / log(2));
    int temp = 1;
    for (int i = 1; i <= k; i++) {
        p[i - 1] = temp;
        for (int j = 1; j <= N; j++) {
            t[j][i] = t[t[j][i - 1]][i-1];
        }
        temp *= 2;
    }
    p[k] = temp;
    /*
    for (int i = 1; i <= N; i++) {
        cout << setw(4) << i << setw(4) << x[i];
        for (int j = 0; j <= k; j++) {
            cout << setw(4) << t[i][j];
        }
        cout << endl;
    }*/
    
    int a, b, c;
    for (int i = 1; i <= Q; i++) {
        //cin >> a >> b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        temp = a;
        c = 0;
        int minC = 1e10;
        for (int j = k; j >= 0; j--) {
            if (b < t[temp][j]) {
                minC = min(minC, c + p[j]);
                continue;
            }
			else if (b > t[temp][j]) {
				temp = t[temp][j];
				c += p[j];
			}
            else if (b == t[temp][j]) {
                //c += p[j];
                minC = min(minC, c + p[j]);
            }
        }
        //cout << c << endl;
        printf("%d\n", minC);
    }

    return 0;
}

/*
32
1 3 6 13 15 18 19 29 31 35 42 52 61 63 65 71 74 77 79 83 93 103 113 123 133 143 153 163 167 170 178 180
10
10
2 31
1 32
1 8
7 3
6 7
8 5
1 17
3 29
4 15
16 24
*/
