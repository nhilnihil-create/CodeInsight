/// Source : https://atcoder.jp/contests/abc042/tasks/abc042_b
/// Author : liuyubobobo
/// Time   : 2020-09-22

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn * L)
/// Space Complexity: O(n * L)
class Solution{

public:
    string getString(vector<string>& v){

        sort(v.begin(), v.end());

        string res = "";
        for(const string& s: v) res += s;
        return res;
    }
};

int main() {

    int N, L;
    cin >> N >> L;

    vector<string> v(N);
    for(int i = 0; i < N; i ++)
        cin >> v[i];

    cout << Solution().getString(v) << endl;

    return 0;
}
