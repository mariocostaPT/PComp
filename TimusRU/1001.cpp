//TIMUS problem 1001

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    //time sinks
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    vector<double> x;
    string s, temp;
    
    while (getline(cin, s, '\n')){
        
        stringstream ss(s);
        while(getline(ss, temp,' ')){
            if (!temp.empty()){
                x.push_back( sqrt( stold(temp) ));
            }
        }

    };

    while(!x.empty()){
        printf("%.4f\n", x.back());
        x.pop_back();
    };
    
    return 0;
}
