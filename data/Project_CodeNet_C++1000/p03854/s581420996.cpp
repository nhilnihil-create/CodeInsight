#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    map<string, vector<string> > k;

    string S;
    cin >> S;

    int l = S.length();

    S += "..........";

    k["dream"].push_back("dream");
    k["dream"].push_back("erase");
    k["dream"].push_back("er");

    k["er"].push_back("dream");
    k["er"].push_back("erase");

    k["erase"].push_back("dream");
    k["erase"].push_back("erase");
    k["erase"].push_back("r");

    k["r"].push_back("dream");
    k["r"].push_back("erase");

    int pos = 5;

    string x;

    if(S[0] == 'e') {
        x = "erase";
    } else {
        x = "dream";
    }

    for(int i = 0; i < 5; i++) {
        if(S[i] != x[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    while(pos < l) {
        bool c = true;
        for(int i = 0; i < k[x].size(); i++) {
            bool checker = false;
            for(int j = 0; j < k[x][i].length(); j++) {
                if(S[pos + j] != k[x][i][j]) {
                    checker = true;
                    break;
                }
            }
            if(checker) continue;
            c = false;
            pos += k[x][i].length();
            x = k[x][i];
            cerr << x << endl;
            break;
        }
        if(c) {
            cout << "NO" << endl;
            return 0;
        }
        cerr << pos << endl;
    }

    cout << "YES" << endl;
}