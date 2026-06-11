#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    s1.erase(unique(s1.begin(), s1.end()), s1.end());
    s2.erase(unique(s2.begin(), s2.end()), s2.end());
    vector<bool> s;
    for(int i=0; i<s1.size(); ++i){
        s.push_back(s1[i]==s2[i]);
    }
    cout << endl;
    long long ans=s[0] ? 3 : 6;
    for(int i=1; i<s.size(); ++i){
        int t;
        if(!s[i-1] && s[i]) t=1;
        else if(!s[i-1] && !s[i]) t=3;
        else t=2;
        ans=ans*t%1000000007;
    }
    cout << ans << endl;
    return 0;
}
