# radix sorting
radix sorts - methods that do not just compare keys -- process and compare pieces of keys

treat keys as numbers represented in a base-M system, for diff values of M (the radix), and work with individual digits of the number

# bits
if size of keys is small, use distribution counting -- ie, if keys are b bits and and we can store table of 2^b, then use distribution counting  (can sort N keys between 0 and M-1 in linear time wiht table size M)

radix exchange sort - sort keys by examining bits left to right
straight radix sort - examines bits in keys from right to left

# radix exchange sort
basically quicksort... using 2^b as partitioning element, with b = pos of rightmost bit, then decrementing with each pass

# straight radix sort
left to right bit sort, sort by partitioning ith column into 0 and 1 => works b.c. 1bit partitioning is stable

can use distribution-counting to conduct the partitioning with M=2 for straight 1 column partitioning. better => use m columns, so M=2^m (so use as large as m as you can, subject to having to use a table of size 2^m) => straight radix sort is a generalization of distribution-counting sort

# performance characteristics of radix sorts
both radix sorts ~Nb for N records with b-bit keys, which is around NlogN if the numbers are all different, as then b >= logN, but also both methods use many fewer than Nb, b.c. left->right stops as soon as you hit a difference, and right->left can process many bits at once

radix-exchange sort uses on avg NlogN bit comparisons

both radix sorts use less than Nb bit comparisons => radix sorts are linear in terms of bits of input (nb- no bit is examined more than once)

straight radix sort can sort in b/m passes, using 2^m space for counters (and buffer to rearrange file) =>  we can get linear sort(!)

# a linear sort
e.g., above, use m ~ b/4, so the radix sort is done in 4 distribution-counting passes. each distribution-count pass is linear => entire sort is linear

good hack for sorting large files with keys that are random bits (uniformly dist.):
right->left sort (straight radix sort) the leading b/2 bits. this will give an almost sorted list. then perform insertion sort. using m ~ b/4, this will be 2 distribution passes, and we likely have few exchanges to make in the insertion sort (am taking sedgewick's word on this...)

main disadvantage of this is the req of needing an extra array of same size as array being sorted. can eliminate using a linked-list, but still need space ~N (for links)

WHY THIS IS NOT THE MAGIC SORT TO RULE THEM ALL
1- efficiency depends on keys being random bits, randomly ordered
 => else severe performance degradation likely
2- requires extra space ~size of array being sorted
3- ''inner loop'' of program contains lots of instructions so even though linear, won't be much faster than quicksort, except for large files (in which case probably can't store in extra array)

''choice between quicksort and radix sort is a difficult one ... likely to depend not only on features of the application, such as key, record, and file size, but also on the features of the programming and machine environment that relate to the efficiency of access and use of the individual bits ... such tradeoffs need to be studied by an expert, and this type of study is likely to be worthwhile only for serious sorting applications.'''