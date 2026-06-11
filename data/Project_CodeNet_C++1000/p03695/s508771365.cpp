#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    int n;
    cin >> n;
    vector<bool> color(8, false);
    int m = 0, highest = 0;
    for(int i = 0; i < n; i++){
        int rate;
        cin >> rate;
        if(rate <= 399) color[0] = true;
        else if(rate <= 799) color[1] = true;
        else if(rate <= 1199) color[2] = true;
        else if(rate <= 1599) color[3] = true;
        else if(rate <= 1999) color[4] = true;
        else if(rate <= 2399) color[5] = true;
        else if(rate <= 2799) color[6] = true;
        else if(rate <= 3199) color[7] = true;
        else highest++;
    }

    for(int i = 0; i < 8; i++){
        if(color[i] == true){
            m++;
        }
    }
    cout << max(1, m) << " " << m+highest << endl;
    return 0;
}
