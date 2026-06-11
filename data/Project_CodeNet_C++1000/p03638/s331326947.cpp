#include<iostream>

using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int c[h][w];
    int lst[h*w];
    int count = 0;
    int num;
    for (int i = 0; i < n; i++){
        num = a[i];

        for (int j = 0; j < num; j++){
            lst[count] = i+1;
            count++;
        }

    }

    // for (int i; i < h*w; i++){
    //     cout << lst[i] << " ";

    // }    
    // cout << "\n\n";

    count = 0;
    for (int i = 0; i < w; i++){
        if (i % 2 == 0){
            for (int j = 0; j < h; j++){
                c[j][i] = lst[count];
                count++;
            }
        }
        else{
            for (int j = h-1; j > -1; j--){
                c[j][i] = lst[count];
                count++;
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << c[i][j] << " "; 
        }
        cout << '\n';
        
    }
    
}