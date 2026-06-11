#include <cstdio>

#define fin stdin
#define fout stdout

#define MOD (1000 * 1000 * 1000 + 7)

int r[5009][5009];

inline int lgput(int a, int n){
    int r = 1;
    while(n > 0){
        if(n % 2) r = 1LL * r * a % MOD;
        a = 1LL * a * a % MOD;
        n /= 2;
    }
    return r;
}

int main(){
    int n;
    fscanf(fin, "%d ", &n);

    int m = 0;
    char ch = fgetc(fin);

    while(ch != '\n'){
        m ++;
        ch = fgetc(fin);
    }

    /*fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (1LL * fact[i-1] * i)%MOD;
    invFact[i] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i --)
        invFact[i] = 1LL * invFact[i+1] * (i+1) % MOD;

    int ajut = 1;
    for(int i = 0;  i <= n/2; i++){
        cat[i] = 1LL * fact[2 * i] * invFact[i] % MOD * invFact[i+1] % MOD * ajut % MOD;
        ajut *= 2;
        if(ajut >= MOD)
            ajut -= MOD;
    }*/

    r[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        r[i][0] = r[i-1][0] + r[i-1][1];
        if(r[i][0] >= MOD)
            r[i][0] -= MOD;
        for(int j = 1; j <= i; j++){
            r[i][j] = 2 * r[i-1][j-1];
            if(r[i][j] >= MOD)
                r[i][j] -= MOD;
            r[i][j] += r[i-1][j+1];
            if(r[i][j] >= MOD)
                r[i][j] -= MOD;
        }
    }

    int ans = 1;
    for(int i = 0; i < m; i++)
        ans = 2 * ans % MOD;
    ans = lgput(ans, MOD-2);

    ans = 1LL * ans * r[n][m] % MOD;

    fprintf(fout, "%d\n", ans);

    return 0;
}
