#include <iostream>
#include <vector>
using namespace std;

int main(){
    int h,w,n;
    vector<int> a;
    cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }

 //   vector<vector<int>> c(h);
    int c[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            //c[i].push_back(0);
            c[i][j]=0;
        }
    }

    int ith=0,itw=0;
    bool mode=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            c[ith][itw]=i+1;
            if(mode){
                if(itw<w-1) itw++;
                else if(itw==w-1){
                    ith++;
                    mode = !mode;
                }
            }else{
                if(itw>0) itw--;
                else if(itw==0){
                    ith++;
                    mode = !mode;
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << c[i][j];
            if(j==w-1) cout<<endl;
            else cout << " ";
        }
    }
}