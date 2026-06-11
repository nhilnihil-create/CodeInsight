#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    string s;
    cin >> N >> s;

    vector<char> ans1(N,'x');
    ans1[0] = 'S';
    bool t1 = true;
    rep(idx,N) {
        int idx1 = (idx-1+N)%N;
        int idx2 = (idx+1)%N;
        if (idx==0) {
            if (s[idx]=='o') {
                ans1[idx2] = 'S';
                ans1[idx1] = 'S';
            }
            else {
                ans1[idx2] = 'S';
                ans1[idx1] = 'W';
            }
        }
        else {
            if (s[idx]=='o' && ans1[idx]=='S') {
                char next = ans1[idx1];
                if (ans1[idx2]!='x' && ans1[idx2]!=next) {
                    t1 = false;
                    break;
                }
                else ans1[idx2] = ans1[idx1];
            }
            else if (s[idx]=='x' && ans1[idx]=='S'){
                char next;
                if (ans1[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans1[idx2]!='x' && ans1[idx2]!=next) {
                    t1 = false;
                    break;
                }
                else ans1[idx2] = next;
            }
            else if (s[idx]=='x' && ans1[idx]=='W') {
                char next = ans1[idx1];
                if (ans1[idx2]!='x' && ans1[idx2]!=next) {
                    t1 = false;
                    break;
                }
                else ans1[idx2] = ans1[idx1];
            }
            else if (s[idx]=='o' && ans1[idx]=='W'){
                char next;
                if (ans1[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans1[idx2]!='x' && ans1[idx2]!=next) {
                    t1 = false;
                    break;
                }
                else ans1[idx2] = next;
            }
        }
    }

    vector<char> ans2(N,'x');
    ans2[0] = 'S';
    bool t2 = true;
    rep(idx,N) {
        int idx1 = (idx-1+N)%N;
        int idx2 = (idx+1)%N;
        if (idx==0) {
            if (s[idx]=='o') {
                ans2[idx2] = 'W';
                ans2[idx1] = 'W';
            }
            else {
                ans2[idx2] = 'W';
                ans2[idx1] = 'S';
            }
        }
        else {
            if (s[idx]=='o' && ans2[idx]=='S') {
                char next = ans2[idx1];
                if (ans2[idx2]!='x' && ans2[idx2]!=next) {
                    t2 = false;
                    break;
                }
                else ans2[idx2] = ans2[idx1];
            }
            else if (s[idx]=='x' && ans2[idx]=='S'){
                char next;
                if (ans2[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans2[idx2]!='x' && ans2[idx2]!=next) {
                    t2 = false;
                    break;
                }
                else ans2[idx2] = next;
            }
            else if (s[idx]=='x' && ans2[idx]=='W') {
                char next = ans2[idx1];
                if (ans2[idx2]!='x' && ans2[idx2]!=next) {
                    t2 = false;
                    break;
                }
                else ans2[idx2] = ans2[idx1];
            }
            else if (s[idx]=='o' && ans2[idx]=='W'){
                char next;
                if (ans2[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans2[idx2]!='x' && ans2[idx2]!=next) {
                    t2 = false;
                    break;
                }
                else ans2[idx2] = next;
            }
        }
    }

    vector<char> ans3(N,'x');
    ans3[0] = 'W';
    bool t3 = true;
    rep(idx,N) {
        int idx1 = (idx-1+N)%N;
        int idx2 = (idx+1)%N;
        if (idx==0) {
            if (s[idx]=='o') {
                ans3[idx2] = 'W';
                ans3[idx1] = 'S';
            }
            else {
                ans3[idx2] = 'S';
                ans3[idx1] = 'S';
            }
        }
        else {
            if (s[idx]=='o' && ans3[idx]=='S') {
                char next = ans3[idx1];
                if (ans3[idx2]!='x' && ans3[idx2]!=next) {
                    t3 = false;
                    break;
                }
                else ans3[idx2] = ans3[idx1];
            }
            else if (s[idx]=='x' && ans3[idx]=='S'){
                char next;
                if (ans3[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans3[idx2]!='x' && ans3[idx2]!=next) {
                    t3 = false;
                    break;
                }
                else ans3[idx2] = next;
            }
            else if (s[idx]=='x' && ans3[idx]=='W') {
                char next = ans3[idx1];
                if (ans3[idx2]!='x' && ans3[idx2]!=next) {
                    t3 = false;
                    break;
                }
                else ans3[idx2] = ans3[idx1];
            }
            else if (s[idx]=='o' && ans3[idx]=='W'){
                char next;
                if (ans3[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans3[idx2]!='x' && ans3[idx2]!=next) {
                    t3 = false;
                    break;
                }
                else ans3[idx2] = next;
            }
        }
    }

    vector<char> ans4(N,'x');
    ans4[0] = 'W';
    bool t4 = true;
    rep(idx,N) {
        int idx1 = (idx-1+N)%N;
        int idx2 = (idx+1)%N;
        if (idx==0) {
            if (s[idx]=='o') {
                ans4[idx2] = 'S';
                ans4[idx1] = 'W';
            }
            else {
                ans4[idx2] = 'W';
                ans4[idx1] = 'W';
            }
        }
        else {
            if (s[idx]=='o' && ans4[idx]=='S') {
                char next = ans4[idx1];
                if (ans4[idx2]!='x' && ans4[idx2]!=next) {
                    t4 = false;
                    break;
                }
                else ans4[idx2] = ans4[idx1];
            }
            else if (s[idx]=='x' && ans4[idx]=='S'){
                char next;
                if (ans4[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans4[idx2]!='x' && ans4[idx2]!=next) {
                    t4 = false;
                    break;
                }
                else ans4[idx2] = next;
            }
            else if (s[idx]=='x' && ans4[idx]=='W') {
                char next = ans4[idx1];
                if (ans4[idx2]!='x' && ans4[idx2]!=next) {
                    t4 = false;
                    break;
                }
                else ans4[idx2] = ans4[idx1];
            }
            else if (s[idx]=='o' && ans4[idx]=='W'){
                char next;
                if (ans4[idx1]=='W') next = 'S';
                else next = 'W';
                if (ans4[idx2]!='x' && ans4[idx2]!=next) {
                    t4 = false;
                    break;
                }
                else ans4[idx2] = next;
            }
        }
    }

    if (!t1 && !t2 && !t3 && !t4) {
        cout << -1 << endl;
    }
    else if (t1) {
        rep(i,N) {
            cout << ans1[i];
        }
        cout << endl;
    }
    else if (t2) {
        rep(i,N) {
            cout << ans2[i];
        }
        cout << endl;
    }
    else if (t3) {
        rep(i,N) {
            cout << ans3[i];
        }
        cout << endl;
    }
    else if (t4) {
        rep(i,N) {
            cout << ans4[i];
        }
        cout << endl;
    }

}
