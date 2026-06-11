#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

//0 -> S
//1 -> W
int main()
{
    int N;cin >> N;
    string str;cin >> str;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            vector<bool> v(N);
            v[0] = i;
            v[1] = j;
            for(int k = 2;k < N;k++){
                if(!v[k - 1] && str[k - 1] == 'o'){
                    v[k] = v[k - 2];
                }
                if(!v[k - 1] && str[k - 1] == 'x'){
                    v[k] = !v[k - 2];
                }
                if(v[k - 1] && str[k - 1] == 'o'){
                    v[k] = !v[k - 2];
                }
                if(v[k - 1] && str[k - 1] == 'x'){
                    v[k] = v[k - 2];
                }
            }
            bool result = true;
            for(int k = 0;k < N;k++){
                if(!v[k]){
                    if(k == 0){
                        if(str[k] == 'o'){
                            if(v.back() != v[1]){
                                result = false;
                            }
                        }else{
                            if(v.back() == v[1]){
                                result = false;
                            }
                        }
                    }else{
                        if(str[k] == 'o'){
                            if(v[k - 1] != v[(k + 1)%N]){
                                result = false;
                            }
                        }else{
                            if(v[k - 1] == v[(k + 1) %N]){
                                result = false;
                            }
                        }
                    }
                }else{
                    if(k == 0){
                        if(str[k] == 'o'){
                            if(v.back() == v[1]){
                                result = false;
                            }
                        }else{
                            if(v.back() != v[1]){
                                result = false;
                            }
                        }
                    }else{
                        if(str[k] == 'o'){
                            if(v[k - 1] == v[(k + 1)%N]){
                                result = false;
                            }
                        }else{
                            if(v[k - 1] != v[(k + 1) %N]){
                                result = false;
                            }
                        }
                    }
                }
            }
            if(result){
                for(auto a : v)cout<<(a ? 'W' : 'S');
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}
