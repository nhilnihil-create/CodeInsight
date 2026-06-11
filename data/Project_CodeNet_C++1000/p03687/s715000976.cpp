#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    string s;
    cin >> s;
    int mi = inf;
    int n = s.size();
    rep(id,26){
        char  c = 'a'+id;
        bool flag = 0;
        rep(i,n){
            if(s[i]==c)flag = 1;
        }
        if(!flag)continue;
        string t = s;
        int tmp = 0;
        while(1){
            int m = t.size();
            bool ff = 1;
            rep(i,m){
                if(t[i]!=c)ff = 0;
            }
            if(ff)break;
            tmp++;
            string u;
            rep(i,m-1){
                if(t[i]==c){
                    u.push_back(c);
                }else{
                    u.push_back(t[i+1]);
                }
            }
            t = u;
        }
        chmin(mi,tmp);
    }
    cout << mi << endl;
    return 0;
}