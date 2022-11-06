#include <bits/stdc++.h>

using namespace std;


int main ()
{
    char w;
    int n;
    
    std::vector<int> sequence;
    std::vector<int> subarray;
    
    // 1 . n 2. start 3. end. 4.sumActual 5. sumMax
    int indexer[4] = {0, 0, 0, 0};
    
    cin >> w >> n;
    indexer[0] = 0;
    indexer[3] = n;
    int max[3] = {0, 0, n};
    sequence.push_back(n);
    
    bool running = true;
    
    
    do {
        
        
        cin >> w;

        
        if (w == 'u'){
            indexer[0] = indexer[0] + 1;
            cin >> n;
            sequence.push_back(n);
            int sum = indexer[3] + n;
            if ( sum > n ){
                indexer[3] = sum;
                indexer[2] = indexer[0];
            } else {
                indexer[3] = n;
                indexer[1] = indexer[0];
                indexer[2] = indexer[0];
            }
            
            if(max[2] <= indexer[3]){
                max[0] = indexer[1];
                max[1] = indexer[2];
                max[2] = indexer[3];
            }
        } else if(w == 'q') {
            if( max[0] == max[1]){
                cout << max[0] << " " <<max[1] << " " << sequence[max[0]] << '\n';
            } else {
                subarray.clear();
                
                for (int i = max[0] ; i <= max[1] ; i++){
                    
                    subarray.push_back( sequence[i] );
                    
                }
                
                auto n = subarray.size() / 2;
                
                nth_element(subarray.begin(), subarray.begin()+n, subarray.end());
                
                auto median = subarray[n];
                
                cout << max[0] << ' ' << max[1] << ' ' << median << '\n';
            }
        } else if (w == 'x') {
            running = false;
        }
        
    } while(running);
    
    return 0;
    
}
