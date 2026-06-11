/*
偶数項を正とする場合と
奇数項を正とする場合の２通りを
シミュレーションする.
どちらも試してみて、手数が小さい方を答えとする.
https://jpliterature.hatenablog.com/entry/abc059-c-sequence
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // 奇数項を正の値にする
    long long minA = 0, sumA = 0;
    
    for (int i = 0; i < n; i++){
        sumA += a[i];
        if (i % 2 == 0){
            if (sumA <= 0){
                minA += abs(sumA) + 1;
                sumA += abs(sumA) + 1;
            }
        }
        else{
            if (sumA >= 0){
                minA += abs(sumA) + 1;
                sumA -= abs(sumA) + 1;
            }
        }
    
    }
   
    // 偶数項を正の値にする
    long long minB = 0, sumB = 0;
    
    for (int i = 0; i < n; i++){
        sumB += a[i];
        if (i % 2 != 0){
            if (sumB <= 0){
                minB += abs(sumB) + 1;
                sumB += abs(sumB) + 1;
            
            }
        }
        else{
            if (sumB >= 0){
                minB += abs(sumB) + 1;
                sumB -= abs(sumB) + 1;
            }
        }
    }
    
    
    long long ans = min(minA, minB);
    cout << ans << endl;
}