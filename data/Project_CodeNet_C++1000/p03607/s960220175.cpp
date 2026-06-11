#include <bits/stdc++.h>
using namespace std;
int main(){
        long long int n; cin >> n;
        set<long long int> s;
        for (long long int x = 0; x < n; ++x){
            long long int q; cin >> q;
            auto it = s.find(q);
            if (it == s.end()) s.insert(q);
            else s.erase(it);
        }
        cout << s.size() << endl;
    return 0;
}
