#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    sort(all(vec));
    vector<pair<ll,ll> > count(0);
    count.push_back(pair<ll,ll> (vec[0],1));
    rep(i,N - 1){
        if (vec[i] == vec[i + 1]){
            int len_count = count.size();
            count[len_count - 1].second++;
        }
        else{
            count.push_back(pair<ll,ll> (vec[i + 1],1));
        }
    }
    int len_count = count.size();
    ll c1 = 0;
    ll c2 = 0;
    rep(i,len_count){
        if (count[i].second >= 4){
            c1 = count[i].first;
            c2 = count[i].first;
        }
        else if (count[i].second >= 2){
            c2 = c1;
            c1 = count[i].first;
        }
    }
    cout << c1 * c2 << endl;
}
