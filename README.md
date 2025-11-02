# MyVector
Implement my own version of a vector

> "If you know vector, you know half of C++."
> — Bjarne Stroustrup
Your Task

Implement your own version of a vector with the following methods:

    push_back – Adds an element to the back.
    at – Retrieves an element by index.
    getSize – Gets the size of the container.
    getCapacity – Gets the capacity of the container.
    shrinkToFit – Shrinks the capacity to equal the size of the container.
    pop_back – Removes the last element in the container. Will never be called on an empty container.

Requirements

    Do not worry about memory alignment or advanced optimizations.
    Do not use std::vector in your getcracked::vector implementation — we will detect cheating.
    Your vector's capacity must start at 1.
    The capacity should triple every time it is reached.

Evaluation

Test cases won't just check correctness — they will also evaluate:

    Efficiency
    Proper resizing
    No use of standard containers

Test Case Keys

When analyzing the test cases:
Symbol	Meaning
p	.push_back
a	.at
z	.getSize
c	.getCapacity
s	sizeof
b	pop_back
f	shrinkToFit
e	.push_back with a tracker object X number of times

Results are concatenated. For example:

z|c → 3|9|

Means:

    .getSize() → 3
    .getCapacity() → 9

Note: If you default construct new objects as you expand capacity, you will fail a test. Expanding capacity should not default construct new objects — that's not how vector works.

Use case 1 : 
getcracked::vector<double> v;
v.push_back(0);
v.getCapacity(); // 3


Use case 2 :
getcracked::vector<double> v;
v.at(0); // Throw
