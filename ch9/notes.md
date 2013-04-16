# quicksort
(nlogn), fragile, in-place

## the basic algorithm
divide-and-conquer-- partition array into 2, sort each separately
parititon function must guarantee: (1) a[i] (ret of partition) is in final place, for some i; (2) all elements a[l] ... a[i-1] <= a[i]; (3) all elements a[i+1] ... a[r] are >= a[i]

## cool optimizaiton -- median of three partitioning
take 3 elements, take median as the partitioning element
if use first last and middle, then can sort over l+1 to r-1, so can avoid sentinal values too
this + nonrecursive implementation knocks 25-30% of recursive quicksort time!

## selection
selection -- find the kth smallest of a set of numbers
for small k, use selection sort -- time ~Nk
for larger k, see ch11 for ~Nlogk
general method: use quick sort, count elements above/below partition element, discard unnecessary bit, rinse repeat

quicksort based selection is linear-time on average. worst case ~quicksort

