[Day 1](https://adventofcode.com/2023/day/1)

# Part 1 Solution

Simple solution of iterating through a file line by line and keeping track of first and last digits found in line and adding it to the sum.
(An improvement would be to use 2 pointers and have them both move inwards until both are digits)

Answer: `54990`

# Part 2 Solution

Now that numbers in their word form is added to the mix I defined a Trie structure which is the most efficient for storing and searching for words with common prefixes. This way I can also store the numerical value of each word at its leaf node.

Answer: `54473`
