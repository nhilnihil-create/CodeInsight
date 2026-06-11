#include <bits/stdc++.h>
using namespace std;

const string YES = "YES";
const string NO = "NO";

void solve(std::string S){
    string ans;
    vector<string> unit_string = {"dream", "dreamer", "erase", "eraser"};
    for(int i = 0; i < 100000; ++i){
        //cout << S << endl;
        if(S.size() == 0){
            ans = YES;
            break;
        }
        else if(S.size() < 5 && S.size() > 0){
            ans = NO;
            break;
        }
        else if(S.size() == 5){
            string s5 = S.substr(S.size()-5, 5);
            bool check = true;
            for(auto t : unit_string){
                if(s5 == t){
                    S.erase(S.size()-5, 5);
                    check = false;
                    break;
                }
            }
            if(check){
                ans = NO;
                break;
            }
        }
        else if(S.size() == 6){
            string s6= S.substr(S.size()-6, 6);
            bool check = true;
            for(auto t : unit_string){
                if(s6 == t){
                    S.erase(S.size()-6, 6);
                    check = false;
                    break;
                }
            }
            if(check){
                ans = NO;
                break;
            }
        }
        else if(S.size() == 7){
            string s7 = S.substr(S.size()-7, 7);
            bool check = true;
            for(auto t : unit_string){
                if(s7 == t){
                    S.erase(S.size()-7, 7);
                    check = false;
                    break;
                }
            }
            if(check){
                ans = NO;
                break;
            }
        }
        else{
            string s5 = S.substr(S.size()-5, 5);
            string s6 = S.substr(S.size()-6, 6);
            string s7 = S.substr(S.size()-7, 7);
            bool check = true;
            for(auto t : unit_string){
                if(s5 == t){
                    S.erase(S.size()-5, 5);
                    check = false;
                    break;
                }
                else if(s6 == t){
                    S.erase(S.size()-6, 6);
                    check = false;
                    break;
                }
                else if(s7 == t){
                    S.erase(S.size()-7, 7);
                    check = false;
                    break;
                }
            }
            if(check){
                ans = NO;
                break;
            }
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
