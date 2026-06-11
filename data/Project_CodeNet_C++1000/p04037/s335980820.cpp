#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inc(i) (++ (i))
#define dec(i) (-- (i))
#define Rep(i , a , b) for(int i = (a) , i##Limit = (b) ; i <= i##Limit ; inc(i))
using namespace std;

const int N = 100000 + 7;
int n , A[N];

int main() {
    cin >> n;
    Rep(i , 1 , n) scanf("%d" , A + i);
    sort(A + 1 , A + n + 1 , [](int A , int B){ return A > B; });
    Rep(i , 1 , n) if(i + 1 > A[i + 1]) {
            int Ans = 0;
            for(int j = i + 1 ; A[j] == i ; inc(j)) Ans ^= 1;
            Ans |= (A[i] - i) & 1;
            if(Ans) puts("First");
            else puts("Second");
            return 0;
        }
    return 0;
}