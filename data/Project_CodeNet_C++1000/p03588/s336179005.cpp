#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    map<int,int> map;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a;
        cin >> b;
        map[a] = b;
    }
    
    vector<int> key;
    for(auto m : map) {
        key.push_back(m.first);
    }
    
    int count = 0;
    count += (map.begin() -> first);//上
    count += (map.rbegin() -> second);//下
    
    for(int i = 0; i < key.size() -1 ; i++) { //全要素参照
        int fdif = abs(key[i] - key[i+1]);
        int sdif = abs(map[key[i]] - map[key[i+1]]);
        int dif = (fdif >= sdif) ? sdif : fdif; 
        count += dif;
    }

    cout << count << endl;
    return 0;
}