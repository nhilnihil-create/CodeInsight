#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    set<int> num;
    for (int i = 0; i < n; i++) {
        int buf;
        cin >> buf;
        if (num.find(buf) == num.end()) {
            num.insert(buf);
        } else {
            num.erase(buf);
        }
    }
    cout << num.size() << endl;
    return 0;
}
