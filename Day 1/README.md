[Day 1](https://adventofcode.com/2023/day/1)

# Part 1

## Question
On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

`
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
`
In this example, the calibration values of these four lines are `12, 38, 15, and 77.` Adding these together produces `142`.

Consider your entire calibration document. What is the sum of all of the calibration values?

## Solution
Simple solution of iterating through a file line by line and keeping track of first and last digits found in line and adding it to the sum.

Answer: `54990`

# Part 2

## Question
Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: `one, two, three, four, five, six, seven, eight, and nine` also count as valid "digits".

Equipped with this new information, you now need to find the real first and last digit on each line. For example:

`two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen`

In this example, the calibration values are `29, 83, 13, 24, 42, 14, and 76.` Adding these together produces `281`.

What is the sum of all of the calibration values?

## Solution
Now that numbers in their word form is added to the mix I defined a Trie structure which is the most efficient for storing and searching for words with common prefixes. This way I can also store the numerical value of each word at its leaf node.

Answer: `54473`
