#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<bool>stt(n,true);
    vector<set<int>>list(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
        list[a[i]].insert(i);
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(auto v : list[i]){
            if(a[i]==v&&stt[v]){
                stt[i] = false;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}