#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Solution.py - Solution

# Date   : 2020/03/26

class Solution:

    def Find(self, target, array):
        if len(array) == 0 or len(array[0]) == 0:
            return False

        l = 0
        r = len(array[0]) - 1
        while l < len(array) and r >= 0:
            if array[l][r] < target:
                l += 1
            elif array[l][r] > target:
                r -= 1
            else:
                print('(%d, %d)' % (l, r))
                return True
        return False


def main():
    array = [
        [1, 4, 7, 11, 15],
        [2, 5, 8, 12, 19],
        [3, 6, 9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30],
    ]
    s = Solution()
    target = 20
    if s.Find(target, array):
        print('found')
    else:
        print('not found')

if __name__ == '__main__':
    main()
