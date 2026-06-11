#include <iostream>
#include <string>
using namespace std;

int main(){
    string w;
    cin >> w;
    int n=w.length();
    int i,j;
    int check=0;

    for(i=0; i<n; i++){
        j=i;
        if(w[i]!=0){
            while(1){
                j++;
                if(w[j]!=0){
                    if(w[i]==w[j]){
                        w[j]=0;
                        break;
                    }
                }
                if(j==n){
                    check=1;
                    break;
                }
            }
        }
    }

    if(check==1){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;

    return 0;
}