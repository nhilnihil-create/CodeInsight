#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 301
#define INF (1LL << 50)
#define MAXN 100001
#define MAXM 100001
#define MAXK 100002
#define MAXV 100001
#define MAXP 1000001
#define MOD 1000000007
#define EPS (1e-10)
typedef long long ll;

int N;
int a[MAXN];

bool check(int i, map<int, int> m){
    int b[MAXN];
    if(m[i] == 0) return false;
    m[i]--;
    b[0] = i;
    for(int i = 1;i < N;i++){
        if(b[i - 1] == 0){
            if(m[2] == 0) return false;
            m[2]--;
            b[i] = 2;
        }else if(b[i - 1] == 1){
            if(m[1] == 0){
                if(m[2] == 0) return false;
                m[2]--;
                b[i] = 2;
            }else{
                m[1]--;
                b[i] = 1;
            }
        }else{
            if(m[0] == 0){
                if(m[1] == 0){
                    if(m[2] == 0) return false;
                }else{
                    m[1]--;
                    b[i] = 1;
                }
            }else{
                m[0]--;
                b[i] = 0;
            }
        }
    }

    return true;
}

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }
    map<int, int> m;
    for(int i = 0;i < N;i++){
        if(a[i] % 2) m[0]++;
        else{
            if(a[i] % 4) m[1]++;
            else m[2]++;
        }
    }
    for(int i = 0;i < 3;i++){
        if(m.find(i) == m.end()){
            m[i] = 0;
        }
    }
    if(check(0, m) ){
        printf("Yes\n");
    }else if(check(1, m) || check(2, m)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}