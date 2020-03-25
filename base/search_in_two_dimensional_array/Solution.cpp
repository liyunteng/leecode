// Solution.cpp - Solution

// Date   : 2020/03/26

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // begin from right/top
    // 时间复杂度O(width+height) 空间复杂度O(1)
    bool Find(int target, vector<vector<int>> array) {
        int width = array[0].size();
        int height = array.size();
        if (width == 0 || height == 0)
            return false;
        int i = 0, j = width-1;
        while (i < height-1 && j >= 0) {
            if (array[i][j] > target) {
                j--;
            } else if (array[i][j] < target) {
                i++;
            } else {
                cout << "(" << i << ", " << j << ")" << endl;
                return true;
            }
        }
        return false;
    }

    // 时间复杂度O(n^2) 空间复杂度O(1)
    bool Find_dumb(int  target, vector<vector<int>> array) {
        int width = array[0].size();
        int height = array.size();
        if (width == 0 || height == 0)
            return false;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (array[i][j] == target) {
                    cout << "(" << i << ", " << j << ")" << endl;
                    return true;
                } else if (array[i][j] > target) {
                    break;
                }
            }
        }
        return false;
    }
};

int main(void)
{
    vector<vector<int>> array = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    int target = 15;
    Solution s;
    if (s.Find(target, array)) {
        std::cout << "found" << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
    return 0;
}
