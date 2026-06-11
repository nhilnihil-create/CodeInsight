#include <iostream>
using namespace std;
int main()
{
    int r,c;
    cin >> r >> c;
    char arr[r][c];
    char aaa[r][c];
    char bbb[r][c];
    for (int i =0;i<r;i++){
        for (int j =0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            aaa[i][j]=arr[i][j];
            bbb[i][j]=arr[i][j];
        }
    }
    for (int i =0;i<r;i++){
        for (int j=0;j<c;j++){
            cout<<aaa[i][j];
        }
        cout<<endl;
         for (int j=0;j<c;j++){
            cout<<bbb[i][j];
        }
        cout<<endl;
    }

    return 0;
}
