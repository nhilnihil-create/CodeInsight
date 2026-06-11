#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    set<int> a;
    rep(i, 3){
        int n;
        cin >> n;
        a.insert(n);
    }
    cout << a.size() << endl;
}
