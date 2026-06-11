#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    priority_queue<string, vector<string>, greater<string>> que;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        que.push(s);
    }

    string ans = "";
    while(!que.empty()){
        string target = que.top();
        ans += target;
        que.pop();
    }

    cout << ans << endl;
    return 0;

}