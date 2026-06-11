#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length()-1;
    long long sum = 0;

    for(int bit = 0; bit < (1<<n);bit++){
        int start = 0;
        int stop = n+1;
        for(int i = 0;i < n;i++){
            if(bit & (1<<i)){
                stop = i+1;
                sum += atoll(s.substr(start,stop-start).c_str());
                start = stop;
            }
        }
        sum += atoll(s.substr(start,n+1-start).c_str());
    }
    
    cout << sum << endl;
}