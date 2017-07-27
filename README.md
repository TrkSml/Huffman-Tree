# Huffman-Tree
A small project to create a Huffman-tree-based Encoding-Decoding based on a set of numbers and their frequencies.
Make command to build the executable program within the project directory:

```
user@user:path/to/directory$ make

```

We managed to make the program accept at least two elements to as starting set to code :

Example:

```
user@user:path/to/directory$ ./HuffmanTree 1 7 7 8 9 6 2 2 2 22 2 22
```
would give the next output :


```
Coding : 

Value:      7 |   Huffman code: 000 
Value:      1 |   Huffman code: 001 
Value:      9 |   Huffman code: 010 
Value:      8 |   Huffman code: 011 
Value:      2 |   Huffman code: 10 
Value:     22 |   Huffman code: 110 
Value:      6 |   Huffman code: 111 


Decoding : 

Huffman code:      000 | Value:      7 
Huffman code:      001 | Value:      1 
Huffman code:      010 | Value:      9 
Huffman code:      011 | Value:      8 
Huffman code:       10 | Value:      2 
Huffman code:      110 | Value:     22 
Huffman code:      111 | Value:      6 
```

