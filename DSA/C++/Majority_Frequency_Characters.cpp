#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string majorityFrequencyGroup(string s) {
         unordered_map<char, int> freq;
    unordered_map<int, vector<char>> freqGroups;

    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }
int count =0;

    // Group characters by their frequency
    for (auto& [ch, count] : freq) {
        freqGroups[count].push_back(ch);
    }

    // Find the majority frequency group
    int maxGroupSize = 0;
    int chosenFreq = 0;
    for (auto& [count, chars] : freqGroups) {
        int groupSize = chars.size();
        if (groupSize > maxGroupSize || (groupSize == maxGroupSize && count > chosenFreq)) {
            maxGroupSize = groupSize;
            chosenFreq = count;
        }
    }

    // Build result string
    string result;
    for (char c : freqGroups[chosenFreq]) {
        result += c;
    }

    return result;
    }
};



