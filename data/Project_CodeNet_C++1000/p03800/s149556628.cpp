#include <iostream>
#include <string>

#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void){
    int i,n;
    string s, output;
    string ans = "-1";
    output = "";
    cin >> n;
    cin >> s;
    s += s[0];
    s += s[1];
    
    output = "SS";
    for(i=1;i<=n;i++){
        if(output[i]=='S'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            }
            else{
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            } 
        }else if(output[i]=='W'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            }
            else{
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            } 
        }
    }
    if(output[0]==output[n] && output[1] == output[n+1]) ans = output.substr(0,n);
    /*
    if(output[n-1]=='S'){
        if((s[n-1]=='o'&&output[n-2]==output[0] || s[n-1]=='x'&&output[n-2]!=output[0]) && (s[0]=='o'&&output[n-1]==output[1] || s[0]=='x'&&output[n-1]!=output[1])) ans=output;
    }else{
        if((s[n-1]=='x'&&output[n-2]==output[0] || s[n-1]=='o'&&output[n-2]!=output[0]) && (s[0]=='x'&&output[n-1]==output[1] || s[0]=='o'&&output[n-1]!=output[1])) ans=output;
    }
    */
    
    
    output = "SW";
    for(i=1;i<=n;i++){
        if(output[i]=='S'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            }
            else{
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            } 
        }else if(output[i]=='W'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            }
            else{
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            } 
        }
    }
    if(output[0]==output[n] && output[1] == output[n+1]) ans = output.substr(0,n);
    
    output = "WS";
    for(i=1;i<=n;i++){
        if(output[i]=='S'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            }
            else{
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            } 
        }else if(output[i]=='W'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            }
            else{
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            } 
        }
    }
    if(output[0]==output[n] && output[1] == output[n+1]) ans = output.substr(0,n);
            
    output = "WW";
    for(i=1;i<=n;i++){
        if(output[i]=='S'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            }
            else{
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            } 
        }else if(output[i]=='W'){
            if(s[i]=='o'){
                if(output[i-1]=='S') output += 'W';
                else output += 'S';
            }
            else{
                if(output[i-1]=='S') output += 'S';
                else output += 'W';
            } 
        }
    }
    if(output[0]==output[n] && output[1] == output[n+1]) ans = output.substr(0,n);
    
    
    cout << ans << endl;
    return 0;
}
