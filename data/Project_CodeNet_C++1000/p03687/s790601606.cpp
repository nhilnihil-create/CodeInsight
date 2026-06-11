#include <bits/stdc++.h>
#define REP(i, n) for(size_t i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;

    int minOp = INF; 

    vector<char> charset;
    REP(i, s.size()) charset.push_back(s[i]);
    

    
    for (auto c : charset){
        // cout << "working on " << c<< endl;
        int ct = 0;
        string tmp = s;
        bool done = true;
        REP(i, tmp.size()){
            if (tmp[i] != c){
                done = false;
                break;
            }
        }
        if (done) minOp = 0;

        while (!done){
            string tmp2 = "";
            REP(i, tmp.size()-1){
                if (tmp[i] == c || tmp[i+1] == c){ 
                    tmp2.push_back(c);
                }
                else{
                    tmp2.push_back(tmp[i]);
                }
                
            }
            tmp = tmp2;
            // cout << tmp << endl;
            done = true;
            REP(i, tmp.size()){
                if (tmp[i] != c){
                    done = false;
                    break;
                }
            }
            ct++;
        }

        if (ct < minOp) minOp = ct;
    }

    cout << minOp << endl;
    
}