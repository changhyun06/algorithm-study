#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int r, c;
  string a[1000];
  queue<pair<int, pair<int, int>>> q;
  pair<char,int> vis[1000][1000];
  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, -1, 0, 1};
  int min = 1000;

  cin >> r >> c;

  for (int i = 0; i < r; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (a[i][j] == 'J' || a[i][j] == 'F')
      {
        q.push({1, {i, j}});
        vis[i][j] = {a[i][j], 1};
        while (!q.empty())
        {
          pair<int, pair<int, int>> tmp = q.front();
          q.pop();
          for (int k = 0; k < 4; k++)
          {
            int tmpx = tmp.second.first + x[k];
            int tmpy = tmp.second.second + y[k];
            int tmptime = tmp.first;

            if (tmpx < 0 || tmpy < 0 || tmpx > r - 1 || tmpy > c - 1)
            {
              continue;
            }

            if (a[tmpx][tmpy] == '#')
            {
              continue;
            }
            
            if (a[i][j] == 'F' && vis[tmpx][tmpy].first == 'F' && vis[tmpx][tmpy].second < tmptime + 1 || vis[tmpx][tmpy].first == 'J' && vis[tmpx][tmpy].second < tmptime + 1)
            {
              continue;
            }
            
            if (a[i][j] == 'J' && vis[tmpx][tmpy].first == 'J' || vis[tmpx][tmpy].first == 'F' && vis[tmpx][tmpy].second <= tmptime + 1)
            {
              continue;
            }

            vis[tmpx][tmpy] = {a[i][j], tmptime + 1};
            q.push({tmptime + 1, {tmpx, tmpy}});
          }
        }
      }
    }
  }

  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(i==r-1 || i == 0 || j==c-1 || j == 0){
        if(vis[i][j].first == 'J'){
          if(min > vis[i][j].second){
            min = vis[i][j].second;
          }
        }
      }
    }
  }

  if(min != 1000){
    cout<<min;
  }
  else{
    cout<<"IMPOSSIBLE";
  }
}