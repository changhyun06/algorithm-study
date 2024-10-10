#include <iostream>

using namespace std;

int main()
{
  int n, m;
  string s[50];
  int cnt = 0;
  int min = 0;

  cin >> n >> m;

  min = n * m;

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  for (int k = 0; k < n - 7; k++)
  {
    for (int h = 0; h < m - 7; h++)
    {
      cnt = 0;

      for (int i = k; i < k+8; i++)
      {
        for (int j = h; j < h+8; j++)
        {
          if (i % 2 == 0)
          {
            if (j % 2 == 0)
            {
              if (s[i][j] != 'B')
              {
                cnt++;
              }
            }
            else
            {
              if (s[i][j] != 'W')
              {
                cnt++;
              }
            }
          }
          else
          {
            if (j % 2 == 0)
            {
              if (s[i][j] != 'W')
              {
                cnt++;
              }
            }
            else
            {
              if (s[i][j] != 'B')
              {
                cnt++;
              }
            }
          }
        }
      }

      if (min > cnt)
      {
        min = cnt;
      }

      cnt = 0;

      for (int i = k; i < k+8; i++)
      {
        for (int j = h; j < h+8; j++)
        {
          if (i % 2 == 0)
          {
            if (j % 2 == 0)
            {
              if (s[i][j] != 'W')
              {
                cnt++;
              }
            }
            else
            {
              if (s[i][j] != 'B')
              {
                cnt++;
              }
            }
          }
          else
          {
            if (j % 2 == 0)
            {
              if (s[i][j] != 'B')
              {
                cnt++;
              }
            }
            else
            {
              if (s[i][j] != 'W')
              {
                cnt++;
              }
            }
          }
        }
      }

      if (min > cnt)
      {
        min = cnt;
      }
    }
  }

  cout << min;
}