// AC済 バチャコン用再提出
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

bool comp(pair<long long, long long> in1, pair<long long, long long> in2)
{
    if(in1.second < in2.second){
        return true;
    } else {
        return false;
    }
}

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    long long a[100100];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<pair<long long, long long> > c, b;
    for(int i = 1; i <= n - 1; i++){
        pair<long long, long long> in;
        in.first = a[i];
        if(a[i] > a[i + 1]){
            in.second = a[i + 1] + m;
        } else {
            in.second = a[i + 1];
        }
        b.push_back(in);
        c.push_back(in);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end(), comp);
    /*for(int i = 0; i < n - 1; i++){
        cout << b[i].first << " " << b[i].second << endl;
    }
    for(int i = 0; i < n - 1; i++){
        cout << c[i].first << " " << c[i].second << endl;
    }*/
    long long minus[100100];
    for(int i = 0; i <= m; i++){
        minus[i] = 0;
    }
    long long contain = 0;
    for(int i = 0; i < n - 1; i++){
        if((b[i].first <= (m + 1 - 2)) && (b[i].second >= (m + 1))){
            contain++;
            minus[1] += m - b[i].first;
        }
    }
    //cout << minus[1] << endl;
    for(int i = 2; i <= m; i++){
        int ok = n - 2;
        int ng = -1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(b[mid].first >= (i - 2)){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        while(b[ok].first == (i - 2)){
            contain++;
            ok++;
            if(ok > n - 2){
                break;
            }
        }
        ok = n - 2;
        ng = -1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(b[mid].first >= (i + m - 2)){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        while(b[ok].first == (i + m - 2)){
            contain++;
            ok++;
            if(ok > n - 2){
                break;
            }
        }
        ok = n - 2;
        ng = -1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(c[mid].second >= (i - 1)){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        while(c[ok].second == (i - 1)){
            contain--;
            minus[i] -= (c[ok].second - c[ok].first - 1);
            ok++;
            if(ok > n - 2){
                break;
            }
        }
        ok = n - 2;
        ng = -1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(c[mid].second >= (i - 1 + m)){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        while(c[ok].second == (i - 1 + m)){
            contain--;
            minus[i] -= (c[ok].second - c[ok].first - 1);
            ok++;
            if(ok > n - 2){
                break;
            }
        }
        minus[i] += minus[i - 1] + contain;
        //cout << i << " " << contain << " " << minus[i] << endl;
    }
    long long sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += b[i].second - b[i].first;
    }
    long long minimum = minus[1];
    for(int i = 2; i <= m; i++){
        minimum = max(minimum, minus[i]);
    }
    cout << sum - minimum << endl;
    /*for(int i = 1; i <= m; i++){
        cout << minus[i] << endl;
    }*/
    return 0;
}
