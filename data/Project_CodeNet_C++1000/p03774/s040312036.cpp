#include <bits/stdc++.h>

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d ",x)
#define pl(x)	printf("%lld ",x)
#define ps(s)	printf("%s ",s)

using namespace std;

int distance(int x1, int x2, int y1, int y2){
    
    return abs(x1 - x2) + abs(y1 - y2);
}



int main(){
        
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>>a(n);
    vector<pair<int, int>>b(m);
    //cout << "A STARTS" << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        //cout << a[i].first << " " << a[i].second << endl; 
    }
    //cout << "B STARTS" << endl;
    for(int i = 0; i < m; i++){
        cin >> b[i].first >> b[i].second;
        //cout << b[i].first << " " << b[i].second << endl;
    }
    
    int current, previous;
    for(int i = 0; i < n; i++){
        current = INT_MAX;
        previous = current;
        int x1 = a[i].first;
        int y1 = a[i].second;
        int idx = 1 << 20;
        int x2, y2;
        for(int j = 0; j < m; j++){
            x2 = b[j].first;
            y2 = b[j].second;
            
            //pi(x1); pi(x2); pi(y1); pi(y2); cout << endl;
            current = distance(x1, x2, y1, y2);
            //cout << "I : " << i << " J : " << j << " " << current << endl; 
            if(current < previous){
                previous = current;
                idx = j+1;
            }
            else if(current == previous){
                idx = min(idx, j+1);
            }
            
        }
        cout << idx << endl;
    }
    
    
    
    
    
    
}
