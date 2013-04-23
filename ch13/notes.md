# external sorting

external methods - involve a large amount of processing external to the cpu

## sort-merge

first pass through file, sort blocks that fit in memory, then merge sorted blocks by making several passes over file

strive to reduce number of passes through file and reduce cost of a single pass to be as close to a cost of a copy

most of cost of external sorting method is IO => can get rough measure of cost by counting number of passes over all data

## balanced multiway merging

e.g., if can store only 3 records in memory, sort every 3 records, and put sorted 3-tuples on 3 tapes, then merge the first 3-tuple of teach tape, and put this sorted 9 tuple on a separate tape. repeat for all 3-tuples. recur on the 9 tuples

## replacement selection

To do a P-way merge, fill a priority queue of size P with the smallest element from each of the P inputs, then replace the head of the heap with next element in the sorted queue of the popped head

not so useful for doing sort in the P-way merge, the diff between log P and P is not typically large, as we are intereted in small P

that said, replacement selection is good for producing the initially sorted sorted runs. build heap of size P, replace head, if replacement is bigger than popped head, mark replacement and treated as if larger than other nodes, and continue replacing head with and treating new nodes similarly, until head is marked node. now popped head goes on new tape. recur.

for random keys, runs produced by replacement selection are ~twice size of heap used.

=> reason to do this is to save one merging pass -- rather than starting with runs size of internal memory, we can start with runs ~twice the size of internal memory. also, if there is some order, e.g., keys are no more than M away from each other, using a priority queue of size M gives a sorted output in one pass

## polyphase merging

for p tapes, stagger num of runs on p-1 tapes, no runs on last tape. merge p-1 tapes onto last tape, until some tape out of memory, recur

advantage is to minimize copying or number of tape units