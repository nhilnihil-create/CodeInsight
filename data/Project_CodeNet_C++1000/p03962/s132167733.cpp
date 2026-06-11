#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<int> vec(0);
    int s;
    for(int i = 0;i < 3;i++){
        cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    cout << vec.size() << endl;
}
