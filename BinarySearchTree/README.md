
## C++ Library for Binary Search Trees

You may find nearly all possible functions used to explore, build, reverse and check Binary Search Trees with a special 
focus on some of the tree printing techniques using recursivity and a few STL features.

An example of a customized buffer-based printed tree:

```

10 : root
|`--58 : first right child
|  |`--951
|  |  |`--2033
|  |  |   `--3030
|  |  |   `--1029
|  |  |      `--1030
|  |  |      `--1000
|  |   `--75
|  |     |`--98
|  |     |  |`--775
|  |     |  |   `--351
|  |     |   `--77
|  |     |      `--82
|  |     |         `--90
|  |      `--58
|  |         `--73
|   `--25
|     |`--35
|     |   `--43
|     |   `--32
|      `--23
 `--7 : first left child
    `--9
    `--3
       `--4
       `--2
          `--1

```
Here's the output after balancing the previous tree ( transforming it into AVL tree) :
```
58
|`--351
|  |`--1029
|  |  |`--2033
|  |  |   `--3030
|  |  |   `--1030
|  |   `--951
|  |      `--1000
|  |      `--775
|   `--77
|     |`--90
|     |   `--98
|     |   `--82
|      `--73
|         `--75
 `--10
   |`--32
   |  |`--43
   |  |   `--58
   |  |   `--35
   |   `--23
   |      `--25
    `--3
      |`--7
      |   `--9
      |   `--4
       `--1
          `--2
```
