#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

template<class like_bool> inline void YES(like_bool condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class like_bool> inline void Yes(like_bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class like_bool> inline void POSS(like_bool condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class like_bool> inline void Poss(like_bool condition){ if(condition)cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class like_bool> inline void First(like_bool condition){ if(condition)cout << "First" << endl; else cout << "Second" << endl; }
int character_count(string text, char character){ int ans = 0; for(int i = 0; i < text.size(); i++){ ans += (text[i] == character); } return ans; }
long power(long base, long exponent, long module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ long root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position move_pattern[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++){ ans += to_string(*i) + " "; } ans.pop_back(); cout << ans << endl; }
long gcd(long a, long b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }}
#define mod long(1e9 + 7)
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcount(n)

int main(){
    int N;
    cin >> N;
    int nums[N];
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    int ans = 0;
    for(int i = 0; i < N - 1; i++){
        if(nums[i] == i + 1){
            ans++;
            swap(nums[i], nums[i + 1]);
        }
    }
    cout << ans + (nums[N - 1] == N) << endl;
}
