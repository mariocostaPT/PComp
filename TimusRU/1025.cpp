// Timus online 1025 "Democracy in danger"

#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    
    int g, q;
    std::vector<int> p;
    
    cin >> g;
    while (cin >> q){
        p.push_back(q);
    };
    
    sort(p.begin(), p.end());
    
    int i = 0, count = 0, needed = (g/2)+1;
    
    while(i < needed){
        count += ((p[i]/2) + 1);
        i++;
    }
    cout << count << '\n';
    
    return 0;
}
