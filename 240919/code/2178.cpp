#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  int a[100][100];
  bool vis[100][100];
  string tmpin[100];
  queue<pair<int, pair<int, int>>> q;
  int x[4] = {-1, 0, 1, 0};
  int y[4] = {0, -1, 0, 1};
  vis[0][0] = true;
  q.push({1, {0, 0}});
  int testcnt=1;

  cin >> n >> m;

  for(int i=0; i<n; i++){
    cin>>tmpin[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      a[i][j] = tmpin[i][j] - 48;
    }
  }

  while (!q.empty())
  { 
    pair<int,pair<int,int>> tmp = q.front();
    if(tmp.second.first == n-1 && tmp.second.second == m-1){
      cout<<tmp.first;
      break;
    }
    q.pop();
    for(int i=0; i<4; i++){
      int tmpx = tmp.second.first + x[i];
      int tmpy = tmp.second.second + y[i];
      int tmpcnt = tmp.first;

      if(tmpx < 0 || tmpy < 0 || tmpx > n-1 || tmpy > m-1){
        continue;
      }

      if(vis[tmpx][tmpy] || a[tmpx][tmpy] != 1){
        continue;
      }

      tmpcnt += 1;
      q.push({tmpcnt,{tmpx, tmpy}});
      vis[tmpx][tmpy] = true;
    }
  }
}