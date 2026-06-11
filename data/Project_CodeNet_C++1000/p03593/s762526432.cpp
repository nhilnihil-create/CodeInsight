#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    int H, W;
    cin >> H >> W;
    map<char, int> mp;
    rep(i, H){
        rep(j, W){
            char ipt;
            cin >> ipt;
            mp[ipt]++;
        }
    }
    vector<int> numbers;
    for(auto m: mp){
        numbers.push_back(m.second);
    }
    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());
    int four = (H / 2) * (W / 2);
    int two = (H % 2) * (W / 2) + (W % 2) * (H / 2);
    int one = (H % 2) * (W % 2);
    int four_mk = 0, two_mk = 0, one_mk = 0;
    for(int i = 0; i < numbers.size(); i++){
        four_mk += numbers[i] / 4;
        numbers[i] %= 4;
        two_mk += numbers[i] / 2;
        numbers[i] %= 2;
        one_mk += numbers[i];
    }

    if(four_mk < four){
        cout << "No" << endl;
        return 0;
    }
    two_mk += (four_mk - four) * 2;
    if(two_mk < two){
        cout << "No" << endl;
        return 0;
    }
    one_mk += (two_mk - two) * 2;
    if(one_mk < one){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}






// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
