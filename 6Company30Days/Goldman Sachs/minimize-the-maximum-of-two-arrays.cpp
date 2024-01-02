// We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.
// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

// Time = O(logn)
// Space = O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        // BINARY SEARCH 
        long long div1 = divisor1, div2 = divisor2, cnt1 = uniqueCnt1, cnt2 = uniqueCnt2;
        long long lcm = (div1*div2) / __gcd(div1, div2);
        long long total = cnt1 + cnt2;
        long long s=1 , e=1e15, ans = e;

        while(s <= e){
            long long mid = (s+e)/2;
            if(div1 == div2){
                // remaining integers(not divisible by div1/div2), can be filled in both arrays 
                long long c = mid - (mid/div1);
                if(c >= total){
                    // already fulfilled => now minimise ans
                    ans = mid;
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else{
                long long both = mid / lcm;  // no. of int divisible by both div1 , div2
                long long c1 = (mid / div1) - both;  // no. of int divisible by only div1 not div2
                long long c2 = (mid / div2) - both;  // no. of int divisible by only div2 not div1

                long long z1 = cnt1 , z2 = cnt2;
                long long availToBoth = mid - (c1 + c2 + both);  // no. of int that can be filled in either of the arrays

                // use c1 in array2 and c2 in array1 (stated as in problem)
                z1 -= min(z1, c2);  // array1 can take c2 integers
                z2 -= min(z2, c1);  // array2 can take c1 integers
                if(z1 + z2 <= availToBoth){
                    ans = mid;
                    e = mid-1;
                }
                else{
                    s = mid + 1;
                }
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}

