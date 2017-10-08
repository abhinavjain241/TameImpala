#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

typedef unsigned int cType;
typedef unsigned int pType;

// int knapSack(int W, vector<uint> wt, vector<uint> val, int n) {
//    int i, w;
//    unsigned int K[n+1][W+1];
//    // Build table K[][] in bottom up manner
//    for (i = 0; i <= n; i++) {
//        for (w = 0; w <= W; w++) {
//            if (i==0 || w==0)
//                K[i][w] = 0;
//            else if (wt[i-1] <= w)
//                  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
//            else
//                  K[i][w] = K[i-1][w];
//        }
//    }
//    return K[n][W];
// }

// int KnapSack(vector<uint> val, vector<uint> wt, int n, int W) {
//     // matrix to store final result
//     unsigned int mat[2][W+1];
//     memset(mat, 0, sizeof(mat));
//     // iterate through all items
//     int i = 0;
//     while (i < n) {  // one by one traverse each element
//         int j = 0; // traverse all wieghts j <= W
//         // if i is odd that mean till now we have odd
//         // number of elements so we store result in 1th
//         // indexed row
//         if (i%2!=0) {
//             while (++j <= W) { // check for each value 
//                 if (wt[i] <= j) // include element
//                     mat[1][j] = max(val[i] + mat[0][j-wt[i]], mat[0][j]);
//                 else           // exclude element
//                     mat[1][j] = mat[0][j];
//             }
//         }
//         // if i is even that mean till now we have even number
//         // of elements so we store result in 0th indexed row
//         else {
//             while(++j <= W) {
//                 if (wt[i] <= j)
//                     mat[0][j] = max(val[i] + mat[1][j-wt[i]], mat[1][j]);
//                 else
//                     mat[0][j] = mat[1][j];
//             }
//         }
//         i++;
//     }
//     // Return mat[0][W] if n is odd, else mat[1][W]
//     return (n%2 != 0)? mat[0][W] : mat[1][W];
// }

// bool cmp(const pair<cType,pType> &a, const pair<cType,pType> &b) {
//     double r1 = (double)a.second / a.first;
//     double r2 = (double)b.second / b.first;
//     return r1 > r2;
// }

// bool cmp(struct Item a, struct Item b) {
//     double r1 = (double)a.value / a.weight;
//     double r2 = (double)b.value / b.weight;
//     return r1 > r2;
// }

// pType fractionalKnapsack(int W, vector<pair<cType, pType> > arr, int n) {
//     //    sorting Item on basis of ration
//     sort(arr.begin(), arr.end(), cmp);
//     //    Uncomment to see new order of Items with their ratio
    
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].second << "  " << arr[i].first << " : "
//              << ((double)arr[i].second / arr[i].first) << endl;
//     }
    
//     cType curWeight = 0;  // Current weight in knapsack
//     pType finalvalue = 0; // Result (value in Knapsack)
//     // Looping through all Items
//     for (int i = 0; i < n; i++) {
//         // If adding Item won't overflow, add it completely
//         if (curWeight + arr[i].first <= W) {
//             curWeight += arr[i].first;
//             finalvalue += arr[i].second;
//         }
//         // If we can't add current Item, add fractional part of it
//         // else {
//         //     int remain = W - curWeight;
//         //     finalvalue += arr[i].value * ((double) remain / arr[i].weight);
//         //     break;
//         // }
//     }
//     // Returning final value
//     return finalvalue;
// }

int main(int argc, char const *argv[]) {
  unsigned int n, m, u, v, i, res = 0; //n - nodes, m - starting units
  cType t;
  pType p; 
  vector<pair<cType, pType> > exchange;
  vector<uint> cost, profit;
  cin >> n >> m;
  for(i = 0; i < n - 1; i++) {
    cin >> u >> v >> t >> p;
    // cost.push_back(t);
    // profit.push_back(p);
    exchange.push_back(make_pair(t, p));
  }
  // res = fractionalKnapsack(m, exchange, n - 1);
  // sort(exchange.begin(), exchange.end());
  // sort(exchange.begin(), exchange.end(), sortbysecdesc);
  // for(i = 0; i < n - 1; i++) {
  //   cout << exchange[i].first << " " << exchange[i].second << endl;
  // }
  i = 0;
  // while(m > 0 && i < exchange.size()) {
  //   if(m >= exchange[i].first) {
  //     m -= exchange[i].first;
  //     res += exchange[i].second;
  //   }
  //   i++;
  // }
  cout << res << endl;
  return 0;
}