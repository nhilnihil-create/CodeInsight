# include <bits/stdc++.h>
using namespace std;

# define forn(i, n) for(int i = 0; i < n; i++)
# define fort(i, n) for(int i = 1; i <= n; i++)
# define fork(i, x) for(__typeof__((x).begin())i=(x).bsegin();i!=(x).end();i++)
# define tbit(a)    __builtin_popcount(a)
# define bchk(a, x) ((a)>>(x))&(1)
# define bset(a, x) ((a)|(1<<(x)))
# define bclr(a, x) ((a)&(~(1<<(x))))
# define read(x)    freopen(#x, "r", stdin)
# define write(x)   freopen(#x, "w", stdout)
# define all(x)     x.begin(), x.end()

# define dbg(args...)    {string sss(#args);sss+=',';cerr<<"-->";debugger::call(all(sss), args);cerr<<"\n";}
# define dbgA(A, n)      {cerr<<"-->"<<#A<<"=(";forn(i, n)cerr<<A[i]<<" ";cerr<<")\n";}
# define dbgA2(A, n, m)  {cerr<<"-->"<<#A<<"=\n";forn(i, n){forn(j, m){cerr<<setw(4)<<A[i][j]<<" ";}cerr<<"\n";}cerr<<"\n";}

struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
            string b;
        for(; *it!=','; ++it) if(*it!=' ')b+=*it;
        cerr << b << " = " << a << " ";
        call(++it, ed, rest...);
    }
};

//int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
//int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};
//int knight_x[] = {2, 2, -2, -2, 1, 1, -1, -1};
//int knight_y[] = {1, -1, 1, -1, 2, -2, 2, -2};

typedef long long int ll;
typedef unsigned long long int ull;
// const double PI = 2.0*acos(0.0);
//const double GOLD = (1.0 + sqrt(5.0))/2.0;
//const double eps = 1e-9;


int dp[1000][1000];

int go(int x, int y){
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    for(int k = 1; k * 2 <= x; k++){
        int _x = x - (2 * k);
        int _y = y + k;
        if(go(_x, _y) == 0){
            dp[x][y] = 1;
            return 1;
        }
    }
     for(int k = 1; k * 2 <= y; k++){
        int _y = y - (2 * k);
        int _x = x + k;
        if(go(_x, _y) == 0){
            dp[x][y] = 1;
            return 1;
        }
    }

    dp[x][y] = 0;
    return 0;

}

int main(){
    #ifdef home
    read(input.txt);
    //    write(input.txt);
    #endif // home
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//    memset(dp, -1, sizeof(dp));
//    dp[0][0] = 0;
//    dp[1][1] = 0;
//    dp[1][0] = 0;
//    dp[0][1] = 0;
//    for(int i = 0; i < 20; i++){
//        for(int j = 0; j < 20; j++){
//            if(dp[i][j] == -1){
//                if(true){
//                    for(int k = 1; k * 2 <= i; k++){
//                        if(dp[i - (2 * k)][j + k] == 0){
//                            dp[i][j] = 1;
//                        }
//                    }
//                    for(int k = 1; k * 2 <= j; k++){
//                        if(dp[i + k][j - (2 * k)] == 0){
//                            dp[i][j] = 1;
//                        }
//                    }
//                    if(dp[i][j] == -1) dp[i][j] = 0;
//                }
//            }
//        }
//    }

//    forn(i, 30){
//        forn(j, 30){
//            cout << go(i, j) << " ";
//        }
//        cout << endl;
//    }

    ll x, y;

    while(cin>>x>>y){
        if(abs(x - y) <= 1){
            cout << "Brown\n";
        }
        else{
            cout << "Alice\n";
        }
    }

}



