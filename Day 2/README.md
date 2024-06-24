[Day 2](https://adventofcode.com/2023/day/2)

# Part 1 Solution

When a digit is followed by a space, store the digit and the character that comes after the space as the dice color (ex. r, b, g)
Also check the digit before the last digit in-case it is a 2 digit number (kinda bad)

Answer: `2528`

# Part 2 Solution

Same as part 1 but keep track of highest dice count found and find their power at the end of the loop and add it to sum.

Answer: `67363`
