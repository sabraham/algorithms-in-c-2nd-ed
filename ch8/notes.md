# sorting
## selection sort
for (head = 0; head < n; ++head)
  exchange smallest element with index > head.

~n^2/2 comparisons (= n(n-1)/2), but guaranteed to move each item only once!
~n exchanges
=> excellent for sorting large files that have small keys (linear in amount of data)

## insertion sort
for (head = 0; head < n; ++head)
  insert head element in sorted elements 0 .. head-1

~n^2/4 comparisons
~n^2/8 exchanges, 2x in worst case
  
linear for ''almost sorted'' files. good for cases of few inversions
eg, have sorted array of ints, add some new ints to end, call sort
eg, array elements are off by a certain position, ie need to shift down..

## bubble sort
pass over array, exchanging adjacent elements. terminate when no exchanges on
some pass.

~n^2/2 comparisons
~n^2/2 exchanges

## Sorting Files with Large Records
Can arrange things so any sorting method uses N exchanges of full records =>
a[] consists of records => p[] is index array, p[i] = i initially. compare a[p[i]] instead of a[i], and exchange p[i] instead of a[i] => ie, sort index array

## shellsort
h-sorted - taking every hth element yields a sorted array
shellsort - h-sort array for h=h1,h2,...,1 using insertion sort/exchanges

## distribution counting

for sorting records with keys known to be between 0 and M-1, some M

iterate over array, and increment counter array
counter array => distribution array by count[j] = count[j-1] + count[j]
construct sorted array: iterate over array again: b[count[a[i]]--] = a[i]
copy b to a