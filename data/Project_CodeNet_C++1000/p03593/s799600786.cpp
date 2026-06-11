#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,W,four,two,one;
    cin >> H >> W;
    vector<string> a(H);
    map<char,int> mp;
    for(int i=0;i<H;i++){
        cin >> a[i];
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            mp[a[i][j]]++;
        }
    }

    if((H*W)%2==1){
        int one = 0,two=0,four=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]%2==1){
                mp[i]--;
                one++;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==2){
                mp[i]-=2;
                two+=2;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==0){
                mp[i]=0;
            }
        }

        if(one==1 && two<=H*W-(H-1)*(W-1)-1){
            for(int i=0;i<mp.size();i++){
                if(mp[i]!=0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

   
    if(H%2==1){
        int one = 0,two=0,four=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]%2==1){
                mp[i]--;
                one++;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==2){
                mp[i]-=2;
                two+=2;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==0){
                mp[i]=0;
            }
        }

        if(one==0 && two<=W){
            for(int i=0;i<mp.size();i++){
                if(mp[i]!=0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    if(W%2==1){
        int one = 0,two=0,four=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]%2==1){
                mp[i]--;
                one++;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==2){
                mp[i]-=2;
                two+=2;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==0){
                mp[i]=0;
            }
        }

        if(one==0 && two<=H){
            for(int i=0;i<mp.size();i++){
                if(mp[i]!=0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    if(W%2==0 && H%2==0){
        int one = 0,two=0,four=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]%2==1){
                mp[i]--;
                one++;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==2){
                mp[i]-=2;
                two+=2;
            }
        }

        for(int i=0;i<mp.size();i++){
            if(mp[i]%4==0){
                mp[i]=0;
            }
        }

        if(one==0 && two==0){
            for(int i=0;i<mp.size();i++){
                if(mp[i]!=0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
}