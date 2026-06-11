#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    cin >> n >> s;
    vector<string> ani(4, "S");
    vector<char> anilast(4, 'S');
    vector<bool> ansani(4, true);

    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            if(s.at(i) == 'o') {
                ani.at(0).push_back('S');
                ani.at(1).push_back('W');
                anilast.at(1) = 'W';
                ani.at(2) = "WS";
                anilast.at(2) = 'W';
                ani.at(3) = "WW";
            }else {
                ani.at(0).push_back('S');
                anilast.at(0) = 'W';
                ani.at(1).push_back('W');
                ani.at(2) = "WS";
                ani.at(3) = "WW";
                anilast.at(3) = 'W';
            }
        }else {
            for(int j = 0; j < 4; ++j) {
                if(i == n-2) {
                    if(ani.at(j).at(i) == 'S') {
                        if(s.at(i) == 'o') {
                            if(ani.at(j).at(i-1) == 'S') {
                                if(anilast.at(j) != 'S') {
                                    ansani.at(j) = false;
                                }
                            }else {
                                if(anilast.at(j) != 'W') {
                                    ansani.at(j) = false;
                                }
                            }
                        }else {
                            if(ani.at(j).at(i-1) == 'S') {
                                if(anilast.at(j) != 'W') {
                                    ansani.at(j) = false;
                                }
                            }else {
                                if(anilast.at(j) != 'S') {
                                    ansani.at(j) = false;
                                }
                            }
                        }
                    }else {
                        if(s.at(i) == 'o') {
                            if(ani.at(j).at(i-1) == 'S') {
                                if(anilast.at(j) != 'W') {
                                    ansani.at(j) = false;
                                }
                            }else {
                                if(anilast.at(j) != 'S') {
                                    ansani.at(j) = false;
                                }
                            }
                        }else {
                            if(ani.at(j).at(i-1) == 'S') {
                                if(anilast.at(j) != 'S') {
                                    ansani.at(j) = false;
                                }
                            }else {
                                if(anilast.at(j) != 'W') {
                                    ansani.at(j) = false;
                                }
                            }
                        }
                    }
                }else if(i == n-1) {
                    if(s.at(i) == 'o') {
                        if(anilast.at(j) == 'S') {
                            if(ani.at(j).at(i-1) != ani.at(j).at(0)) {
                                ansani.at(j) = false;
                            }
                        }else {
                            if(ani.at(j).at(i-1) == ani.at(j).at(0)) {
                                ansani.at(j) = false;
                            }
                        }
                    }else {
                        if(anilast.at(j) == 'S') {
                            if(ani.at(j).at(i-1) == ani.at(j).at(0)) {
                                ansani.at(j) = false;
                            }
                        }else {
                            if(ani.at(j).at(i-1) != ani.at(j).at(0)) {
                                ansani.at(j) = false;
                            }
                        }
                    }
                }else {
                    if(ani.at(j).at(i) == 'S') {
                        if(s.at(i) == 'o') {
                            if(ani.at(j).at(i-1) == 'S') {
                                ani.at(j).push_back('S');
                            }else {
                                ani.at(j).push_back('W');
                            }
                        }else {
                            if(ani.at(j).at(i-1) == 'S') {
                                ani.at(j).push_back('W');
                            }else {
                                ani.at(j).push_back('S');
                            }
                        }
                    }else {
                        if(s.at(i) == 'o') {
                            if(ani.at(j).at(i-1) == 'S') {
                                ani.at(j).push_back('W');
                            }else {
                                ani.at(j).push_back('S');
                            }
                        }else {
                            if(ani.at(j).at(i-1) == 'S') {
                                ani.at(j).push_back('S');
                            }else {
                                ani.at(j).push_back('W');
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < 4; ++i) {
        if(ansani.at(i)) {
            cout << ani.at(i) << anilast.at(i) << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}