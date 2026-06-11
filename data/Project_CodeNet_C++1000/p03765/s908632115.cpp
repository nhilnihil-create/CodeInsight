#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string t;
    cin >> s >> t;
    vector <int> a(s.size());
    vector <int> b(t.size());
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == 'A'){
            a[i] = 2;
        }
        else{
            a[i] = 1;
        }
    }
    for (int i = 0; i < t.size(); ++i){
        if (t[i] == 'A'){
            b[i] = 2;
        }
        else{
            b[i] = 1;
        }
    }
    vector <int> pref_a(a.size() + 1);
    vector <int> pref_b(b.size() + 1);
    for (int i = 1; i < pref_a.size(); ++i){
        pref_a[i] = (pref_a[i - 1] + a[i - 1]);
    }
    for (int i = 1; i < pref_b.size(); ++i){
        pref_b[i] = (pref_b[i - 1] + b[i - 1]); 
    }
    int q;
    cin >> q;
    while (q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--,l2--;
        int fir = (pref_a[r1] - pref_a[l1])%3;
        int sec = (pref_b[r2] - pref_b[l2])%3;
        if (sec == fir){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}