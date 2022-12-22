#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

int main()
{
    int t;
    cin >> t;

    for(int i=1; i<t+1; i++){ //cases
        vi even, odd;
        int temp = 0;
        int n;
        cin >> n;
        //filling two vectors for odd and even numbers
        for(int j=0; j<n; j++){
            cin >> temp;
            if(j%2 == 0) //even
                even.push_back(temp);
            else
                odd.push_back(temp);
        }
        //sorting vectors
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        //building new sorted vector
        vi v;
        for(int j=0; j<n; j++){
            if(j%2 == 0){
                v.push_back(even[0]);
                even.erase(even.begin());
            }
            else{
                v.push_back(odd[0]);
                odd.erase(odd.begin());
            }
        }

        //checking if trouble sort does not sort correctly
        int flag = -1;
        for(int j=0; j<(n-1); j++){
            if(v[j] > v[j+1]){
                flag = j;
                break;
            }
        }

        if(flag == -1)
            cout << "Case #" << i << ": OK\n";
        else 
            cout << "Case #" << i << ": " << flag << "\n";
    }

	return 0;
}
