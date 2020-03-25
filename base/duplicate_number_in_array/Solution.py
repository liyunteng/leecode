#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Solution.py - Solution

# Date   : 2020/03/26
import collections

class Solution:

    def duplicate(self, numbers, duplication):
        if (not numbers) or len(numbers) <= 1:
            return False

        for i in range(len(numbers)):
            while i != numbers[i]:
                if numbers[i] == numbers[numbers[i]]:
                    duplication[0] = numbers[i]
                    return True
                temp = numbers[i]
                numbers[i] = numbers[temp]
                numbers[temp] = temp
        return False

    def duplicate_sort(self, numbers, duplication):
        if (not numbers) or len(numbers) <= 1:
            return False

        numbers.sort()
        for i in range(0, len(numbers)-1):
            if numbers[i] == numbers[i+1]:
                duplication[-1] = numbers[i]
                return True

        return False

    def duplicate_hash(self, numbers, duplication):
        if (not numbers) or len(numbers) <= 1:
            return False

        d = {}
        for i in numbers:
            if i in d and d[i] == 1:
                duplication[0] = i
                return True
            d[i] = 1
        return False

    def duplicate_collection(self, numbers, duplication):
        if len(numbers) == len(set(numbers)):
            return False
        duplication[0] = collections.Counter(numbers).most_common(1)[0][0]
        return True



def main():
    numbers = [2, 3, 1, 0, 2, 5]
    # numbers = [2, 3, 1, 0, 4, 9, 7, 8, 6, 5]
    s = Solution()
    duplication = [-1]
    if s.duplicate_collection(numbers, duplication):
        print(duplication[0])
    else:
        print('no duplication')

if __name__ == '__main__':
    main()
