## HASING

### 1-What Is The Hasing ?

Applying **hash function** to the key and storing or accessing data using that index will be called as **HASHING**

### 2-When We Use Hashing?

If you have some data which does NOT requires database but requires fast access time you use HASHING!

### 3-What Is The Hash Function?

if you have some student IDs, you can hash with using mod operator. Like that **ID % TABLE_SIZE**. In this formula, 

(% TABLE_SIZE) is **HASH FUNCTION**

### 4-Hashing In Other Programming Languages

Hash function is used to **MAP** key to an index.
Another common use name for hashing.

 - **In C++ there are “map” classes for hashing.**
 -  **In Python dictionary data type uses hashing. So, it is a bult-in part of Python.**
 - **In Java, there is Hashtable class.**

### 5-What Is The Collision In Hashing Literature?

When you use hash function (mod operator) for hashing, you can came across same results. Like that:

3007 % 20K = 3007

23007 % 20K = 3007

43007 % 20K = 3007

In Brief, The problem is the keys yielding the same results!

### 6-Solutions For  The Collision ?

- **Linear Probing**

If there is a collision occurs, you proceed to the next item or next slot. You repeat this process until you find an empty index.

 - **Quadratic Probing**

If there is a collision occurs, in the first attempt you check the next slot, in the second attempt you check the fourth slot and so on.

- **Rehashing**

After each insert, the chance/probability of collision increases. So, if you create a new table by doubling size of it after half of the table is full, the probability of collision decreases. This is rehashing!

- **Double Hashing**

You will have two hash functions. Firstly, you apply first function. After that if there is a collision, you apply second function. Still there is a collision you apply linear or quadratic probing.

### 7-Can You Suggest Another Solution For Hash Table Implementation Which Has NOT Got Space Limitation?

Answer is: **Separate Chaining Hash Table**

This is Mixture of arrays and linked list. Each linked list will be considired chain. Those chains are seperate each other.

If you have two different items want to go same location, you create linked list and add those items in that list.






