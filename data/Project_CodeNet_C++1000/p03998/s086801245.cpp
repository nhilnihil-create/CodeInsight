#include <bits/stdc++.h>
using namespace std;

int main(){
	string S[3];
    long long cnt[3];
    long long tugi = 0;
    cin >> S[0] >> S[1] >> S[2];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    for(int i = 0; i < 300; i++) {
        if(cnt[tugi] == S[tugi].size()) {
            cout << (char)(tugi+'A') << endl;
            return 0;
        }
        cnt[tugi]++;
        tugi = S[tugi][cnt[tugi]-1]-'a';
    }
}