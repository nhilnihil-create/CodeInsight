#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec;
    map<int, map<int, int>> nums;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.emplace_back(x % m, x);
        nums[x % m][x]++;
    }
    // sort(vec.begin(), vec.end());

    // int num = vec[1].second;
    // int num2 = lower_bound(vec.begin(), vec.end(), pair<int, int>{m - num, -1}) -> second;
    // cout<<num<<' '<<num2<<endl;
    int ans = 0;

    for(int i=0;i<m;i++){
        if(i == (m - i) % m){
            int s1 = 0;
            auto& m1 = nums[i];
            for(auto& p : m1){ s1 += p.second; }
            ans += s1 / 2;
        }else{
            if(i > (m - i) % m){ break; }
            // if(!nums.count(i) || !nums.count((m - i) % m)){ continue; }
            auto& m1 = nums[i];
            auto& m2 = nums[(m - i) % m];
            int s1 = 0, s2 = 0;
            for(auto& p : m1){ s1 += p.second; }
            for(auto& p : m2){ s2 += p.second; }
            ans += min(s1, s2);
            if(s1 == s2){ continue; }
            if(s1 < s2){
                swap(s1, s2);
                swap(m1, m2);
            }
            vector<int> v;
            for(auto& p : m1){ v.push_back(p.second); }
            sort(v.begin(), v.end());
            // sort(v.begin(), v.end(), [](int a, int b){return (a % 2) < (b % 2); });
            // sort(v.begin(), v.end(), [](int a, int b){return !((a % 2) == 0 && (b % 2) == 1); });
            // sort(v.begin(), v.end(), [](int a, int b){return ((a % 2) == 1 && (b % 2) == 0); });
            // println(v);
            // sort(v.begin(), v.end(), [](int a, int b){return (a % 2) < (b % 2); });
            for(int& i : v){
                if(i % 2 == 1){
                    if(s2 == 0){
                        break;
                    }
                    s2--;
                    i--;
                }
            }
            sort(v.begin(), v.end());
            for(int& i : v){
                int d = min(i, s2);
                s2 -= d;
                i -= d;
            }
            for(int& i : v){
                // cnt += i;
                ans += i / 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
