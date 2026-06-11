#include <iostream>
#include <cstdio>
using namespace std;


string delete_s(string s, char t){
    string ans;
    //printf("a\n");
    for(long long i = 0; i < s.size()-1; i++){
        if(s[i] == t || s[i+1] == t){
            ans.push_back(t);
        }
        else{
            ans.push_back(s[i]);
        }
    }

    //cout << "ans : " << ans << endl;

    return ans;
}

int main(){
    string s;
    cin >> s;

    long long min_ans = 100;

    for(long long i = 0; i < s.size(); i++){
        char delete_c = s[i];

        long long count = 0;
        string s2 = s;
        while(1){
            //cout << "s2 : " << s2 << endl;
            if(s2.find_first_not_of(delete_c) == string::npos){
                break;
            }
            s2 = delete_s(s2, delete_c);
            
            count++;
        }

        min_ans = min(min_ans, count);
    }

    cout << min_ans << endl;

    return 0;
}