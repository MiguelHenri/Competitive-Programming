#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>

vll v; vll sum; int n;

double calculate_mean(int guess, int k){
    if (k == 0)
        return v[guess];
    double s;
    s = (sum[guess+1] - sum[guess-k])+(sum[n] - sum[n-k]); 
    return s/(2*k+1);
}

int main()
{
    /*reading input*/
    cin >> n;

    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    /*sorting array*/
    sort(v.begin(), v.end());

    /*sum vector*/
    sum.push_back(0);
    for(int i=0; i<n; i++){
        sum.push_back(sum.back() + v[i]);
    }

    double ans = -1, mean = 0, cmean = 0;
    int rk, rmedian;

    for(int median=0; median<n; median++){
        // we guessing a median and adding k numbers to its left and k numbers from the end of the array
        // and then calculating the mean
        int range = min(median, n-median-1); //max k

        int left = 0, right = range, middle = (left+right)/2;

        /*binary search*/
        while(right > left){
            //middle is current k
            cmean = calculate_mean(median, middle);

            //should increase k?
            int k = middle+1;
            int a = v[n-k];
            int b = v[median-k];

            if(double(a+b)/2 <= cmean) // NO, decrease.
                right = max(middle, left);
            else // YES, increase. 
                left = min(middle+1, right);     

            middle = (left+right)/2;
        }

        //when left == right, found k
        mean = calculate_mean(median, right);

        if(mean - v[median] > ans){
            ans = mean - v[median];
            rmedian = median;
            rk = left;
        }
    }

    //ans
    cout << rk*2 + 1 << "\n";

    for(int i = 0; i < rk; i++){
        cout << v[n-1-i] << " ";
    }
    
    for(int i = 0; i < rk+1; i++){
        cout << v[rmedian-i] << " ";
    }

}
