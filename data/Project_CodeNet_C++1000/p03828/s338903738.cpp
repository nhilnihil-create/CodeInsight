#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int, int> cnt_map;//素数、約数の個数
    //iが数、jが約数,cnt_mapに約数とその個数が確保される
    for(int i=2; i<=N; i++){
        int tmp=i;
        for(int j=2; j<=i; j++){
            while(tmp%j == 0){
                cnt_map[j]++;
                tmp /= j;
            }
            //cout << cnt_map[2] << endl;
        }
    }
    long long pro=1, devide = ((long long)pow(10, 9) + 7);
    for(int i=2; i<=N; i++){
        pro *= (cnt_map[i] + 1);
        while(pro >= devide){
            pro -= devide;
        }
    }
    //long long result = pro % ((long long)pow(10, 9) + 7);
    cout << pro << endl;
}