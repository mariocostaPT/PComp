// timus 1068 sum

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    
    int n;
    
    scanf("%d", &n);
    
    if (n == 0){
        printf("1\n");
    }else if (n == -1){
        printf("0\n");
    } else if (n > 0){
        printf("%d\n",  ((n * (n + 1))/2));
        
    } else {
        n = abs(n);
        printf("-%d\n",  ((n * (n + 1))/2) - 1);
    }
    
    return 0;
}
