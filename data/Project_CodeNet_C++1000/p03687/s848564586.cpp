#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 100100;
    {
        for(char ch = 'a'; ch <= 'z'; ch++){
            int costart = 0;
            int coans = 0;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == ch){
                    int cocoans = i - costart;
                    if(cocoans > s.length()-costart) cocoans = s.length()-costart;
                    if(coans < cocoans) coans = cocoans;
                    costart = i+1;
                }
            }
            if(costart != s.length()){
                int cocoans = s.length()-costart;
                if(coans < cocoans) coans = cocoans;
            }

            if(coans < ans) ans = coans;
        }
    }

    cout << ans << endl;
    return 0;
}