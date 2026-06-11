#include<iostream>
#include<string>

using namespace std;

int32_t get_num_32(void){
    int32_t x;
    scanf("%d",&x);
    return x;
}


int main(void){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    int H,W;
    H = get_num_32();
    W = get_num_32();
    string a;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> a;
            //cout << a << endl;
            if(a == "snuke"){
                cout << (char)(j+'@') << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}
