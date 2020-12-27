# subtree-occurrence-finder

## The Problem

A Binary Tree which leafs all reside at equal depth will be given. This tree will be denoted as `Σ` and its height as `H`. The number of nodes of `Σ` is `n = 2H - 1`. These nodes have an assigned color, white or black. The following is an example:

<p align="center">
  <img width="60%" src=https://github.com/juansjimenez/hash-table-problem/blob/main/img/tree_example.PNG>
</p> </br>
 <p align="center"> Σ with H = 4. The nodes are numbered from 1 to n, which corresponds to the node's ID </p> </br>

The problem consists of finding the location of occurrences of a Binary Tree `t`, of height `h` (1 ≤ h ≤ H), in `Σ`. An occurrence of `t` in `Σ` is defined as some subtree of `Σ` which nodes coincide in color with `t`'s nodes. The following is an example:

<p align="center">
  <img width="60%" src=https://github.com/juansjimenez/hash-table-problem/blob/main/img/input_tree_example.PNG>
</p>
 <p align="center"> On the left, the subtree t to search, with h = 2. On the right, its occurences in Σ </p>



We denote the occurrences of a subtree `t` in `Σ` by the ID of the node of `Σ` which coincides with the root of `t`. In the previous example, the occurrences of `t` in `Σ` correspond to the indexes 1 and 5. Note that a given subtree `t` doesn't necessarily belong to `Σ`. 

## Solution

The implemented solution to this problem consists of a Hash Table in order to search for the subrees in `Σ`. Every subtree (of at least three nodes) is hashed and inserted into the table which uses Open Addressing to handle collisions. After hashing all subtrees, the occurrences of a given tree `t` can be found by searching the table. Said table is implemented in the `table.c` file, the hashing procedures in the `hash.c` file and the tree procedures in the `tree.c` file (including searching for a tree in the table). 

## Input

The input must be structured as follows:
* A line which contains a description of `Σ`. This corresponds to a number `n`, which represents the number of nodes of `Σ`, followed by the colors of the `n` nodes which will be ordered by index. White = 0, Black = 1.
* A number `N` which represents the amount of subtrees to search in `Σ`.
* `N` lines, each one corresponding to a tree `t` to search in `Σ`. These lines follow the same structure of `Σ` given in the first bullet.

For example, the input for the `Σ` and `t` trees given in the previous example would be:  <br />
15 0 1 1 1 0 0 1 0 1 1 1 1 0 0 1 <br />
1  <br />
3 0 1 1 

## Output

The output consists of `N` lines, each one contaning the ID of each occurrence of `t` in the `Σ` tree given by input, in ascending order. For example, for the previously given input, the output would be:  <br />
1 5

## Execution

The execution depends on a binary called `remember` which needs to be compiled by running 
```
make
```
The binary can be then executed by running
```
./remember input ouput
```
* `input` corresponds to the `.txt` file which contains the previously mentioned input format.
* `output` corresponds to the `.txt` file in which the output will be printed.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.











