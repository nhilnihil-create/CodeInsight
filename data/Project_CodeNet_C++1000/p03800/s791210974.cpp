#include <bits/stdc++.h>
using namespace std;
char tmp[1000010];
int n;
string s;

char re(char a){
    return a == 'S' ? 'W' : 'S';
}

int isisOK(int i){
    if(tmp[i] == 'S'){
        return (s[i] == 'o' ? tmp[(n+i-1)%n] == tmp[(i+1)%n] : tmp[(n+i-1)%n] != tmp[(i+1)%n]);
    }else{
        return (s[i] == 'x' ? tmp[(n+i-1)%n] == tmp[(i+1)%n] : tmp[(n+i-1)%n] != tmp[(i+1)%n]);
    }
}

bool isOK(int one, int two){
    tmp[0] = (one == 0 ? 'S' : 'W');
    tmp[1] = (two == 0 ? 'S' : 'W');

    for(int i = 1;i < n-1;i++){
        if(tmp[i] == 'S'){
            if(s[i] == 'o'){
                tmp[i+1] = tmp[i-1];
            }else{
                tmp[i+1] = re(tmp[i-1]);
            }
        }else{
            if(s[i] == 'x'){
                tmp[i+1] = tmp[i-1];
            }else{
                tmp[i+1] = re(tmp[i-1]);
            }
        }
    }

    return isisOK(n-1) && isisOK(0);
}

int main(){
    cin >> n >> s;

    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            if(isOK(i, j)){
                for(int x = 0;x < n;x++){
                    cout << tmp[x];
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}