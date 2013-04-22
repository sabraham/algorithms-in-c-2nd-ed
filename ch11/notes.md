# Priority Queues

queues, stacks

mapping between sorting algorithms and priority queues:
- insert everything to build a queue, and remove everything to get (reverse) sorted order

with unsorted list = selection sort
with sorted list = insertion sort

## heap

heap condition - key in each node should be larger (or equal to) keys of in its children (=> largest key is in the root)

heap - complete binary tree, represented a san array, in which every node satisfies the heap condition.

## algorithms on heaps

insert -- append to end of array, if key is greater than parent, exchange, recur
replace -- replace root node, swap with children if heap cond violated, recur
remove largest -- remove last element, decrement, replace largest element with just removed last element

all operations above (insert, remove, replace), delete, change require < 2 log N comparisons on a heap of N elements

nb - join not detailed above

## heapsort

sort n elements in n log n, but inner loop longer than that of quicksort, so ~twice as slow as quicksort on average

alg - add the n elements to the heap, then remove the top element n times; can be done in place

## indirect heaps

use a pointer array to keep track of array of records and sort pointer array~

## advanced implementations

heap condition too strong to allow efficient implementation of `join` operator -- ie, log implementation. advanced data structures designed to resolve this all weaken the heap or balance condition
