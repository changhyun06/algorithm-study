#include <iostream>
#include <queue>

using namespace std;

int main() {
  int t, n,m,k;
  int x,y;
  int cnt = 0;
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {-1, 0, 1, 0};

  cin>>t;

  for(int i=0; i<t; i++){
    cin>>m>>n>>k;
    cnt=0;
    int a[50][50] = {0,};
    bool vis[50][50] = {0,};
    queue<pair<int,int>> q;

    for(int j=0; j<k; j++){
      cin>>x>>y;
      a[x][y] = 1;
    }

    for(int j=0; j<m; j++){
      for(int h=0; h<n; h++){

        if(vis[j][h] || a[j][h] != 1){
          continue;
        }

        q.push({j,h});
        cnt++;

        while(!q.empty()){
          pair<int,int> tmp = q.front();
          q.pop();

          for(int z=0; z<4; z++){
            int tmpx = tmp.first + dx[z];
            int tmpy = tmp.second + dy[z];

            if(tmpx < 0 || tmpy < 0 || tmpx > m-1 || tmpy > n-1 ){
              continue;
            }

            if(vis[tmpx][tmpy] || a[tmpx][tmpy] != 1){
              continue;
            }

            q.push({tmpx,tmpy});
            vis[tmpx][tmpy] = true;

          }

        }
      }
    }

    cout<<cnt<<'\n';
  }
}