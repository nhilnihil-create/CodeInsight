#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s;
    cin >> s;

    long long count_left = 0; 
    long long a = 0;

    for(long long i = 0; i < s.size(); i++){
        if(s[i] == '('){
            count_left++;
        }
        else{
            if(count_left == 0){
                a++;
            }
            else{
                count_left--;
            }
        }
    }

    long long count_right = 0; 
    long long b = 0;

    for(long long i = s.size()-1; i >= 0; i--){
        if(s[i] == ')'){
            count_right++;
        }
        else{
            if(count_right == 0){
                b++;
            }
            else{
                count_right--;
            }
        }
    }

    string ans;
    for(long long i = 0; i < a; i++){
        ans.push_back('(');
    }

    ans = ans + s;

    for(long long i = 0; i < b; i++){
        ans.push_back(')');
    }

    cout << ans << endl;

    return 0;
}