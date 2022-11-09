#include <bits/stdc++.h>

using namespace std;

int main ()
{

  int n;
  scanf ("%d", &n);

  char s[100];
  std::vector < string > resposta;
  for (int x = 0; x < n; x++)
    {
      scanf ("%s", s);
      if (strlen (s) > 10)
	{
	  int tmp = strlen (s);
	  printf ("%c%d%c\n", s[0], tmp - 2, s[tmp - 1]);
	}
      else
	{
	  printf ("%s\n", s);
	}
    }
    
  return 0;
}
