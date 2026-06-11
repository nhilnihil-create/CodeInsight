#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int h,w; cin >> h >> w;
    int x,y;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            string s; cin >> s;
            if(s == "snuke"){
                x = i+1; y = j;
            }
        }
    }
    cout << char(y+'A') << x << endl;
    return 0;
}