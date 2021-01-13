# Find MIN Height of B+ Trees

## 1) Prepare Assumption
- 10 million records  **[RECORD COUNT]**
- Each record is 256 bytes **[RECORD SIZE]**
- Each record has a 32-bytes index field **[INDEX FIELD]**
- Our system's disc block size 8KB **[DISCK BLOCK SIZE]**
- Our system is 32-bits, so the pointers are 4-bytes **[POINTER SIZE]**

## 2) Find Data Count For Each Data Node

**Node size = data count * record size**

	8KB = L * 256 bytes
	8192 bytes = L x * 256 bytes
	L = 32

- A data node can store max 32, min 32/2 = 16 data.

## 3) Find Links and Index Fields For Each Index Node 

**Node Size = (M - 1) * index + M * pointers** 
	8192 bytes = (M - 1) * 32  bytes + M * 4 bytes;
	8192 = 36M - 32
	M = 228
	
- An index node(inner node) can have up to 228 links and 227 index fields at max.
- An index node(inner node) can have up to 114 links and 223 index fields at min.

## 4) Find Count of Data Nodes in B+ Trees
**record count = data count in a data node * data node count**
	10 million = 32 * data node count
	data node count =  312500

- To store 10 million records we need to 312500 FULL data nodes.

## 5) Find Count of Index Nodes in B+ Trees

**data node count = link count in an index node * index node count**
	312500 = 228 * index node count
	index node count = 1370

- To store 312500 data nodes we need to 1370  FULL index nodes.

## 6) If exist, Find Upper Index Node

**1370 > 228, This  means we need to have upper index nodes.**
	1370 = 228 * upper index node
	upper index node = 6

## 7) Result

 - [ ] Root for 6 nodes
 - [3] 
 - [ ] 6 upper index nodes are required for 1370 index nodes
 - [2] 
 - [ ]  1370 index nodes are required for 312500 data nodes
 - [1] 							
 - [ ]  312500 data nodes are required for 10 million records

MIN HEIGHT = 3
	
 
