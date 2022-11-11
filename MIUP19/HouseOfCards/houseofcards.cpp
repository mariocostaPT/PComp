#include <bits/stdc++.h>

using namespace std;

#define ll long long




ll solve(ll n) {
    return (n*(3*n + 1))/2;
};

int main(){

//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    ll N;

    cin >> N;
    if (N == 0 || N == 1){
        cout << 0 << '\n';
        return 0;
    }


    ll i = 1, solver = 0;
    
    while(true){
        solver = solve(i);
        if (N <= solver){
            break;
        }
        i+=2;
    }

    if(N == solver){
        cout << i << '\n';
    } else if (N >= solve(i-1)){
        cout << (i-1) << '\n';
    } else {
        cout << (i-2) << '\n';
    }

    return 0;
}
