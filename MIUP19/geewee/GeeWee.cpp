#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;


int main ()
{
    ll Dl, Dh, X, a, b, m, E, j, p, l;
    ll jumpDistance = 0, place = 1, direction = 1;
    ll FORWARD = 1, BACKWARD = -1;
    ll totalDist = 0, totalEn = 0;
    string path;
    
    bool alive = false;
    
    cin >> Dl >> Dh >> X >> a >> b >> m >> E >> j >> p >> l;
    cin >> path;
    
    if(E > 0){
        alive = true;
    }
    
    
    char checker = path[place - 1];
    
    while(alive){
        
        X = ((a * X) + b) % m;
        jumpDistance = Dl + (X % (Dh - Dl + 1));
        
        if (checker == 'P'){
            path[place - 1] = '.';
            E += p;
        }
        
        if(E >= j){
            if(direction == FORWARD){
                
                place += jumpDistance;
                if(place > l+1){
                    ll dif = place - (l+1);
                    jumpDistance -= dif;
                    place = l+1;
                }
                
                totalDist += jumpDistance;
                totalEn += j;
                E -= j;
                
                if(place != (l+1)){
                    checker = path[ place - 1 ];
                    
                    if (checker == 'D'){
                        direction = BACKWARD;
                    }
                }
                
                
                
            } else if (direction == BACKWARD) {
                
                place -= jumpDistance;
                if(place < 1){
                    ll dif = 1 - place;
                    jumpDistance -= dif;
                    place = 1;
                }
                
                totalDist += jumpDistance;
                totalEn += j;
                E -= j;
                
                checker = path[ place - 1 ];
                
                if (checker == 'D'){
                    direction = BACKWARD;
                } else {
                    direction = FORWARD;
                }
            }
  
            } else {
                totalEn += E;
                E = 0;
                alive = false;
            }
        
        
        if(E <= 0){
            alive = false;
            break;
        } else if (place == l+1){
            alive = true;
            break;
        }
        

    }
    
    if(alive){
        cout << totalDist << '\n' << totalEn << '\n' << "yes\n";
    } else {
        cout << totalDist << '\n' << totalEn << '\n' << "no\n";
    }
    return 0;
    
    
}