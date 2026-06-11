#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;


const int SIZE = 1e2+100;

ll h,w;
string s[SIZE];
ll cou[30];

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s[i];
        for(int j = 0; j < s[i].length(); j++){
            ++cou[s[i][j]-'a'];
        }
    }
    int mm = h*w;

    int f = 0;
    if(h % 2 == 0 && w%2 == 0){
        int hitu = h*w/4;
        for(int i = 0; i < 30; i++){
            if(cou[i] % 4 != 0){
                f = 2;
                break;
            }
        }
        if(f != 2)  f = 1;
    }
    else if((h%2 == 0 && w%2 == 1) || (h%2 == 1 && w%2 == 0)){
        int ki,gu;
        if(h%2 == 1){
            ki = h;
            gu = w;
        }
        else{
            ki = w;
            gu = h;
        }
        int hitu_ni = gu/2;
        int hitu_yon = h*w-hitu_ni;

        int yon = 0, niko = 0;

        for(int i = 0; i < 30; i++){
            if(cou[i] %2 == 1){
                f = 2;
                break;
            }
            if(cou[i] % 4 == 0){
                ++yon;
            }
            else{
                ++niko;
            }
        }

        if(f == 0){
            if(niko <= hitu_ni){
                hitu_ni -= niko;
                if(hitu_ni%2 == 0)  f = 1;
            }
        }
    }
    else{
        int yon = 0, ichi = 0, niko = 0;
        int hitu_yon = (h*w-1-h+1-w+1)/4;
        int hitu_ni = (h-1+w-1)/2;

        for(int i = 0; i < 30; i++){
            if(cou[i] % 2 == 1){
                ++ichi;
            }
            else{
                if(cou[i] % 4 == 0){
                    ++yon;
                }
                else{
                    ++niko;
                }
            }
        }

        if(ichi == 1){
            if(niko <= hitu_ni){
                hitu_ni -= niko;
                if(hitu_ni%2 == 0)  f = 1;
            }
        }
    }

    if(f == 1){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}