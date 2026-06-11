
#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int n1 = 10;
    char a[10];
    while(n1 <= 1000000000){
        printf("? %lld\n", n1);
        fflush(stdout);
        scanf("%s", a);
        if(a[0] == 'N') break;
        n1 *= 10;
    }
    if(n1 != 10000000000){
        int n0 = n1 / 10;
        // n0 < ans < n1
        int x1 = n0;
        int x2 = n1 - 1;
        while(x2 - x1 > 1){
            int x = (x1 + x2 + 1) / 2;
            printf("? %lld000000000\n", x);
            fflush(stdout);
            scanf("%s", a);
            if(a[0] == 'Y'){
                x2 = x;
            }else{
                x1 = x;
            }
        }
        printf("! %lld\n", x2);
        fflush(stdout);
    }else{
        //答えは10^n
        int n1 = 9;
        while(n1 <= 1000000000){
            printf("? %lld\n", n1);
            fflush(stdout);
            scanf("%s", a);
            if(a[0] == 'Y') break;
            n1 = n1 * 10 + 9;
        }
        printf("! %lld\n", (n1 + 1) / 10);
        fflush(stdout);
    }
    

    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}