#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); ++i)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define INF ((1 << 30) - 1)
 
int main(){
    istream_iterator<int> itr(cin);
    int n = *itr, m = *(++itr);
    vector<int> a(m), b(m), c(m);
    rep(i, m){
        a[i] = *(++itr) - 1;
        b[i] = *(++itr) - 1;
        c[i] = *(++itr);
    }
 
    vector< vector<int> > p(n);
    rep(i, n){
        p[i] = vector<int>(n, INF);
    }
    rep(i, n){
        p[i][i] = 0;
    }
    rep(i, m){
        p[a[i]][b[i]] = c[i];
        p[b[i]][a[i]] = c[i];
    }
    rep(i, n)
        rep(j, n)
            rep(k, n)
                p[j][k] = min(p[j][k], p[j][i] + p[i][k]);
 
    int sum = 0;
    rep(i, m){
        bool used = false;
        rep(j, n){
            if(p[j][a[i]] + c[i] == p[j][b[i]] || p[j][b[i]] + c[i] == p[j][a[i]]){
                used = true;
                break;
            }
        }
        if(!used){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}