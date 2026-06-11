#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,ans=0,now;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }

    now = 0;
    for(int i = 0; i < n; ++i){
        now = a.at(now)-1;
        if(now == 1){
            cout << (i + 1) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
