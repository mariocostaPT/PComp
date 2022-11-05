#include <bits/stdc++.h>

#define uc unsigned char

using namespace std;

int main() {
    uc x;
    scanf("%d", &x);
    
    if (x == 2){
        printf("NO\n");
        return 0;
    }
    
    x = x & 0x0001;
    
    if (x == 0){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    
    return 0;
}