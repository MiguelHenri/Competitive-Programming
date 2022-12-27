#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1731/problem/D
//time limit problem :(
//try to pre-process data using prefix sum

#define ll long long
#define vi vector<int>
#define vll vector<long long>

void solve(){
    //reading input
    int n, m; cin >> n >> m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    }

    //binary searching
    int L = 1; int R = min(n,m); int mid;

    while(R >= L){
        bool test = false;

        mid = (L+R)/2;

        int temp_arr[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] >= mid)
                    temp_arr[i][j] = 1;
                else
                    temp_arr[i][j] = 0;
            }
        }
        for(int i=0; i<n-mid+1; i++){
            if(test == true) break;
            for(int j=0; j<m-mid+1; j++){
                if(test == true) break;
                if(temp_arr[i][j] == 1){
                    int sum = 0;
                    for(int k=i; k<i+mid; k++){
                        int l;
                        for(l=j; l<j+mid; l++){
                            if(temp_arr[k][l] == 0)
                                break;
                            sum += temp_arr[k][l];
                        }
                    }
                    if(sum == mid*mid)
                        test = true;
                }
            }
        }
                 
        if(test == false)
            R = mid - 1;
        else
            L = mid + 1;
    }

    cout << R << "\n";
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
}