#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long int n = s.length();

    /*
    set<string> word;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            string t1 = s.substr(i, j-i+1);
            reverse(t1.begin(),t1.end());

            string t2 = s.substr(0,i) + t1 + s.substr(j+1);
            cout << i << " " << j << " " << t2 << endl;
            if(word.find(t2) != word.end()) cout << "!" << endl;
            word.insert(t2);
        }
    }
    cout << word.size() << endl;
    */
    
    vector<long long int> count(26);
    for(int i=0; i<n; i++){
        count[s[i] - 'a'] += 1;
    }

    long long int ans = 1 + n * (n-1) / 2;
    for(int i=0; i<26; i++){
        ans -= count[i] * (count[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}