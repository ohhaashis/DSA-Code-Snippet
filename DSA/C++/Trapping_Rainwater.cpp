#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prev(n), next(n), mini(n);

        // Fill prev array
        prev[0] = height[0];
        for (int i = 1; i < n; i++) {
            prev[i] = max(prev[i - 1], height[i]);
        }

        // Fill next array
        next[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            next[i] = max(next[i + 1], height[i]);
        }

        // Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            int minHeight = min(prev[i], next[i]);
            if (minHeight > height[i]) {
                water += minHeight - height[i];
            }
        }

        return water;
    }
};