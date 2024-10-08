#include<iostream>

using namespace std;

int main() {
  string s;
  int cnt=0;

  getline(cin, s);

  for(int i=0; i<s.length(); i++) {
    if(i==0&&s[i]!=' '){
      cnt++;
    }
    else if(s[i-1] == ' '){
      cnt++;
    }
  }

  cout<<cnt;
}