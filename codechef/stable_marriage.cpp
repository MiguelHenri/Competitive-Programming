#include <bits/stdc++.h>
#include <vector>
using namespace std;

//https://www.codechef.com/problems/STABLEMP

#define ll long long
#define vi vector<int>
#define vll vector<long long>

bool remains_single(int *arr, int n){
    if(find(arr, arr + n, -1) == arr + n){ //no -1, no single person
        return false;
    }
    return true; 
}

void answer(int t){
    int n; cin >> n;

    vi men[n];
    vi women[n];

    int temp;
    //reading women
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<n; j++){
            cin >> temp;
            women[i].push_back(temp);
        }
        reverse(women[i].begin(), women[i].end());
    }
    //reading men
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<n; j++){
            cin >> temp;
            men[i].push_back(temp);
        }
        reverse(men[i].begin(), men[i].end());
    }

    //solving
    int womenp[n], menp[n]; //stores current partners
    for(int i = 0; i < n; i++){
        womenp[i] = -1; 
        menp[i] = -1;
    }
    while(remains_single(womenp, n)){
        for(int i = 0; i < n; i++){
            if(menp[i] == -1){
                int pref = men[i].back() - 1;
                men[i].pop_back();
                if(womenp[pref] == -1){//woman pair also single
                    menp[i] = pref;
                    womenp[pref] = i; //matches
                }
                else{ //woman already has pair
                    //see if man is a better match
                    int current_man = womenp[pref];

                    int cman_rank = n - (find(women[pref].begin(), women[pref].end(), current_man+1) - women[pref].begin());
                    int iman_rank =  n - (find(women[pref].begin(), women[pref].end(), i+1) - women[pref].begin());

                    if(cman_rank > iman_rank){ //lower rank is better
                        menp[i] = pref;
                        womenp[pref] = i; //matches
                        menp[current_man] = -1; //old pair turns single
                    }
                }
            }
        }
    }

    //print solution
    for(int i=0; i<n; i++){
        cout << i+1 << " " << menp[i]+1 << "\n";
    }

}

int main()
{
    int tests; cin >> tests;

    for(int i=1; i<=tests; i++){
        answer(i);
    }
}
