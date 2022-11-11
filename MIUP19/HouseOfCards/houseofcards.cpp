#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define size(x) ((int)x.size())

const ll MAX_N = 10e15;

// a1 + (3x - 1)
int house(ll N, int i, ll prev){
    if (N < prev){
        return 0;
    } else {
        ll new_Prev = prev + ((3*i) - 1);
        return 1 + house(N, i++, new_Prev);
    }

}

ll solve(ll N){
    return 1 + house(N, 3, 7);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll N;

    cin >> N;

    if (N <= 0 || N == 1){
        cout << 0 << '\n';
    } else if (6 >= N && N >= 2){
        cout << 1 << '\n';
    } else {
        cout << solve(N) << '\n';
    }


    return 0;
}
