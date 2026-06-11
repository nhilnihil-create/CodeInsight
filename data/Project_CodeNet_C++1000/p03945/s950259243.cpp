#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int cnt=0;
    for(int i=1; i<s.size(); i++){
        if(s.at(i)!=s.at(i-1)) cnt++;
    }
    cout << cnt << endl;
}