#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n,A,B;
    string s;
    int cnt = 0;
    int cnt2 = 0;
    cin >> n >> A >> B >> s;
    rep(i,0,s.size()){
        if(s.at(i)=='a'){
            if(cnt<A+B){
                cout << "Yes" << endl;
                cnt++;
            }else{
                cout << "No" << endl;
            }
        }else if(s.at(i)=='b'){
            if(cnt<A+B&&cnt2<B){
                cout << "Yes" << endl;
                cnt++;
                cnt2++;
            }else{
                cout << "No" << endl;
            }

        }else{
            cout << "No" << endl;
        }
    }
}