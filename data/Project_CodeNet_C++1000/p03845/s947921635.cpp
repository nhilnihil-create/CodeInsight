#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin>>n;
    
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t.at(i);
    }
    
    int m; cin>>m;
    //m回 tの操作をする
    
    vector<int> a(m);
    
    for (int i = 0; i < m; i++) {
        //tの添字pをxに変更して、tの要素の和
        int p, x, s = 0;
        cin >> p >> x;
        p = p - 1;
        vector<int> result = t;
        result.at(p) = x;
        for (int j = 0; j < result.size(); j++) {
            s += result.at(j);
        }
        a.at(i) = s;
        
    }
    
    for (int i = 0; i < m; i++) {
        cout << a.at(i) << endl;
    }
}