#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int switch_index(char s) {
    if (s == 'a') {
        return 0;
    } else if (s == 'b') {
        return 1;
    } else {
        return 2;
    }
}
int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    char v = '-';
    int a_index = 0;
    int a_size = A.size();
    int b_index = 0;
    int b_size = B.size();
    int c_index = 0;
    int c_size = C.size();
    int next = 0;
    while (true) {
        if (next == 0) {
            if (a_index == a_size) {
                v = 'A';
                break;
            }
            next = switch_index(A[a_index]);
            a_index++;
        } else if (next == 1) {
            if (b_index == b_size) {
                v = 'B';
                break;
            }
            next = switch_index(B[b_index]);
            b_index++;
        } else {
            if (c_index == c_size) {
                v = 'C';
                break;
            }
            next = switch_index(C[c_index]);
            c_index++;
        }
    }

    cout << v << endl;
    return 0;
}