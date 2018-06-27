#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 5;
int arr[N] = { 1, 2, 3, 4, 5 };

void Combi(int n, int r, int idx, string combi)
{
   if (combi.length() == r)
   {
      for (int i = 0; i < combi.length(); i++)
      {
         int idx = combi[i] - '0';
         printf("%d ", arr[idx]);
      }
      printf("\n");
      return;
   }

   if (N <= idx)
      return;

   Combi(n, r, idx + 1, combi + (char)(idx + '0'));
   Combi(n, r, idx + 1, combi);
}

int main()
{
   Combi(N, 3, 0, "");
   return 0;
}
