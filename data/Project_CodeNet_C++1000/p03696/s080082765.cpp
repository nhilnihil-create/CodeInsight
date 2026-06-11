#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    int l = 0;
    int r = 0;
    int cnt = 0;
    for(int i=0; i<S.length(); i++){
        if(S[i] == '(') l++;
        else{
            r++;
            if(l == 0) continue;
            l--;
            cnt++;
        }
    }

    for(int i=0; i<r-cnt; i++){
        cout << '(';
    }
    cout << S;
    for(int i=0; i<l; i++){
        cout << ')';
    }
    cout << endl;

    return 0;
}
