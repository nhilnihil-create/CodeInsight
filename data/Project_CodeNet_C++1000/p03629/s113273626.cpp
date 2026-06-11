#include <iostream>
#include <algorithm>
#include <vector>
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
    string S;
    cin >> S;
    S.insert(S.begin(), 0);
    vector<int> cumulative_sum[S.size() + 1];
    cumulative_sum[0].resize(26, 0);
    cumulative_sum[1].resize(26, 0);
    for(int i = 1; i < S.size(); i++){
        cumulative_sum[i + 1] = cumulative_sum[i];
        cumulative_sum[i + 1][S[i] - 'a']++;
    }
    int next[S.size()];
    for(int i = 0; i < S.size(); i++){
        int left = i, right = int(S.size()) + 1; // [left, right)
        while(left + 1 < right){
            int middle = (left + right) / 2;
            bool is_ok = true;
            for(int j = 0; j < 26; j++){
                if(cumulative_sum[i + 1][j] == cumulative_sum[middle][j]){
                    is_ok = false;
                    break;
                }
            }
            if(is_ok){
                right = middle;
            }else{
                left = middle;
            }
        }
        next[i] = left;
    }
    vector<int> next_alphabets_point[S.size()];
    next_alphabets_point[0].resize(26, int(S.size()));
    for(int i = 1; i < S.size(); i++){
        next_alphabets_point[i].resize(26, int(S.size()));
        for(int j = i - 1; j >= 0 && next_alphabets_point[j][S[i] - 'a'] == int(S.size()); j--){
            next_alphabets_point[j][S[i] - 'a'] = i;
        }
    }
    int longthest_of_not_subsequence[S.size() + 1];
    longthest_of_not_subsequence[S.size()] = 0;
    for(int i = int(S.size()) - 1; i >= 0; i--){
        longthest_of_not_subsequence[i] = longthest_of_not_subsequence[next[i]] + 1;
    }
    int now = 0;
    while(now < S.size()){
        for(int i = 0; i < 26; i++){
            if(next_alphabets_point[now][i] == S.size()){
                for(int j = 0; j < 26; j++){
                    if(next_alphabets_point[now][j] == S.size()){
                        cout << char(j + 'a') << endl;
                        return 0;
                    }
                }
            }else if(longthest_of_not_subsequence[next_alphabets_point[now][i]] == longthest_of_not_subsequence[now] - 1){
                cout << S[next_alphabets_point[now][i]];
                now = next_alphabets_point[now][i];
                break;
            }
        }
    }
}
