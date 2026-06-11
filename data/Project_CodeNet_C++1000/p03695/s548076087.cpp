#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    set<int> s;
    int num = 0; 
    for(int i = 0; i < N; i++){
        if(vec.at(i) >= 3200){
            num++;
        }
        else{
            int div;
            div = vec.at(i) / 400;
            s.insert(div);
        }
    }
    int ans;
    ans = s.size() + num;
    int s2 = s.size();
    cout << max(1, s2) << " ";
    cout << ans << endl;
}
    