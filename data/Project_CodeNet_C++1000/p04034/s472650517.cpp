#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<bool> red(n, false);
    vector<long long> s(n, 1);

    red[0] = true;
    for(long long i = 0; i < m; i++){
        long long x, y;
        cin >> x >> y;
        x--;
        y--;

        if(red[x] == false){
            s[x]--;
            s[y]++;
        }
        else{
            red[y] = true;
            s[x]--;
            s[y]++;
            if(s[x] == 0) red[x] = false;
        }
    }

    long long cnt = 0;

    for(long long i = 0; i < n; i++){
        if(red[i] == true) cnt++;
    }
    cout << cnt << endl;
    return 0;
}