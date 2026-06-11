#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    char c[h][w];
    map<char, int> m;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
            auto itr = m.find(c[i][j]);
            if(itr == m.end()){
                m[c[i][j]] = 1;
            }else{
                m[c[i][j]]++;
            }
        }
    }

    int flag = 0;
    if(h == 1 || w == 1){
        if(h == 1 && w != 1){
            int cou = 0;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                if(itr->second % 2 != 0){
                    if(w % 2 == 0){
                        flag = 1;
                        break;
                    }else{
                        cou++;
                    }
                }
                if(cou == 2){
                    flag = 1;
                    break;
                }
            }
        }else if(h != 1 && w == 1){
            int cou = 0;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                if(itr->second % 2 != 0){
                    if(h % 2 == 0){
                        flag = 1;
                        break;
                    }else{
                        cou++;
                    }
                }
                if(cou == 2){
                    flag = 1;
                    break;
                }
            }
        } 
    }else{
        if(h % 2 == 0 && w % 2 == 0){
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                if(itr->second % 4 != 0){
                    flag = 1;
                    break;
                }
            }
        }else if(h % 2 == 0){
            int cou = 0;
            int k = h / 2;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                if(itr->second % 4 != 0){
                    if(itr->second % 2 == 0){
                        cou += 2;
                        if(cou > h){
                            flag = 1;
                            break;
                        }
                    }else{
                        flag = 1;
                        break;
                    }
                }
            }
        }else if(w % 2 == 0){
            int cou = 0;
            int k = w / 2;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                if(itr->second % 4 != 0){
                    if(itr->second % 2 == 0){
                        cou += 2;
                        if(cou > w){
                            flag = 1;
                            break;
                        }
                    }else{
                        flag = 1;
                        break;
                    }
                }
            }
        }else{
            int cou = 0;
            int cou2 = 0;
            int k = h + w - 1;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                if(itr->second % 4 != 0){
                    if(itr->second % 2 == 0){
                        cou += 2;
                        if(cou > k){
                            flag = 1;
                            break;
                        }
                    }else{
                        cou2++;
                        if(cou2 >= 2){
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        
    }

    if(flag == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}