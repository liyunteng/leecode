/*
 * anser.c - anser
 *
 * Date   : 2020/03/25
 */
#include <iostream>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false

    // 时间复杂度O(N) 空间复杂度O(1)
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length <= 0)
            return false;

        for (int i = 0; i < length; ++i) {
            while (numbers[i] != i) {
                int v = numbers[i];
                if (v == numbers[v]) {
                    duplication[0] = v;
                    return true;
                }
                numbers[i] = numbers[v];
                numbers[v] = v;
            }
        }
        return false;
    }

    // sort
    // 时间复杂度O(nlogn) 空间复杂度O(1)
    bool duplicate_sort(int numbers[], int length, int *duplication) {
        if (numbers == nullptr || length <= 0)
            return false;

        std::sort(numbers, numbers+length);
        for (int i = 0; i < length - 1; ++i) {
            if (numbers[i] == numbers[i+1]) {
                duplication[0] = numbers[i];
                return true;
            }
        }
        return false;
    }

    // hash
    // 时间复杂度O(n) 空间复杂度O(n)
    bool duplicate_hash(int numbers[], int length, int *duplication) {
        std::unordered_set<int> s;
        for (int i = 0; i < length; ++i) {
            if (s.find(numbers[i]) != s.end()) {
                duplication[0] = numbers[i];
                return true;
            } else {
                s.insert(numbers[i]);
            }
        }
        return false;
    }
};


int main(void)
{
    int a[] = {2, 3, 1, 0, 2, 5};
    // int a[] = {2, 3, 1, 0, 4, 9, 7, 8, 6, 5};
    int dup;
    Solution s;
    bool r = s.duplicate_hash(a, sizeof(a)/sizeof(a[0]), &dup);
    if (r)
        std::cout << dup << std::endl;
    else
        std::cout << "no duplication" << std::endl;
    return 0;
}
