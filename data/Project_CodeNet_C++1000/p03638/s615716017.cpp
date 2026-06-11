#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int h, w, n;
    int nh=1;
    int nw=1;
    int k=0;
    
    cin >> h >> w;
    cin >> n;
    
    vector<int> a(n+1);
    int ans[109][109]={};
    
    for(int i=1; i<=n; i++){
        
        cin >> a.at(i);
        
    }
    
    for(int i=1; i<=n; i++){
        
        k = a.at(i);
        
        for(int j=1; j<=k; j++){
            
            ans[nh][nw] = i;
            
            if(nh%2==1){
                
                if(nw>=w){
                    
                    nh += 1;
                    
                } else {
                    
                    nw += 1;
                    
                }
                
            } else {
                
                if(nw<=1){
                    
                    nh += 1;
                    
                } else {
                    
                    nw -= 1;
                    
                }
                
            }
            
        }
        
    }
    
    for(int i=1; i<=h; i++){
        
        for(int j=1; j<=w; j++){
            
            cout << ans[i][j];
            
            if(j<w){
                
                cout << " ";
                
            }
            
        }
        
        cout << endl;
        
    }
    
    return 0;
    
}