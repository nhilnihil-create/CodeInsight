#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> s(N);
    deque<int> q;
    int sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> s[i];
        sum += s[i];
        if(s[i]%10 != 0) q.push_back(s[i]);
    }
    sort(q.begin(), q.end());
    while(sum%10 == 0 && sum != 0){
        if(q.size() == 0){
            cout << 0 << endl;
            return 0;
        }
        sum -= q.front();
        q.pop_front();
    }
    cout << sum << endl;
    return 0;
}
