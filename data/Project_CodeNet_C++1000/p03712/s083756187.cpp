    #include <bits/stdc++.h>
    using namespace std;
     
    #define rep(i,n) for (int i = 0; i < (int)(n);i++)

    int main() {
        int h,w,i,j;
        char input[100][100];
        cin >> h >> w;
        for(int j=0;j<h;j++){
            for(int i=0;i<w;i++){
                cin >> input[i][j];
            }
        }
        for(j=0;j<h;j++){
            if(j==0){
                for(int k=0;k<w+2;k++)
                    cout << '#';
                cout << endl;
            }
            for(i=0;i<w;i++){
                if(i==0){
                    cout << '#' << input[i][j];
                }else{
                    cout << input[i][j];
                }
            }
            cout << '#' << endl;
            if(j==h-1){
                for(int k=0;k<w+2;k++)
                    cout << '#';
                cout << endl;
            }
        }
        }