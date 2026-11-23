# OOP in C: Binary Search Tree with an Integrated Linked List

A learning project that implements a Binary Search Tree with an added linked list structure whereby non-recursive traversal of the tree is performed.

## Features

* An emulation of OOP in C via structs, function pointers and an iterator.
* Integrated linked list: each node belongs to the tree and the singly linked list at the same time.
* 3 tree traversals:
    * Pre-order (`pre_order_dump`): showcases the tree structure with vertical bars.
    * In-order (`in_order_dump`): recursively outputs nodes in a sorted manner.
    * Iterator-based traversal: non-recursively outputs nodes in a sorted manner.
* `get` method for searching nodes by key which returns the node's value or -1 if the key is not found.    
* 2 modes: 
    * Static demo with a pre-filled dataset.
    * Interactive version for user input.
    
## Build and Run 

To compile the static demo:
```cmd
gcc -std=c11 tree_list.c tree_list_main.c -o demo
```

To compile the interactive version:
```cmd
gcc -std=c11 tree_list.c tree_list_main_interactive.c -o interactive
```

Note that tree nodes have keys of type char* and values of type int (e.g., Radiohead 9).
When entering keys and values, separate them by a space (e.g., Cranberries 11).
For multiple-word keys use underscores (e.g., Thom_Yorke).
Enter exit 0 to quit.

## Attribution

This project is an educational exercise based on the **"C Programming for Everybody"** course.

* **Title:** C Programming for Everybody (CC4E)
* **Author:** Dr. Charles Russell Severance (Dr. Chuck), University of Michigan
* **Source:** [https://www.cc4e.com/](https://www.cc4e.com/) (Course taken via Coursera)
* **Licence:** The course materials and original code snippets are licensed under [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

**Changes made:** this repository is not entirely original work.
* The core logic of the Binary Search Tree and the Linked List (specifically the `put` method) was **assembled and adapted from code fragments presented in the course's lecture slides**.
* The tree and iterator destructors, the in-order traversal (`in_order_dump`) and the interactive user input (`tree_list_main_interactive.c`) were **implemented by me**.

## Licence

The original code in this repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
