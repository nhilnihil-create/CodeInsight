#include<bits/stdc++.h>

using namespace std;

int main(){
    int l;
    long long ans,sum;
    string S,s_num;

    const int nmax = 10;
    cin >> S;
    l = (int)S.length();

    ans = 0;
    for(int i = 0;i < (1 << (l-1));i++){
        bitset<nmax> bit(i);
        sum = 0;
        s_num = "";
        int j = 0;
        while(j < l){
            s_num += S[j];
            if(bit.test(j)){
                sum += atol(s_num.c_str());
                s_num = "";
            }
            j++;
            if(j == l){
                sum += atol(s_num.c_str());
            }
        }
        ans += sum;
    }
    cout << ans << endl;
}