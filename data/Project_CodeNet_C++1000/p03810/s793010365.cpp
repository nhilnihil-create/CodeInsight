#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

int N;
int v[100005];

void first() {printf("First\n"); exit(0);}
void second() {printf("Second\n"); exit(0);}

void win(int mv) {if(mv == 0) first(); second();}
void lose(int mv) {if(mv == 0) second(); first();}

int gcd(int a, int b)
{
    if(!a)  return b;
    if(!b)  return a;
    return gcd(b % a, a);
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &v[i]);

    int mv = 0;
    while(1)
    {
        int f[2];
        f[0] = f[1] = 0;
        for(int i = 1; i <= N; i++) f[ v[i] & 1 ]++;
        if(f[0] % 2 == 1)   win(mv);
        if(f[1] > 1)    lose(mv);
        int d = 0;
        for(int i = 1; i <= N; i++)
        {
            if(v[i] & 1)    v[i]--;
            if(v[i] == 0)   lose(mv);
            d = gcd(d, v[i]);
        }
        for(int i = 1; i <= N; i++) v[i] /= d;
        mv ^= 1;
    }

    return 0;
}
