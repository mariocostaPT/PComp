#include <bits/stdc++.h>

using namespace std;

int main ()
{

  int count = 0, n;
  int a1 , a2 , a3 ;
  scanf ("%d", &n);

  char s[12];
  for (int x = 0; x < n; x++)
    {
      scanf ("%d %d %d", &a1, &a2, &a3);
      

      if(a1){
          if (a2 || a3){
              count++;
          }
      } else if (a2  && a3 ) {
          count++;
      }
    }
    
    printf("%d", count);



  return 0;
}
