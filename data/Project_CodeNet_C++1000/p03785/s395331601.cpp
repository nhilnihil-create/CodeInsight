#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,c,k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for(int i=0; i<n; i++){
        cin >> t.at(i);
    }
    sort(t.begin(),t.end());

    int bus=1;
    int count=0;
    int time=t.at(0);
    for(int i=0; i<n; i++){
//        cout << t.at(i) << ' ' << time << endl;
        if(count==c || (t.at(i)-time) >k){
            bus++;
            time=t.at(i);
            count=1;
        }
        else count++;
    }
    cout << bus << endl;
}