# hash-table-problem

## The Problem

A Binary Tree which leaves all reside at equal depth will be given. This tree will be denoted as Σ and its height as H. The nunmber of nodes of Σ is n = 2H - 1. These nodes have an assigned color, white or black. The following is an example:


The problem to solve consists of finding where in Σ occurances of another Binary Tree are located. We will call this other tree t, of height h (1 <= h <= H). An occurance of t in Σ is defined as some subtree of Σ, which nodes coincide in color with t's nodes. The following is an example:

We denote the occurances of a subtree t in Σ by the ID of the node of Σ which coincides with the root of t. In the previous example, the ocurrances of t in Σ would correspond to the indexes 1 and 5. The given subtree t does not necessarily belong to Σ. 

## Solution

The implemented solution to this problem consists of a hash table in order to search for the subrees in Σ. Every subree (of at least three nodes) is hashed and inserted into the table which uses open addressing to handle collisions. After hashing all subtrees, the occurances of a given tree t can be found by searching the hash table. The hash table is defined in the table.c file, the hashing procedures in the hash.c file and the tree procedures in the tree.c file (including the searching for tree in the hash table). 

## Input

The input must be structured as follows:
* A line which contains a description of Σ. This corresponds to a number n, which represents the number of nodes of Σ, followed by the colors of the n nodes which will be ordered by index (left to right). White = 0, Black = 1.
* A with a number N which represents the amoung of subtrees to search in Σ
* N lines, each one for a tree t to search in Σ. Each of these lines follows the same structure of Σ given in the first bullet.

For example, the input for the Σ and t trees given in the previous example would be:
15 0 1 1 1 0 0 1 0 1 1 1 1 0 0 1
1
3 0 1 1

## Output

The output consists of N lines, each one contaning the ID of each occurance of t in the Σ given by input, in ascending order. For example, for the previously given input, the output would be:
1 5

## Execution

The execution depends on a binary called remember which will be compiled by running 
```
make
```
The binary can be executed by running
```
./remember input ouput
```
* input corresponds to the .txt file which contains the previously mentioned input format
* output corresponds to the .txt file in which the output will be printed

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.











