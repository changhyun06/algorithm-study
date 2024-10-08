#include <iostream>

using namespace std;

int main()
{
  int n;
  string s1, s2;

  cin >> n;

  cin >> s1;

  for (int i = 0; i < n - 1; i++)
  {
    cin >> s2;
    for(int j=0; j<s2.length(); j++){
      if(s1[j]!=s2[j]){
        s1[j]='?';
      }
    }
  }

  cout<<s1;
}