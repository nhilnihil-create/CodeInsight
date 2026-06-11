#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        int n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int cnt=0;
        int cntb=0;
        
        rep(i,s.size()){
            switch (s[i]){
            case 'a':
                if(cnt < a+b){
                cout << "Yes" << endl;
                cnt++;
                }
                else{
                    cout << "No" << endl;
                }
                break;
            case 'b':
            if(cnt<a+b && b > cntb){
                cout << "Yes" << endl;
                cnt++;
                cntb++;
            }
            else{
                cout  << "No" << endl;
            }
            
            break;
            case 'c':
            cout << "No" << endl;
            break;
            default:
                break;
            }
        }
        return 0;
    }