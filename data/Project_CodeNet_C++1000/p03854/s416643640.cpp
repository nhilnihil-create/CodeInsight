#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    string s;
    cin >> s;
    string t[20010];
    string T;
    int j = 0;
    reverse(s.begin(), s.end());
    int n = s.size();
    for(int i = 0; i < n; i++){
        t[j] += s[i];
        if(t[j] == "maerd" || t[j] == "esare" || t[j] == "remaerd" || t[j] == "resare"){
            T += t[j];
            j++;
        }

    }
    if(T.size() == s.size()) cout << "YES" << endl;
    else cout << "NO" << endl; 
    return 0;
}