#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    int che[26];
    for(int i = 0; i < 26; i++){
        che[i] = 0;
    }

    for(int i = 0; i < n; i++){
        che[s[i] - 'a']++;
    }
    int flag = 0;
    for(int i = 0; i < 26; i++){
        if(che[i] != 0){
            flag++;
        }
    }

    int ans = 100;
    if(flag != 1){
        for(int i = 0; i < 26; i++){
            if(che[i] != 0){
                int now = n - 1;
                string a = s;
                while(1){
                    string k;
                    int cou = 0;
                    for(int j = 0; j < now; j++){
                        if(a[j] == (char)(i + 'a') || a[j + 1] == (char)(i + 'a')){
                            if(s[j] == (char)(i + 'a')){
                                k += a[j];
                            }else{
                                k += a[j + 1];
                            }
                            cou++;
                        }else{
                            k += a[j];
                        }
                    }

                    if(cou == now){
                        break;
                    }else{
                        a = k;
                        now--;
                    }
                }

                if(ans > n - now){
                    ans = n - now;
                }
            }
        }

        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
}