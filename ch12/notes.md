# Mergesort

divide-and-conquer sorting cases:
1- divide array into 2, sort, result is sorted -- quicksort
2- divide array into 2, sort, merge, result is sorted -- mergesort

n log n in worst case -- disadvantage is extra space = prop to n

inner loop btwn quicksort and heapsort

mergesort can be implemented so that it accesses data sequentially -- (so perfect e.g. sorting a linked list)

## merging

two-way merging -- combine two sorted files into one sorted file
multiway merging -- combine more than two sorted files into one sorted file

# list mergesort

get middle of linked list by having 2 points, both at the beginning, increment both, but one twice, when the latter hits the end, the former will be at the middle

# bottom-up mergesort

non-recursive implementation: every 2 elements in the first pass, every 4 elements, ...

# performance

~nlogn comparisons; extra space ~n; stable; insensitive to inital order of input

# optimization

can avoid sentinals by reversing order of right array.

biggests inefficiency is copy a->b; like radix sort, move can be avoided by having two copies of code, one where we merge a->b and then later b->a