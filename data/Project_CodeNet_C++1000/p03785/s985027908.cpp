#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
using namespace std;
#define int ll

struct Waiting{
    int num = 0;
    int minutes = -1;
};

signed main(){
    int N,C,K; cin >> N >> C >> K;
    vi passengers(N); rep(i,N) cin >> passengers[i]; 
    sort(ALL(passengers));
    Waiting que;
    int bus = 0;
    que.num++;
    que.minutes = 0;
    for(int i = 1; i < N; i++){
        if(que.num == C){
            //Bus leaving
            bus++;
            que.num = 1;
            que.minutes = 0;
        }else if(que.minutes + (passengers[i] - passengers[i-1]) > K){
            // bus leaving
            bus++;
            que.num = 1;
            que.minutes = 0;
            
        }else{
            que.num++;
            que.minutes += passengers[i] - passengers[i-1];
        }


    }
    bus++;
    cout << bus << endl;
    sysp;
}