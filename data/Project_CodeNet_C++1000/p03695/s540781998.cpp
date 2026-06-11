#include <bits/stdc++.h>
using namespace std;

int main(){
    int rating[][2] = {{1, 399}, {400, 799}, {800, 1199}, {1200, 1599}, {1600, 1999}, {2000, 2399}, {2400, 2799}, {2800, 3199}};
    int cnt[10];
    int n;

    for(int i=0; i<10; i++) cnt[i] = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if(tmp < 3200){
            for(int j=0;j<8;j++){
                if(rating[j][0]<=tmp && tmp<=rating[j][1])
                    cnt[j]++;
            }
        }else{
            cnt[8]++;
        }
    }
     
    int base = 0;
    for(int i=0; i<8; i++){
        if(cnt[i]>0) base++;
    }
    
    if(base==0){
        cout << 1 << " " << cnt[8] << "\n";
    }else{
        cout << base << " " << base+cnt[8] << "\n";
    }
}