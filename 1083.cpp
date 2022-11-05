//timus online 1083

#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, final;
    
    string s;
    
    cin >> n >> s;
    
    k = s.size();
    
    final = n;

    if (n % k == 0) {
        // divides  n!!…! = n(n−k)(n−2k)…k
        n -= k;
        while (n >= k){
            final *= n;
            n -= k;
        }
    } else {
        int r = n % k;
        n-= k;
        while (n >= r){
            final *= n;
            n -= k;
        }
    }
    
    cout << final;
    
    return 0;
}
