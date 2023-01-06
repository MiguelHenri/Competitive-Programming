#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1779/problem/A

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    //reading input
    int n; cin >> n;
    string s; cin >> s;

    //solve
    int rightmost_left = -1; int leftmost_right = 1000000;

    for(int i=0; i<s.length(); i++){
        if(s[i] == 'L' && i > rightmost_left)
            rightmost_left = i;
        if(s[i] == 'R' && leftmost_right == 1000000)
            leftmost_right = i;
    }

    //ans
    if(rightmost_left == -1 || leftmost_right == 1000000)
        cout << -1 << "\n";
    else if(rightmost_left > leftmost_right)
        cout << 0 << "\n";
    else if(leftmost_right - rightmost_left == 1)
        cout << leftmost_right << "\n";
    else
        cout << -1 << "\n";
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
}