#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

/*

int main(){
    string S;
    cin >> S;
    int N = (int)S.size();

    //右側からチェックしていく
    for(int i = N-1; i >= 0; i--){
        string t;

        //dreamer check
        if(i-7+1 >= 0){
            t = S.substr(i-7+1 ,7);
            if(t == "dreamer"){
                i -= 6;
                continue;
            }
        }

        //eraser check
        if(i-6+1 >= 0){
            t = S.substr(i - 6 + 1, 6);
            if (t == "eraser"){
                i -= 5;
                continue;
            }
        }

        //dream and erase check
        if(i-5+1 >= 0){
            t = S.substr(i - 5 + 1, 5);
            if (t == "dream" || t == "erase"){
                i -= 4;
                continue;
            }
        }

        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}

*/

int main(){
    string S;
    cin >> S;

    int N = (int)S.size();

    reverse(S.begin(), S.end());

    const string dreamer = "remaerd";
    const string dream = "maerd";
    const string eraser = "resare";
    const string erase = "esare";

    rep(i, N){
        //dreamer check
        if(i < N){
            string t = S.substr(i, 7);
            if(t == dreamer){
                i+=6;
                continue;
            }
        }
        //eraser check
        if(i < N){
            string t = S.substr(i, 6);
            if(t == eraser){
                i+=5;
                continue;
            }
        }
        //dream and erase check
        if(i < N){
            string t = S.substr(i, 5);
            if(t == erase || t == dream){
                i+=4;
                continue;
            }
        }

        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}