#include<iostream>
#include<algorithm>
using namespace std;

int arr[205], stitle[205];

int main(){
    int maks = 0;
    string S;
    cin >> S;
    for(int i=0; i<S.length(); i++){
        arr[S[i] - 96]++;
        if (arr[S[i] - 96] > maks){
            maks = arr[S[i] - 96];
        }
        stitle[i] = S[i] - 96;
    }
    if(maks == 1){
        cout << S.length()/2 << endl;
    } else{
        int min = 201;
        for(int i=1; i<=26; i++){
            int jumlah = arr[i], cnt = 0;
            if(arr[i] != 0){
                int cstitle[205];
                for(int j=0; j<S.length(); j++){
                    cstitle[j] = stitle[j];
                }
                while(true){
                    bool hehe = true;
                    for(int j=0; j<S.length(); j++){
                        if(cstitle[j] != i && j <= S.length() - cnt - 1) hehe = false;
                        if(cstitle[j+1] == i && cstitle[j] != i){
                            jumlah++;
                            cstitle[j] = i;
                        }
                    }
                    if(hehe) break;
                    cnt++;
                }
                if (cnt < min){
                    min = cnt;
                }
            }
        }
        cout << min << endl;
    }
}