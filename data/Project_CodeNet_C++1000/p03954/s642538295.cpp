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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    int n;
    cin >> n;
    n *=2;
    n--;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ok = 1;
    int ng = n+1;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        vector<int>b = a;
        rep(i,n){
            if(b[i]>=mid){
                b[i] = 1;
            }else{
                b[i] = 0;
            }
        }
        // for(int x:b){
        //     cerr << x << " ";
        // }
        // cerr << endl;
        int p = n/2;
        int left = 0;
        int right = 0;
        int k = b[p];
        int c = 1-k;
        for(int i=p+1;i<n;i++){
            if(b[i]==c){
                right++;
                c = 1-c;
            }else{
                break;
            }
        }
        c = 1-k;
        for(int i=p-1;i>=0;i--){
            if(b[i]==c){
                left++;
                c = 1-c;
            }else{
                break;
            }
        }
        int res = 0;
        if(left==right){
            if(left ==p){
                res = k + p%2;
                res %=2;
            }else{
                res = b[p+right+1];
            }
        }else if(left>right){
            res = b[p+right+1];
        }else{
            res = b[p-left-1];
        }
        if(res){
            ok = mid;
        }else{
            ng = mid;
        }
    }   
    cout << ok << endl;
    return 0;
}