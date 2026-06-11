#include <climits>

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <numeric>

#define SIZE 100

typedef long long ll;

int N;
ll  W;
std::vector< ll > weights;
std::map< ll, std::vector< ll > > mp;

ll one() {
    ll res = 0, wgt = 0;
    std::vector< ll > v = mp[ weights[0] ];
    for (int i=0; i<=v.size(); ++i) {
        if (wgt + weights[0] <= W) {
            res += v[i];
            wgt += weights[0];
        }
    }
    return res;
}

ll two() {
    ll res = 0, wgt = 0;
    std::vector< ll > v0 = mp[weights[0]], v1 = mp[weights[1]];
    for (int i=0; i<=v0.size(); ++i) {
        for (int j=0; j<=v1.size(); ++j) {
            ll tmp = -1;
            if ( i*weights[0] + j * weights[1] <= W ) {
                tmp = std::accumulate(v0.begin(), v0.begin()+i, 0) + std::accumulate(v1.begin(), v1.begin()+j, 0);
            }
            res = std::max(res, tmp);
        }
    }
    return res;
}

ll three() {
    ll res = 0, wgt = 0;
    std::vector< ll > v0 = mp[weights[0]], v1 = mp[weights[1]], v2 = mp[weights[2]];
    for (int i=0; i<=v0.size(); ++i) {
        for (int j=0; j<=v1.size(); ++j) {
            for (int k=0; k<=v2.size(); ++k) {
                ll tmp = -1;
                if ( i*weights[0] + j * weights[1] + k * weights[2] <= W ) {
                    tmp  = std::accumulate(v0.begin(), v0.begin()+i, 0) + std::accumulate(v1.begin(), v1.begin()+j, 0);
                    tmp += std::accumulate(v2.begin(), v2.begin()+k, 0);
                }
                res = std::max(res, tmp);
            }
        }
    }
    return res;
}

ll four() {
    ll res = 0, wgt = 0;
    std::vector< ll > v0 = mp[weights[0]], v1 = mp[weights[1]], v2 = mp[weights[2]], v3 = mp[weights[3]];
    for (int i=0; i<=v0.size(); ++i) {
        for (int j=0; j<=v1.size(); ++j) {
            for (int k=0; k<=v2.size(); ++k) {
                for (int l=0; l<=v3.size(); ++l) {
                    ll tmp = -1;
                    if ( i*weights[0] + j * weights[1] + k * weights[2] + l *weights[3] <= W ) {
                        tmp  = std::accumulate(v0.begin(), v0.begin()+i, 0) + std::accumulate(v1.begin(), v1.begin()+j, 0);
                        tmp += std::accumulate(v2.begin(), v2.begin()+k, 0) + std::accumulate(v3.begin(), v3.begin()+l, 0);
                    }
                    res = std::max(res, tmp);
                }
            }
        }
    }
    return res;
}

void solve() {
    ll res = 0;
    int n = weights.size();
    switch (n)
    {
        case 1:
            res = one();
            break;
        case 2:
            res = two();
            break;
        case 3:
            res = three();
            break;
        case 4:
            res = four();
            break;
        default:
            break;
    }

    std::cout << res << std::endl;
}

void print_vector( std::vector< ll > vec ) {
    for ( auto v : vec ) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin >> N >> W;
    for (int i=0; i<N; ++i) {
        ll w, v;
        std::cin >> w >> v;
        if (mp.find(w) == mp.end()) weights.push_back( w );
        mp[w].push_back(v);
    }
    /*
    for (auto wgt : weights) {
        std::cout << wgt << ' ';
    }
    std::cout << '\n';
    */
    std::map< ll, std::vector< ll > >::iterator itr = mp.begin();
    while (itr != mp.end()) {
        std::sort((itr->second).begin(), (itr->second).end(), std::greater< ll >());
        ++itr;
    }
    /*
    itr = mp.begin();
    while ( itr != mp.end()) {
        std::cout << itr->first << " : ";
        print_vector( itr->second );
        ++itr;
    }
    */
    solve();
    return 0;
}
