#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    string s;
    cin >> s;
    vector<int> news = {0,0,0,0};
    rep(i,s.size()){
        if (s[i] == 'N'){
            news[0]++;
        }
        if (s[i] == 'E'){
            news[1]++;
        }
        if (s[i] == 'W'){
            news[2]++;
        }
        if (s[i] == 'S'){
            news[3]++;
        }
    }
    //p(news);
    if (news[0] > 0 && news[3] == 0){
        cout << "No";
    }
    else if (news[1] > 0 && news[2] == 0){
        cout << "No";
    }
    else if (news[2] > 0 && news[1] == 0){
        cout << "No";
    }
    else if (news[3] > 0 && news[0] == 0){
        cout << "No";
    }
    else cout << "Yes";
}

