 #include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0,k=0;
    cin >> n >> k;
    map<int,bool>m;
    int x;
    for(int i=0;i<k;i++){
        cin >> x;
        m[x]=true;
    }
    int N = n;
    while(1){
        string str = to_string(N);
        bool flag = false;
        for(char ch:str){
            int x = ch - '0';
            if(m[x]==true){
                flag = true;
            }
        }
        if(flag==false){
            break;
        }
        N++;
    }
    cout << N << endl;

}
