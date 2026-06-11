#include <bits/stdc++.h>

using namespace std;

int main()
{
      int ti = clock();

    int H, W;cin >> H >> W;
    vector<string> s;
    for(int i = 0;i < H;i++){
        string v;cin >> v;
        s.push_back(v);
    }
    map<char, int> mp;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            mp[s[i][j]]++;
        }
    }
    vector<int> ss;
    for(auto a : mp){
        int w = a.second;
        //cout<<a.first<<" "<<a.second<<endl;
        while(w > 3){
            //cout<<w<<endl;
            ss.push_back(0);
            w -= 4;
        }
        if(w != 0)ss.push_back(w);
    }
    vector<int> w;
    if(H % 2 == 0 && W % 2 == 0){
        for(int i = 0;i < H * W / 4;i++){
            w.push_back(0);
        }
    }else
    if(H % 2 == 1 && W % 2 == 0){
        for(int i = 0;i < (H - 1) * W / 4;i++){
            w.push_back(0);
        }
        for(int i = 0;i < W / 2;i++){
            w.push_back(2);
        }
    }else
    if(H % 2 == 0 && W % 2 == 1){
        for(int i = 0;i < H * (W - 1) / 4;i++){
            w.push_back(0);
        }
        for(int i = 0;i < H / 2;i++){
            w.push_back(2);
        }
    }else
    if(H % 2 == 1 && W % 2 == 1){
        for(int i =0 ;i < (H - 1) * (W - 1) / 4;i++){
            w.push_back(0);
        }
        for(int i = 0;i < H / 2;i++){
            w.push_back(2);
        }
        for(int i = 0;i < W / 2;i++){
            w.push_back(2);
        }
        w.push_back(1);
    }
    map<int, int> A, B;
    for(int a : ss)A[a]++;
    for(int b : w)B[b]++;
    /*
    for(auto a : A)
        cout<<a.first<<" "<<a.second<<endl;
    for(auto b : B)
        cout<<b.first<<" "<<b.second<<endl;
        */
    while(A[2] < B[2]){
        if(A[0] > B[0]){
            A[0]--;
            A[2]+=2;
        }
      if(1.0 * (clock() - ti) / CLOCKS_PER_SEC >= 1.0){
        cout<<"No"<<endl;
        return 0;
      }
    }
    /*
    for(auto a : A)
        cout<<a.first<<" "<<a.second<<endl;
    for(auto b : B)
        cout<<b.first<<" "<<b.second<<endl;
        */
    if(A == B){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
