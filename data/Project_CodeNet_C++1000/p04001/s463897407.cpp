#include<bits/stdc++.h>
using namespace std;


int main(){
    string s; cin >> s;
    long long res=0;
    for(int bits=0; bits<(1<<s.size()-1); bits++){
        vector<long long> num(s.size());
        for(int i=0; i<s.size(); i++){
            num[i]=s[i]-'0';
        }
        long long total=0;
        for(int i=0; i<s.size()-1; i++){
            if(bits & (1<<i)) continue;
            num[i+1]+=10*num[i];
            num[i]=0;
        }
        for(int i=0; i<s.size(); i++){
            total+=num[i];
        }
        res+=total;
    }
    cout << res << endl;
    return 0;
}