#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string w;
    cin >> w;
    map<char,int> mp;
    for(int i = 0; i < w.size(); i++) mp[w[i]]++;
    for(char i = 'a';i <= 'z'; i++){
        if(mp[i]%2 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

