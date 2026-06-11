#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int s = S.size();
    int64_t ans = 0;

    for(int i=0;i<(1<<(s-1));i++){
        bitset<9> bit(i);

        int64_t sum = 0;
        int start = 0;

        for(int j=0;j<s-1;j++){
            if(bit.test(j)) {
                string t = S.substr(start ,j+1-start);
                int64_t a = stoll(t);
                sum += a;
                start = j+1;
            }
        }
        string t = S.substr(start ,s-start);
        int64_t a = stoll(t);
        sum += a;

        //cout << sum << endl;

        ans += sum;
    }

    cout << ans << endl;
}