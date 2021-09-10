# File-Structure-Project

Movie is something for which everyone has passion these days. But the major problem is that it becomes very tough to maintain such old movie records and retrieve such records, so to overcome this problem we introduce Movie Management System.
The Movie management system is a stand-alone application. It provides a user-friendly, interactive Menu Driven Interface (MDI).All data is stored in files for persistence. The application uses two files: a secondary index file, to store the primary index and a Data file, to store records pertaining to the Movie details, its routes and complete information regarding movie’s name and other details.</br>

# Introduction to File Structure

A file structure is a combination of representations for data in files and of operations for accessing the data. A file structure allows applications to read, write and modify data. It might also support finding the data that matches some search criteria or reading through the data in some particular order. An improvement in file structure design may make an application hundreds of times faster. The details of the representation of the data and the implementation of the operations determine the efficiency of the file structure for particular applications. A tremendous variety in the type needs of the file structure design important.

# INDEXING USED
An indexed file is a computer file with an index that allows easy random access to any record given its file key. The key must be such that it uniquely identifies a record. If more than
one index is present the other ones are called alternate indexes. The indexes are created with the file and maintained by the system.
Inverted File Indexing
Inverted file indices are probably the most common method used for indexing documents. Below figure shows the structure of an inverted file index. It consists first of a lexicon with one entry for every term that appears in any document. For each item in the lexicon the inverted file index has an inverted file entry (or posting list) that stores a list of pointers (also called postings) to all occurrences of the term in the main text. Thus to find the documents with a given term we need only look for the term in the lexicon and then grab its posting list. Boolean queries involving more than one term can be answered by taking the intersection (conjunction) or union (disjunction) of the corresponding posting lists. The total size of the posting lists can be as large as the document data itself. In fact, if the granularity of the posting lists is such that each pointer points to the exact location of the term in the document, then we can in effect recreate the original documents from the lexicon and posting lists (i.e., it contains the same information).
